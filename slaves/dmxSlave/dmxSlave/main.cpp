/*
 * slaveDMX.cpp
 *
 * Description : "Master" board used as slaveDMX
 * Created     : 1/28/2020 2:05:32 AM
 * Author      : Rishav
 */ 

#include <avr/io.h>
#include "includes.h"

#define SLAVE_ADDRESS 0x47

//Registers and buffers for Modbus communication
#define REG_OUTPUT_START 1000
#define REG_INPUT_START  1000
#define REG_OUTPUT_NREGS 70
#define REG_INPUT_NREGS  4

//Static Variables
static USHORT   usRegOutputStart = REG_OUTPUT_START;
static USHORT   usRegInputStart = REG_INPUT_START;
static USHORT   usRegOutputBuf[REG_OUTPUT_NREGS];
static USHORT   usRegInputBuf[REG_INPUT_NREGS];

int main(void)
{
	//Timer init for millis();
	init();
	
	//Init indicators
	DDRB |= (1<<PINB1)|(1<<PINB2)|(1<<PINB3)|(1<<PINB4);
	
	//Sun init
	surya::initTimekeeper();
	surya::initTimeLapse();
	
	//Modbus initialization
	const UCHAR ucSlaveID[] = {0xAA, 0xBB, 0xCC};
	eMBInit(MB_ASCII, SLAVE_ADDRESS, 0, 9600, MB_PAR_ODD);
	eMBSetSlaveID(0x34, TRUE, ucSlaveID, 3);
	eMBEnable();
	
	//DMX initialization (14->PIND6)
	DMXSerial.init(DMXController, 14);
	
	_delay_ms(6000);
	DMX::sweepAngle(PAN_MOTOR, 90, 127);
	_delay_ms(1000);
	DMX::sweepAngle(PAN_MOTOR, 0, 127);
	_delay_ms(1000);
	DMX::sweepAngle(TILT_MOTOR, 90, 127);
	_delay_ms(1000);
	DMX::sweepAngle(TILT_MOTOR, 0, 127);
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
				
				//sweep angle
				if (iRegIndex == 11){
					uint8_t motor_select = usRegOutputBuf[iRegIndex]; 
					uint16_t angle = usRegOutputBuf[iRegIndex+1];
					uint8_t speed = usRegOutputBuf[iRegIndex+2];
					
					switch (motor_select){
					case 33://tilt
						DMX::sweepAngle(TILT_MOTOR, angle, speed);
						break;
					case 22://pan
						DMX::sweepAngle(PAN_MOTOR, angle, speed);
						break;
					}
				}
				
				//start sun
				else if (iRegIndex == 15){
					surya::startTimeLapse();
				}
				
				//stop sun
				else if (iRegIndex == 16){
					surya::stopTimeLapse();
				}
				
				//set color
				else if (iRegIndex == 17){	
					uint8_t r = usRegOutputBuf[iRegIndex];
					uint8_t g = usRegOutputBuf[iRegIndex+1];
					uint8_t b = usRegOutputBuf[iRegIndex+2];
					uint8_t effect = usRegOutputBuf[iRegIndex+3];
					
					switch (effect){
					case 1://strobe
						DMXSerial.write(DMX_EFFECTS, _DMX_EFFECTS_STROBE_MAX);
						break;
					case 2://constant
						DMXSerial.write(DMX_EFFECTS, _DMX_EFFECTS_CONSTANT);
						break;
					case 3://no effect
						DMXSerial.write(DMX_EFFECTS, _DMX_EFFECTS_noEFFECT);
						break;
					}
					DMXSerial.write(DMX_RED,r);
					DMXSerial.write(DMX_GREEN,g);
					DMXSerial.write(DMX_BLUE,b);		
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



