/*
 * roboSlave.cpp
 *
 * Created: 1/24/2020 4:19:54 PM
 * Author : Rishav
 */ 

#include <avr/io.h>
#include "includes.h"

//Slave address
#define SLAVE_ADDRESS  0x47

//Registers and buffers for Modbus communication
#define REG_OUTPUT_START 1000
#define REG_INPUT_START 1000
#define REG_OUTPUT_NREGS 70
#define REG_INPUT_NREGS 4

//Static Variables
static USHORT   usRegOutputStart = REG_OUTPUT_START;
static USHORT   usRegInputStart = REG_INPUT_START;
static USHORT   usRegOutputBuf[REG_OUTPUT_NREGS];
static USHORT   usRegInputBuf[REG_INPUT_NREGS];

int main(void)
{
	//Indicator init
	DDRB |= (1<<PINB0);
	DDRD |= (1<<PIND7);
		
	//Timer initializations 
	init();    //for millis();
	oscInit(); //for speak function
 
    //scServo init
	servo.init(57600);
	_delay_ms(500);
	
	//DDR init for pneumatic pins
	pneumaticInit();
	
	//Enable torque for possible motors
	for(uint8_t i=1; i<=5; i++){
		servo.EnableTorque(i, 1);
		_delay_ms(500);	
	}
	
	//Modbus initialization
	const UCHAR ucSlaveID[] = {0xAA, 0xBB, 0xCC};
	eMBInit(MB_ASCII, SLAVE_ADDRESS, 0, 9600, MB_PAR_ODD);
	eMBSetSlaveID(0x34, TRUE, ucSlaveID, 3);
	eMBEnable();
	
	while (1)
	{
		(void )eMBPoll( );
	}
	
}

eMBErrorCode
eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
	eMBErrorCode    eStatus = MB_ENOERR;
	int             iRegIndex;

	if( ( usAddress >= REG_INPUT_START )
	&& ( usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS ) )
	{
		iRegIndex = ( int )( usAddress - usRegInputStart );
		while( usNRegs > 0 )
		{
			*pucRegBuffer++ =
			( unsigned char )( usRegInputBuf[iRegIndex] >> 8 );
			*pucRegBuffer++ =
			( unsigned char )( usRegInputBuf[iRegIndex] & 0xFF );
			iRegIndex++;
			usNRegs--;
		}
	}
	else
	{
		eStatus = MB_ENOREG;
	}

	return eStatus;
}

eMBErrorCode
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs,
eMBRegisterMode eMode )
{
	eMBErrorCode    eStatus = MB_ENOERR;
	int             iRegIndex;

	if( ( usAddress >= REG_OUTPUT_START )
	&& ( usAddress + usNRegs <= REG_OUTPUT_START + REG_OUTPUT_NREGS ) )
	{
		iRegIndex = ( int )( usAddress - usRegOutputStart );
		if(eMode==MB_REG_READ){
			while( usNRegs > 0 )
			{
				*pucRegBuffer++ =
				( unsigned char )( usRegOutputBuf[iRegIndex] >> 8 );
				*pucRegBuffer++ =
				( unsigned char )( usRegOutputBuf[iRegIndex] & 0xFF );
				iRegIndex++;
				usNRegs--;
			}
		}
		else if(eMode==MB_REG_WRITE){
			while( usNRegs > 0 )
			{
				UCHAR upper = *pucRegBuffer++;
				UCHAR lower = *pucRegBuffer++;
				
				usRegOutputBuf[iRegIndex] = (((uint16_t)upper)<<8) | ((uint16_t)lower);
				
				//Servo position command
				if(iRegIndex == SERVO_ADDR){
					servo.WritePos(usRegOutputBuf[iRegIndex], (int)usRegOutputBuf[iRegIndex+1],  SERVO_VELOCITY);
				}
				
				//Speak start command
				else if(iRegIndex == MOUTH_START_ADDR){
					osc_close_pos = (int)usRegOutputBuf[iRegIndex];   //up
					osc_open_pos  = (int)usRegOutputBuf[iRegIndex+1]; //down
					osc_switch = 1; //Start oscillation		
				}
				
				//Speak stop command
				else if(iRegIndex == MOUTH_STOP_ADDR){
					osc_switch = 2; //Stop oscillation
				}
				
				//Pneumatic command
				else if(iRegIndex == PNEUMATIC_ADDR){
					PORTB ^= (1<<PINB0);
					uint16_t pneu_ID = usRegOutputBuf[iRegIndex] - 1;
					digitalWrite(pneumatic_pin[pneu_ID], usRegOutputBuf[iRegIndex+1]);	
				}
				iRegIndex++;
				usNRegs--;
			}
		}
	} 
	else
	{
		eStatus = MB_ENOREG;
	}

	return eStatus;
}


eMBErrorCode
eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils,
eMBRegisterMode eMode )
{
	return MB_ENOREG;
}

eMBErrorCode
eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
	return MB_ENOREG;
}


