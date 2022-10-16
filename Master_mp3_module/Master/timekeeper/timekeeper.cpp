/*
 * TimeKeeper.cpp
 *
 * Created: 12/11/2013 9:22:07 AM
 *  Author: R_Shrestha
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../configs/masterConfig.h"
#include "TimeKeeper.h"

volatile unsigned long timeMS=0;

void TimeKeeper::init(void){
	
	// CTC Mode2, PS:64, Int en  
	TCCR1B |= _BV(WGM12);
	TIMSK1 |= _BV(OCIE1A);
	TCCR1B |= _BV(CS11) | _BV(CS10);
	
	// Clock for 1ms
	OCR1AL = ((F_CPU /1000) / 64) - 1;
	OCR1AH = 0;

	timeMS = 0;
	sei();
}

unsigned long TimeKeeper::millis(void){
	return timeMS;
}

ISR(TIMER1_COMPA_vect){
	timeMS++;
}