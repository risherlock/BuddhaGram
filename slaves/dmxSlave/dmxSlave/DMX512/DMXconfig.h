/*
 * DMXconfig.h
 *
 * Created: 1/29/2020 2:20:41 PM
 *  Author: Rishav
 */ 

#ifndef DMXCONFIG_H_
#define DMXCONFIG_H_

/* DMX specifications
 * ==================
 * Name				: LED mini moving head
 * Model No.		: MJ-1005C
 * Power Supply		: AC100-240V, 50/60Hz
 * Lights			: 7pcs 5 in 1 LEDs
 * Power			: 100W
 * Protocol			: DMX512
 * Channels			: 13CH
 * Rotation			: pan->540', tilt->90' 
 * Pinout (XLR-3)	: 1->'Ground(Red->Black,Yellow)',
 *					  2->'+(White->Red)', 
 *					  3->'-(Black->Green)'
 *		* + - * *
 *		 + - * *
 */

//DMX Channels
#define DMX_PAN				1 	
#define DMX_PAN_FINE		2 
#define DMX_TILT			3	 	
#define DMX_TILT_FINE		4 
#define DMX_SPEED			5 //max_speed->0	
#define DMX_EFFECTS			6 
#define DMX_RED				7 //max_brightness->0		
#define DMX_GREEN			8	
#define DMX_BLUE			9			
#define DMX_WHITE			10		
#define DMX_COLOUR			11	
#define DMX_AUTO		    12 
#define DMX_MODES			13		

/* Channel 6
 * =========
 * 0-7		:	no effect
 * 135-239	:	strobe from low to fast
 */
#define _DMX_EFFECTS_noEFFECT	0
#define _DMX_EFFECTS_STROBE_MAX 239
#define _DMX_EFFECTS_STROBE_MIN 135
#define _DMX_EFFECTS_CONSTANT	255

/* Channel 13
 * ==========
 * 0-142	:	auto
 * 143-255	:	music controlled
 */
#define _DMX_MODES_MUSIC 255
#define _DMX_MODES_AUTO  100


#endif /* DMXCONFIG_H_ */

