/*
 * projectorAPI.cpp
 *
 * Created: 2/2/2020 12:33:36 AM
 *  Author: Rishav
 */ 

#include "projectorAPI.h"
#include "../ir/IRremote.h"
#include "../arduino/arduino.h"
#include "../configs/remoteConfig.h"

#include <util/delay.h>

//Master must wait for 35 secs 
void projector::init(){
	_delay_ms(10000);							//startup delay				
	projector::pressButton(irPROJECTOR_POWER);	//power
	projector::pressButton(irPROJECTOR_POWER);	//second power
	_delay_ms(10000);							//turn on + logo
	projector::pressButton(irPROJECTOR_OK);		//select USB1
	_delay_ms(5000);
	projector::pressButton(irPROJECTOR_OK);		//select movie
	projector::pressButton(irPROJECTOR_OK);		//select drive
	projector::pressButton(irPROJECTOR_RIGHT);	//cursor on video 
}

void projector::play(){
	projector::pressButton(irPROJECTOR_PLAY_PAUSE);
	projector::pressButton(irPROJECTOR_RIGHT);
	projector::pressButton(irPROJECTOR_OK);
	//Wait for clean screen after play
	_delay_ms(PROJECTOR_WAIT_AFTER_PLAY);
}

//Reconfigure for next play
void projector::nextConfig(){
	projector::pressButton(irPROJECTOR_PLAY_PAUSE); //pause video 
	projector::pressButton(irPROJECTOR_BACK);		//cursor on video
}

void projector::lampOn(){
	digitalWrite(PROJECTOR_LAMP_PIN, HIGH);
	_delay_ms(2000); //Capacitor delay
}

void projector::lampOff(){
	digitalWrite(PROJECTOR_LAMP_PIN, LOW);
}

void projector::pressButton(unsigned long txData){
	irTransmit.sendNEC(txData, 32);
	_delay_ms(PROJECTOR_REMOTE_MIN_DELAY);
}


