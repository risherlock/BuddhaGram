/*
 * DMXsun.cpp
 *
 * Created: 2/6/2020 4:14:26 PM
 *  Author: Rishav
 */ 

#include <avr/interrupt.h>
#include "DMXsun.h"
#include <stdlib.h>

void surya::initTimekeeper(){
	
	// CTC Mode2, PS:64, Int en  
	TCCR1B |= _BV(WGM12);
	TIMSK1 |= _BV(OCIE1A);
	TCCR1B |= _BV(CS11) | _BV(CS10);
	
	// Clock for 1ms
	OCR1AL = ((F_CPU /1000) / 64) - 1;
	OCR1AH = 0;

	sei();

}

volatile unsigned long _counter = 0;
/*const uint32_t _colours[] = {0xFF6600, 0xFF6600, 0xFF6600,
							0xEE8422, 0xEE8422, 0xEE8422, 0xFF6600, 
							0x452510, 0x050510, 0x050510};
 */

const uint32_t _colours[] = {0xFFA500, 0xFF7F00, 0xFFC125,
							0xFFD700, 0xEEC900, 0xFF7F24, 0xF0FFFF, 
							0xC1CDCD, 0x5CACEE, 0x473C8B};


uint16_t _t[12]; //time profile
 uint8_t _tv[10]; //tilt values
 uint8_t n = 1;  //used for time increment (1->10)
 uint8_t pi = 1; //profile index used inside ISR 

/* Time and position profile
 * =========================
 
 <- morning -><- afternoon -><- evening ->
 ||---|---|---|---|---|---|---|---|---|---||
    1   2   3   4   5   6   7   8   9   10
 
 * 1. We break the 'SOLAR_DAY->t' into 10 parts
 * 2. We can assign 10 different colors to each
 * 3. The tilt is divided to 10 equal parts too
 */
void surya::initTimeLapse(){

	//delta tilt
	uint8_t dtil = abs(SUN_EAST_TILT_ANG - SUN_WEST_TILT_ANG); 
	
	//angle profile (variable set points)
	_tv[0] = uint8_t(SUN_EAST_TILT_ANG);
	_tv[1] = uint8_t(dtil * 0.1 + _tv[0]);
	_tv[2] = uint8_t(dtil * 0.1 + _tv[1]);
	_tv[3] = uint8_t(dtil * 0.1 + _tv[2]);
	_tv[4] = uint8_t(dtil * 0.1 + _tv[3]);
	_tv[5] = uint8_t(dtil * 0.1 + _tv[4]);
	_tv[6] = uint8_t(dtil * 0.1 + _tv[5]);
	_tv[7] = uint8_t(dtil * 0.1 + _tv[6]);
	_tv[8] = uint8_t(dtil * 0.1 + _tv[7]);
	_tv[9] = uint8_t(SUN_WEST_TILT_ANG);
}

void surya::startTimeLapse(){
	DMX::setColour(_colours[0], effCONSTANT);
	DMX::sweepAngle(TILT_MOTOR, _tv[0],SUN_MOTOR_SPEED);
	_start_flag = 1;
}

void surya::stopTimeLapse(){
	_start_flag = 0;
	_counter = 0;
	DMX::setColour(0x000000, effNoEFFECT); //no light
	DMX::sweepAngle(TILT_MOTOR, SUN_EAST_TILT_ANG, 255);
}


ISR(TIMER1_COMPA_vect){
	if (_start_flag){
		_counter++;
		if (_counter == n*DELTA_TIME){
			//set color and set point (angle)
			DMX::setColour(_colours[n], effCONSTANT);
			DMX::sweepAngle(TILT_MOTOR, _tv[n]+tuneOFFSET, SUN_MOTOR_SPEED);
			n++;
			//return back to East position
			if (n==11 || n==12){
			 DMX::setColour(0x000000, effNoEFFECT); //no light
			 DMX::sweepAngle(TILT_MOTOR, SUN_EAST_TILT_ANG, 255);	
			}
			if (n==13){
				//restart solar day
				surya::startTimeLapse();
				_counter = 0; n = 1;
			}	
		}
	}
}
