/*
 * wega.cpp
 *
 * Created: 2/4/2020 4:06:56 PM
 *  Author: Rishav
 */ 

#include "wegaAPI.h"
#include "../ir/IRremote.h"
#include "../configs/remoteConfig.h"

#include <util/delay.h>

// !! Don't edit !!
//Master must wait for 30 seconds
void wega::init(){
		_delay_ms(10000);					//startup delay
		wega::pressButton(irWEGA_POWER);	//power
		_delay_ms(500);						//wait
		wega::pressButton(irWEGA_POWER);	//power
		_delay_ms(13000);					//wait for startup
		wega::pressButton(irWEGA_RIGHT);	//music
		wega::pressButton(irWEGA_RIGHT);	//movie
		wega::pressButton(irWEGA_OK);		//select movie
		wega::pressButton(irWEGA_OK);		//select drive
		wega::pressButton(irWEGA_RIGHT);	//cursor on video
		wega::pressButton(irWEGA_OK);		//select video
		wega::pressButton(irWEGA_PLAY);		//pause
}

void wega::play(){
	wega::pressButton(irWEGA_PLAY);		//play
}

void wega::nextConfig(){
	wega::pressButton(irWEGA_STOP);		//stop
	wega::pressButton(irWEGA_OK);		//select video
	_delay_ms(2000);					//video buffer
	wega::pressButton(irWEGA_RIGHT);	//don't resume
	wega::pressButton(irWEGA_OK);		//select
	wega::pressButton(irWEGA_PLAY);		//pause	
}

void wega::pressButton(unsigned long txData){
	irTransmit.sendNEC(txData, 32);
	_delay_ms(WEGA_REMOTE_MIN_DELAY);	
}