/*
 * ampCtrlAPI.h
 *
 * Created: 1/12/2020 7:16:14 PM
 *  Author: Rishav
 */ 

 
#ifndef AMPCTRLAPI_H_
#define AMPCTRLAPI_H_

#include "../configs/remoteConfig.h"
#include "../arduino/arduino.h"
#include "../ir/IRremote.h"

IRsend irTransmit;

enum language{
	NEPALI,    //Remote:1
	ENGLISH,   //Remote:2
	HINDI      //Remote:3
};
	 
/*	
 * Waits till the amp responses 
 * amp_max_delay: maximum response time of vacuum tube amp 
 */
void ampInit(uint8_t amp_max_delay){
	
	//Initialization for timer0
	init();
	
	// No. of loops to wait for specified time
	// 100 loops: 22 secs (observed)
	// 150 loops: 33 secs
	// 200 loops: 44 secs
	// -> 1 sec: 5 loops
	uint8_t counter = 5*amp_max_delay;
	
	//To make sure the volume decreases to zero
	if (counter<AMP_MAX_VOLUME){counter=32;}
	
	//Fires 'stop' signals and 'volume decrease' signals
	for (uint8_t i=0; i<=counter; i++)
	{
		irTransmit.sendNEC(AMP_STOP, 32);
		_delay_ms(AMP_REMOTE_MIN_DELAY);
		
		irTransmit.sendNEC(AMP_VOL_DEC, 32);
		_delay_ms(AMP_REMOTE_MIN_DELAY);
	}
	
}

//Stops the audio and resets volume to 0
void ampStopAudio(){
	for (uint8_t i=0; i<=32; i++){
		irTransmit.sendNEC(AMP_STOP, 32);
		_delay_ms(AMP_REMOTE_MIN_DELAY);
		
		irTransmit.sendNEC(AMP_VOL_DEC,32);
		_delay_ms(AMP_REMOTE_MIN_DELAY);
	}
}

void ampPlayAudio(uint8_t volume, language lan){
	//Max volume = 32
	if (volume>AMP_MAX_VOLUME){volume=AMP_MAX_VOLUME;}

	switch (lan){
	case NEPALI: 
		irTransmit.sendNEC(AMP_PLAY_PAUSE, 32);
		_delay_ms(AMP_REMOTE_MIN_DELAY);
		irTransmit.sendNEC(AMP_ONE, 32);
		break;
	
	case ENGLISH:
		irTransmit.sendNEC(AMP_PLAY_PAUSE, 32);
		_delay_ms(AMP_REMOTE_MIN_DELAY);
		irTransmit.sendNEC(AMP_TWO, 32);
		break;
	
	case HINDI:
		irTransmit.sendNEC(AMP_PLAY_PAUSE, 32);
		_delay_ms(AMP_REMOTE_MIN_DELAY);
		irTransmit.sendNEC(AMP_THREE, 32);
		break;	
	}
	_delay_ms(AMP_REMOTE_MIN_DELAY);
	irTransmit.sendNEC(AMP_PLAY_PAUSE,32);
	
	for (uint8_t i=0; i<=volume; i++){
		irTransmit.sendNEC(AMP_VOL_INC, 32);
		_delay_ms(AMP_REMOTE_MIN_DELAY);
	}	
}

#endif /* AMPCTRLAPI_H_ */