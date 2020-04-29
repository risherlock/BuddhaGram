/*
 * masterConfig.h
 *
 * Description: Hardware config of 'Master'
 *  Created: 12/23/2019 12:22:46 PM
 *   Author: Rishav
 */ 

#ifndef MASTERCONFIG_H_
#define MASTERCONFIG_H_

/* 'Master' board 
 * ==============
 * Fuse-bit(Atmega1284P)	: F9 D9 FF
 * Indicators				: B1, B2, B3 and B4
 * 'to slaves' UART			: UART1
 * 'to super master' UART	: UART0
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define MOTOR_PIN PINA7
#define MOTOR2_PIN PINA4
#define START_BUTTON_PIN PINA6
#define NEPALI_LANGUAGE_PIN PINA0
#define ENGLISH_LANGUAGE_PIN PINA1
#define HINDI_LANGUAGE_PIN PINA5

#define DDR(x) (*(&x-1))

#define motorInit() ((DDRA |= (_BV(MOTOR_PIN) | _BV(MOTOR2_PIN))),\
(PORTA |= _BV(MOTOR_PIN)),\
(PORTA |= _BV(MOTOR2_PIN)))
#define motorOn() (PORTA |= _BV(MOTOR_PIN))
#define motorOff() (PORTA &= ~(_BV(MOTOR_PIN)))
#define motor2On() (PORTA |= _BV(MOTOR2_PIN))
#define motor2Off() (PORTA &= ~(_BV(MOTOR2_PIN)))

//On-board LEDs
#define initIndicators() (DDRB |= _BV(PB1) | _BV(PB2) | _BV(PB3) | _BV(PB4))
#define indicator1On() (PORTB |= _BV(PB1))
#define indicator1Off() (PORTB &= ~(_BV(PB1)))
#define indicator2On() (PORTB |= _BV(PB2))
#define indicator2Off() (PORTB &= ~(_BV(PB2)))
#define indicator3On() (PORTB |= _BV(PB3))
#define indicator3Off() (PORTB &= ~(_BV(PB3)))
#define indicator4On() (PORTB |= _BV(PB4))
#define indicator4Off() (PORTB &= ~(_BV(PB4)))

#define startButtonInit() ((DDRA &= ~(_BV(START_BUTTON_PIN|NEPALI_LANGUAGE_PIN|ENGLISH_LANGUAGE_PIN|HINDI_LANGUAGE_PIN))),\
(PORTA|=_BV(START_BUTTON_PIN|NEPALI_LANGUAGE_PIN|ENGLISH_LANGUAGE_PIN|HINDI_LANGUAGE_PIN)))

//Start switch long press
#define startWait()\
while(1){\
	while(!(PINA & _BV(START_BUTTON_PIN)));\
	_delay_ms(250);\
	if(!(PINA & _BV(START_BUTTON_PIN))) continue;\
	_delay_ms(250);\
	if(!(PINA & _BV(START_BUTTON_PIN))) continue;\
	_delay_ms(250);\
	if((PINA & _BV(START_BUTTON_PIN))) break;\
}

#endif /* MASTERCONFIG_H_ */