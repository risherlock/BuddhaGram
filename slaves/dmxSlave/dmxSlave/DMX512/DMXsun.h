/*
 * DMXsun.h
 *
 * Created: 2/6/2020 4:14:02 PM
 *  Author: Rishav
 */ 


#ifndef DMXSUN_H_
#define DMXSUN_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include "DMXapi.h"

/* TUNING FOR SMOOTH MOTION
 * ========================
 * Play with: 
 *	 - tuneOFFSET value,
 *	 - DELTA_TIME value and
 *	 - SUN_MOTOR_SPEED value	
 */

#define SUN_EAST_TILT_ANG 0
#define SUN_WEST_TILT_ANG 90
#define SUN_EAST_PAN_ANG 0
#define SUN_WEST_PAN_ANG 90

//tuning parameters
#define SUN_MOTOR_SPEED 0
#define tuneOFFSET 1
#define DELTA_TIME uint16_t(2000)

static volatile uint8_t _start_flag = 0;
class surya
{
public:
	static void initTimekeeper();
	static void initTimeLapse();
	static void startTimeLapse();
	static void stopTimeLapse();
};

#endif /* DMXSUN_H_ */