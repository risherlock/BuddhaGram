/*
 * SCServo.h
 * Series Control Servo for SC10
 * Created on: 2015.4.15
 * Author: Tony tan
 * Modified on: 2015.8.7
 * Modification author: Ilya Altukhov and Rishav
 */

#ifndef _SCSERVO_h_
#define _SCSERVO_h_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include "../arduino/Arduino.h"
#include "../arduino/SoftwareSerial.h"

#define		s8		char
#define		u8		unsigned char
#define		u16		unsigned short
#define		s16		short
#define		u32		unsigned long
#define		s32		long

class SCServo{
	public:
		SCServo();
		void init(long baud_rate);
		void end(void);
		int EnableTorque(byte ID, byte Enable, byte ReturnLevel=1);
		int WritePos(byte ID, int position, int velocity, byte ReturnLevel=1);
		int RegWritePos(byte ID, int position, int velocity, byte ReturnLevel=1);
		int ReadPos(byte ID);
		int ReadVoltage(byte ID);
		int ReadTemper(byte ID);
		void RegWriteAction();
		void SyncWritePos(byte ID[], byte IDN, int position, int velocity);
		int WriteID(byte oldID, byte newID, byte ReturnLevel=1);
		int WriteLimitAngle(byte ID, int MinAngel, int MaxAngle, byte ReturnLevel=1);
		int WriteLimitTroque(byte ID, int MaxTroque, byte ReturnLevel=1);
		int WritePunch(byte ID, int Punch, byte ReturnLevel=1);
		int WriteBaund(byte ID, byte Baund, byte ReturnLevel=1);
		int WriteDeadBand(byte ID, byte CWDB, byte CCWDB, byte ReturnLevel=1);
		int WritePID(byte ID, byte P, byte I, byte D, byte ReturnLevel=1);
		int WriteSpe(byte ID, int velocity, byte ReturnLevel=1);
		int LockEprom(byte ID, byte Enable, byte ReturnLevel=1);
		int WriteIMax(byte ID, int IMax, byte ReturnLevel=1);
		void RotateClockwise(void);
		void RotateCounterClockwise(void);
	private:
		int		ReadBuf(byte len, byte *buf=NULL);
		void	fflushRevBuf(void);
		void	Printf(byte reg);
		int     ReadSerial(void);
		SoftwareSerial 	_SCSserial;


		#define		startByte	0xFF
		#define		TIMEOUT		500//TIMEOUT 500ms

		#define		B_1M		0
		#define		B_0_5M		1
		#define		B_250K		2
		#define		B_128K		3
		#define		B_115200	4
		#define		B_76800		5
		#define		B_57600		6
		#define		B_38400		7
		#define 	RX_PIN		10
		#define 	TX_PIN		11
		
	//register Address
		#define P_MODEL_NUMBER_L 0
		#define P_MODEL_NUMBER_H 1
		#define P_VERSION_L 3		
		#define P_VERSION_H 4
		#define P_ID 5
		#define P_BAUD_RATE 6
		#define P_RETURN_DELAY_TIME 7
		#define P_RETURN_LEVEL 8
		#define P_MIN_ANGLE_LIMIT_L 9
		#define P_MIN_ANGLE_LIMIT_H 10
		#define P_MAX_ANGLE_LIMIT_L 11
		#define P_MAX_ANGLE_LIMIT_H 12
		#define P_LIMIT_TEMPERATURE 13
		#define P_MAX_LIMIT_VOLTAGE 14
		#define P_MIN_LIMIT_VOLTAGE 15
		#define P_MAX_TORQUE_L 16
		#define P_MAX_TORQUE_H 17
		#define P_ALARM_LED 18
		#define P_ALARM_SHUTDOWN 19
		#define P_COMPLIANCE_P 21
		#define P_COMPLIANCE_D 22
		#define P_COMPLIANCE_I 23
		#define P_PUNCH_L 24
		#define P_PUNCH_H 25
		#define P_CW_DEAD 26
		#define P_CCW_DEAD 27
		#define P_IMAX_L 28
		#define P_IMAX_H 29
		#define P_OFFSET_L 30
		#define P_OFFSET_H 31

		#define P_TORQUE_ENABLE 40
		#define P_LED 41
		#define P_GOAL_POSITION_L 42
		#define P_GOAL_POSITION_H 43
		#define P_GOAL_SPEED_L 44
		#define P_GOAL_SPEED_H 45
		#define P_LOCK 48

		#define P_PRESENT_POSITION_L 56
		#define P_PRESENT_POSITION_H 57
		#define P_PRESENT_SPEED_L 58
		#define P_PRESENT_SPEED_H 59
		#define P_PRESENT_LOAD_L 60
		#define P_PRESENT_LOAD_H 61
		#define P_PRESENT_VOLTAGE 62
		#define P_PRESENT_TEMPERATURE 63
		#define P_REGISTERED_INSTRUCTION 64
		#define P_ERROR 65
		#define P_MOVING 66
		#define P_VIR_POSITION_L 67
		#define P_VIR_POSITION_H 68
		#define P_CURRENT_L 69
		#define P_CURRENT_H 70

	//Instruction:
		#define INST_PING 0x01
		#define INST_READ 0x02
		#define INST_WRITE 0x03
		#define INST_REG_WRITE 0x04
		#define INST_ACTION 0x05
		#define INST_RESET 0x06	
		#define INST_SYNC_WRITE 0x83
};
#endif
