/*
 * softpwm.cpp
 *
 * Created: 8/9/2014 9:32:09 AM
 *  Author: R_Shrestha
 */ 

#include "softpwm.h"

volatile uint8_t __swpwm_dc[16];
volatile uint8_t _swpwm_dc[16];	    //double buffering
volatile int8_t _swpwm_step[16];    //change pwm by this much...
volatile uint8_t _swpwm_dt[16];	    //...every this many steps...
volatile uint8_t __swpwm_dt[16];
volatile uint8_t _swpwm_nstep[16];	//...for this many steps
volatile uint8_t _swpwm_tgt[16];
volatile uint8_t _swpwm_cnt = 128;
volatile uint8_t _pwm_changed;

void softpwm_write(uint8_t channel, uint8_t pwm){
	if ((channel > 15) || (pwm > 127)) return;
	_swpwm_nstep[channel] = 0;
	__swpwm_dc[channel] = pwm;
	_pwm_changed = 1;
}

int16_t softpwm_transition(uint8_t channel, uint8_t target_pwm, uint16_t ms){
	if (channel > 15)		return -1;
	if (target_pwm > 127)	return -2;

	int8_t del_pwm = target_pwm - __swpwm_dc[channel];
	if (del_pwm == 0)		return 0;

	uint16_t ncycles = ms/msPerCycle;
	if (ncycles == 0){
		softpwm_write(channel, target_pwm);
		return 0;
	}

	if (ncycles/abs(del_pwm) > 16){
		ncycles = abs(del_pwm) * 16;
	}
	
	int8_t step = ((int16_t)del_pwm)/((int16_t)ncycles);
	step = (step==0)?((del_pwm<0)?-1:1):step;
	
	uint8_t dt = (((int16_t)step)*((int16_t)ncycles))/((int16_t)del_pwm);
	if (dt==0)	dt = 1;
	
	ncycles = dt * del_pwm/step;
	uint8_t nstep = ncycles/dt;
	if (nstep == 0){
		softpwm_write(channel, target_pwm);
		return 0;
	}
	_swpwm_nstep[channel] = 0;
	_swpwm_step[channel] = step;
	_swpwm_dt[channel] = dt;
	__swpwm_dt[channel] = dt;
	_swpwm_tgt[channel] = target_pwm;
	_swpwm_nstep[channel] = nstep;

	return nstep*dt*msPerCycle;
}

void softpwm_init(){
	TIMSK1 = 0;//~(1<<OCIE1A);

	for (uint8_t i=0; i<16; i++){
		_swpwm_dc[i] = 0;
		__swpwm_dc[i] = 0;
		_swpwm_nstep[i] = 0;
	}
	_swpwm_cnt=128;

	DDRB = 0x3F;
	DDRC = 0x3F;
	DDRD |= 0xF0;

	OCR1A = 2000;		//interrupt every this many cycles
	TCCR1A = 0;
	TCCR1B = (0<<WGM13) | (1<<WGM12) | 0x01;
	TIMSK1 = (1<<OCIE1A);
	
	sei();
}

ISR(TIMER1_COMPA_vect){ 
	//using local variable so compiler will use register for faster code
	uint8_t _cnt = _swpwm_cnt;	
	_cnt--;
	if (_cnt){	
		//hard coded for faster ISR code
		if (_cnt == _swpwm_dc[0])	PORTC |= (1<<5);	//B1
		if (_cnt == _swpwm_dc[1])	PORTC |= (1<<4);	//G1
		if (_cnt == _swpwm_dc[2])	PORTC |= (1<<3);	//R1
		if (_cnt == _swpwm_dc[3])	PORTC |= (1<<2);	//B2
		if (_cnt == _swpwm_dc[4])	PORTC |= (1<<1);	//G2
		if (_cnt == _swpwm_dc[5])	PORTC |= (1<<0);	//R2
		if (_cnt == _swpwm_dc[6])	PORTB |= (1<<5);	//L1
		if (_cnt == _swpwm_dc[7])	PORTB |= (1<<4);	//L2
		if (_cnt == _swpwm_dc[8])	PORTB |= (1<<3);	//L3
		if (_cnt == _swpwm_dc[9])	PORTB |= (1<<2);	//L4
		if (_cnt == _swpwm_dc[10])	PORTB |= (1<<1);	//3R
		if (_cnt == _swpwm_dc[11])	PORTD |= (1<<4);	//3G
		if (_cnt == _swpwm_dc[12])	PORTB |= (1<<0);	//3B
		if (_cnt == _swpwm_dc[13])	PORTD |= (1<<7);	//4R
		if (_cnt == _swpwm_dc[14])	PORTD |= (1<<6);	//4G
		if (_cnt == _swpwm_dc[15])	PORTD |= (1<<5);	//4B
	}
	else
	{
		PORTB = 0;
		PORTC = 0;
		PORTD &= ~(0xF0);
		_cnt = 128;		//this many pwm steps (0 to this-1)

		if (_pwm_changed)
		{
			_pwm_changed = 0;
			_swpwm_dc[0] = __swpwm_dc[0];
			_swpwm_dc[1] = __swpwm_dc[1];
			_swpwm_dc[2] = __swpwm_dc[2];
			_swpwm_dc[3] = __swpwm_dc[3];
			_swpwm_dc[4] = __swpwm_dc[4];
			_swpwm_dc[5] = __swpwm_dc[5];
			_swpwm_dc[6] = __swpwm_dc[6];
			_swpwm_dc[7] = __swpwm_dc[7];
			_swpwm_dc[8] = __swpwm_dc[8];
			_swpwm_dc[9] = __swpwm_dc[9];
			_swpwm_dc[10] = __swpwm_dc[10];
			_swpwm_dc[11] = __swpwm_dc[11];
			_swpwm_dc[12] = __swpwm_dc[12];
			_swpwm_dc[13] = __swpwm_dc[13];
			_swpwm_dc[14] = __swpwm_dc[14];
			_swpwm_dc[15] = __swpwm_dc[15];
		}
	}

	//every 8 cycles -> 0,8,16,...
	if (!(_cnt&0x7)){
		uint8_t channel = _cnt/8 -1;
		
		if (_swpwm_nstep[channel]){
			--__swpwm_dt[channel];
			
			if (!(__swpwm_dt[channel])){
				__swpwm_dt[channel] = _swpwm_dt[channel];
				--_swpwm_nstep[channel];

				if (_swpwm_nstep[channel])
					__swpwm_dc[channel] += _swpwm_step[channel];
				else
					__swpwm_dc[channel] = _swpwm_tgt[channel];

				_pwm_changed = 1;
			}
		}
	}
	_swpwm_cnt = _cnt;
}
