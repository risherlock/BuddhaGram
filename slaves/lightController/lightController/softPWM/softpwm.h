/*
 * softpwm.h
 *
 * Created: 8/9/2014 9:31:54 AM
 *  Author: R_Shrestha
 */ 


#ifndef SOFTPWM_H_
#define SOFTPWM_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdlib.h>

#define SOFTPWM_BLOCK 2

#define msPerCycle (16)	// 16e6/2000/128 -> Hz

#define B1 0
#define G1 1
#define R1 2
#define B2 3
#define G2 4
#define R2 5
#define L1 6
#define L2 7
#define L3 8
#define L4 9
#define R3 10
#define G3 11
#define B3 12
#define R4 13
#define G4 14
#define B4 15

void softpwm_write(uint8_t channel, uint8_t pwm);
int16_t softpwm_transition(uint8_t channel, uint8_t target_pwm, uint16_t ms);
void softpwm_init();


#endif /* SOFTPWM_H_ */