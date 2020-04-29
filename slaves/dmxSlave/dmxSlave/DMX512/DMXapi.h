/*
 * DMXapi.h
 *
 * Created: 1/31/2020 11:05:27 AM
 *  Author: Rishav
 */ 

#ifndef DMXAPI_H_
#define DMXAPI_H_

#include "DMXconfig.h"
#include "DMXSerial.h"
#include "colours.h"
#include "DMXsun.h"

enum effect{
	effSTROBE,    
	effCONSTANT,   
	effNoEFFECT     
};

enum motorSel{
	PAN_MOTOR,
	TILT_MOTOR
};

class DMX
{
public:
	static void pointToXY(int x, int y);
	static void sweepAngle(motorSel motor, uint16_t deg, uint8_t speed);
	static void lightsOff();
	static void setColour(uint32_t hex_rgb, effect _effect);
	static void panSweep(uint8_t pan_value, uint8_t speed);
	static void tiltSweep(uint8_t tilt_value, uint8_t speed);
};

#endif /* DMXAPI_H_ */