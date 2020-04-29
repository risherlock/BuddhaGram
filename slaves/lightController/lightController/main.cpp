/*
 * lightController.cpp
 *
 * Created	: 2014 
 *	Edited	: 2019/20 
 *  Author	: R_Shrestha 
 */ 

#include <avr/io.h>
#include "includes.h"

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
	
	//Software PWM init
	softpwm_init();
	
	//Lights check
	for (uint8_t i=0; i<16; i++){
		softpwm_write(i,127);
	}
	_delay_ms(100);
	for (uint8_t i=0; i<16; i++){
		softpwm_write(i,0);
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
				
				//Addresses for light
				if (iRegIndex<32){
					//Address where the PWM position  is written
					if ( (!((iRegIndex+1)%SOFTPWM_BLOCK)) ){
						static uint8_t pwm_index;
						pwm_index = (iRegIndex-1)/SOFTPWM_BLOCK;
					
						//Instantaneous write(upper 8 bit)
						if (usRegOutputBuf[iRegIndex] & 0xFF00){
							softpwm_write(pwm_index, (usRegOutputBuf[iRegIndex]>>8)&0x7F);
						}
					
						//Slow write(lower 8 bit)
						else{
							softpwm_transition(pwm_index, usRegOutputBuf[iRegIndex]&0x7F, usRegOutputBuf[iRegIndex-1]);
						}	
					}
				}
				//Reset lights
				else if (iRegIndex==32){
					softpwm_init();
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


