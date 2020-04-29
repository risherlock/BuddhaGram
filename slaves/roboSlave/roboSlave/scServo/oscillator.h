/*
 * oscillator.h
 *
 * Created: 12/28/2019 11:25:08 PM
 *  Author: Rishav
 */ 

/* Timer1 Compare Match Interrupt based callback */
#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#ifndef F_CPU
#define F_CPU 16000000UL 
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../slaveConfig.h"
#include "scServo.h"

SCServo servo;

#define TASK_INTERVAL 1 //task interval (sec)
volatile unsigned long osc_counter = 0;

volatile uint8_t osc_state_flag =  0;  //0:mouth_close
volatile uint8_t osc_switch =  0;      //0:off, 1:start_speaking, 2:stop_speaking
volatile uint16_t osc_close_pos = 0;
volatile uint16_t osc_open_pos = 0;

void oscInit(){
	
	uint16_t compare_value = (((F_CPU /100) / 1024) - 1);  //10ms
	
	//CTC, PS:1024 
	TCCR1A |= ((0<<WGM11) | (0<<WGM10));
	TCCR1B |= ((0<<WGM13) | (1<<WGM12) | (1<<CS12) | (0<<CS11) | (1<<CS10));
	
	//Output Compare Match A interrupt enable
	TIMSK1 |= ((0<<OCIE1B) | (1<<OCIE1A) | (0<<TOIE1));
	
	//8 bit compare value
	OCR1AL = uint8_t(compare_value);
	OCR1AH = (compare_value<<8);
	
	sei();
	
}

ISR(TIMER1_COMPA_vect){
	osc_counter++;
		
	//Repeats every 'TASK_INTERVAL' sec(s)  
	if (osc_counter == TASK_INTERVAL * 100){
		osc_counter = 0;
		PORTD ^= (1<<PIND7);
	
		//Start speaking & set_pos must not be 0 
		if ((osc_switch == 1) & (osc_open_pos>0) & (osc_close_pos>0)){
			//close
			if (!osc_state_flag){
				servo.WritePos(1, osc_close_pos, SERVO_VELOCITY);
			}
			//open
			else{
				servo.WritePos(1, osc_open_pos, SERVO_VELOCITY);
			}
			osc_state_flag = !(osc_state_flag);
		}
		
		//Stop speaking
		else if((osc_switch == 2) & (osc_close_pos>0)){
			servo.WritePos(1, osc_close_pos, SERVO_VELOCITY);	
			osc_state_flag = 1; //Open next time
			osc_switch = 0;     //Switch off oscillator		
		}
	}
}

#endif /* OSCILLATOR_H_ */