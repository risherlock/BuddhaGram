/*
 * slaveCtrlAPI.h
 *
 * Created: 12/8/2013 9:17:08 AM
 *  Author: R_Shrestha
 *   Modified: Rishav
 */ 


#include <stdint.h>

#ifndef SLAVECTRLAPI_H_
#define SLAVECTRLAPI_H_

//IR device interface
enum irSlaveCmd{
	LAMP_ON,
	LAMP_OFF,
	RECONFIGURE,
	PLAY_VIDEO
};

enum dmxEffects{
	STROBE,
	CONSTANT,
	NO_EFFECT
};

enum dmxState{
	START_SUN,
	STOP_SUN
};

enum dmxMotor{
	PAN_MOTOR,
	TILT_MOTOR
};

class SlaveCtrlAPI{

	public:
	
	static void init(void);
	
	//roboSlave
	static uint8_t pneumaticWrite(uint16_t slave_addr, uint8_t pneumaticNumber, uint8_t state);
	static uint8_t servoPosWrite(uint8_t slave_addr, uint8_t servoId, uint16_t position);
	static uint8_t mouthStart(uint8_t slave_addr, uint16_t up_pos, uint16_t down_pos);
	static uint8_t mouthStop(uint8_t slave_addr);
	
	//lightController
	static uint8_t lightGradualWrite(uint16_t slave_addr, uint8_t lightNumber, uint8_t intensity, uint16_t duration);
	static uint8_t lightInstantWrite(uint16_t slave_addr, uint8_t lightNumber, uint8_t intensity);
	static uint8_t lightReset(uint16_t slave_addr);
	
	//irSlave
	static uint8_t irSlaveCommand(uint16_t slave_addr, irSlaveCmd command);
	
	//dmxSlave 
	static uint8_t dmxSweepAngle(uint16_t slave_addr, dmxMotor m, uint16_t angle, uint8_t speed);
	static uint8_t dmxColour(uint16_t slave_addr, uint8_t r, uint8_t g, uint8_t b, dmxEffects e);
	static uint8_t dmxSunStart(uint16_t slave_addr);
	static uint8_t dmxSunStop(uint16_t slave_addr);
	
	//Wait
	static void waitTill(uint32_t x);
};



#endif /* SLAVECTRLAPI_H_ */