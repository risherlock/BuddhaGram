/*
 * mbMasterCallback.cpp
 *
 * Created: 11/9/2013 9:47:14 PM
 *  Author: R_Shrestha
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../mbMaster/ModbusMaster.h"
#include "../uart/uart.h"

extern ModbusMaster modbus_master;

/************************************************
SERIAL CALLBACK FUNCTIONS FOR MODBUSMASTER
*************************************************/

void ModbusMaster::WriteCharacterCB(uint8_t character){
	uart1_putc(character);
	return;
}

ISR (USART1_RX_vect){
	modbus_master.ReadCharacterCB(UDR1);
}


/************************************************
TIMEOUT CALLBACK FUNCTIONS FOR MODBUSMASTER
*************************************************/
//Edited to use timer2 instead of timer0

#include <avr/io.h>
#include <avr/interrupt.h>

#define TIMSK TIMSK2
#define TCCR TCCR2B

static uint8_t tmr2_overflow_count=0;

void ModbusMaster::TimeoutStartCB(void){
	this->TimeoutResetCB();
	
	// PS:1024, En timer OF interrupt
	TCCR |= _BV(CS22) | _BV(CS20);
	TIMSK |= _BV(TOIE2);
}

void ModbusMaster::TimeoutStopCB(void){
	this->TimeoutResetCB();
	TIMSK &= ~(_BV(TOIE2));
}

void ModbusMaster::TimeoutResetCB(void){
	TCNT2 = 0;
	tmr2_overflow_count=0;
		
}


ISR(TIMER2_OVF_vect, ISR_NOBLOCK){
	
	tmr2_overflow_count++;
	
	// 80 produces 1sec timeout (20Mhz)
	if (tmr2_overflow_count>=80){
		tmr2_overflow_count=0;
		modbus_master.TimeoutCB();	
	}
	
}

