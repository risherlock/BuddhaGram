/*
 * slaveConfig.h
 *
 * Created: 12/26/2019 10:23:46 PM
 *  Author: Rishav
 */ 

/* !! Uncomment for ROOM7 !!*/
//#define BUDDHA_SLAVE 1

#ifndef SLAVECONFIG_H_
#define SLAVECONFIG_H_

//command address
#define MOUTH_START_ADDR 60
#define MOUTH_STOP_ADDR 63
#define PNEUMATIC_ADDR 53
#define SERVO_ADDR 57

#define SERVO_VELOCITY 1023

//Viewing from connector side
//tip122 pins:  C4, B5, C3, C5, 12V
#if (!BUDDHA_SLAVE)
	uint8_t pneumatic_pin[4] = {PIN_A4, LED_BUILTIN, PIN_A3, PIN_A5};
	void pneumaticInit(){
		for (uint8_t i=0; i<4; i++){
			pinMode(pneumatic_pin[i], OUTPUT);
			digitalWrite(pneumatic_pin[i], LOW);
		}
	}
#endif

/* Pneumatic pins "lightController" used as roboSlave
 *		PORTB : B0, B1, B2, B4, B5
 *		PORTC :	C0, C1, C2, C3, C4, C5 
 *		PORTD : D4, D5, D6, D7
 */
#if defined(BUDDHA_SLAVE)  
	uint8_t pneumatic_pin[15] = {8, 9, 10, 12, 13,			/*PORTB*/
								 14, 15, 16, 17, 18, 19,	/*PORTC*/
								 4, 5, 6, 7};				/*PORTD*/
	void pneumaticInit(){
		for (uint8_t i=0; i<15; i++){
			pinMode(pneumatic_pin[i], OUTPUT);
			digitalWrite(pneumatic_pin[i], LOW);
		}
	}
#endif

#endif /* SLAVECONFIG_H_ */