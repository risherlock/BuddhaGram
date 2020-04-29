/*
 * DMXapi.cpp
 *
 * Created: 1/31/2020 11:05:05 AM
 *  Author: Rishav
 */ 

#include <stdint.h>
#include "DMXapi.h"

/*
 * DMX faces to specified coordinate
 * X -> pan_angle, Y -> tilt_angle
 * speed -> max
 */
void DMX::pointToXY(int x, int y){
	DMX::sweepAngle(PAN_MOTOR, x, 255);
	DMX::sweepAngle(TILT_MOTOR, y, 255);
}


void DMX::sweepAngle(motorSel motor, uint16_t deg, uint8_t speed){
	uint8_t DMX_motor_val = 0;
	switch (motor)
	{   
		//255->540'
		case PAN_MOTOR:
			if (deg>540){deg = 540;}
			DMX_motor_val = (255 / 540.0) * deg;
			DMX::panSweep(DMX_motor_val, speed);
			break;
		
		//255->90'	
		case TILT_MOTOR:
			if (deg>90){deg = 90;}
			DMX_motor_val = (255 / 90.0) * deg;
			DMX::tiltSweep(DMX_motor_val, speed);
			break;
	}
}


void DMX::panSweep(uint8_t pan_value, uint8_t speed){
	//max_speed = 255 for panSweep();
	uint8_t _speed = 255 - speed;
	DMXSerial.write(DMX_SPEED, _speed);
	DMXSerial.write(DMX_PAN, pan_value);
}

void DMX::tiltSweep(uint8_t tilt_value, uint8_t speed){
	uint8_t _speed = 255 - speed;
	DMXSerial.write(DMX_SPEED, _speed);
	DMXSerial.write(DMX_TILT, tilt_value);	
}

void DMX::lightsOff(){
	DMXSerial.write(DMX_EFFECTS, _DMX_EFFECTS_noEFFECT);
}

/* setColour(); description:
 * ========================
 * Each hex takes 4 bits
 * Right shift by 16 bits turns 0xRRGGBB to 0xRR
 * Masking with 0xff takes only first 3 bits
 * eg: hex_rgb = 0xff234d;
 */	
void DMX::setColour(uint32_t hex_rgb, effect _effect){
	
	int red, green, blue;
    red		= ((hex_rgb>>16) & 0xff);
	green	= ((hex_rgb>>8) & 0xff);
	blue	= ((hex_rgb>>0) & 0xff);
	
	switch (_effect)
	{
		case effSTROBE:
			DMXSerial.write(DMX_EFFECTS, _DMX_EFFECTS_STROBE_MAX);
			break;
						
		case effCONSTANT:
			DMXSerial.write(DMX_EFFECTS, _DMX_EFFECTS_CONSTANT);
			break;
			
		case effNoEFFECT:
			DMXSerial.write(DMX_EFFECTS, _DMX_EFFECTS_noEFFECT);
			break;	
	}
	DMXSerial.write(DMX_RED, red);
	DMXSerial.write(DMX_GREEN, green);
	DMXSerial.write(DMX_BLUE, blue);
}