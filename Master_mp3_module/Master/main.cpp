/*
 * Master.cpp
 *
 * Created: 1/16/2020 1:51:10 PM
 * Author : Rishav
 */ 

//Room select 
#define ROOM 7

#include <avr/io.h>
#include "rooms/roomSelect.h"

int main(void){
	
	//Arduino core init 
	init();
	
	//For communication
	SlaveCtrlAPI::init();
	_delay_ms(2000);
	 
	//Initialize mp3 module
	ampInit(VOLUME);
	indicator4On();
	
	//Initially audience lights on
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,127,7000);
	
	//On-board LEDs and pins
	initIndicators();
	startButtonInit();
	motorInit();
	 
	//Communication check
	if (!SlaveCtrlAPI::lightReset(LIGHT_CONTROLLER)){indicator1On();}
	
	/* Replace with your application code */

	while (1){	
		//Servo, pneumatic and lights reset
		resetToInitial();
				
		//Switch actions (From operator)
		startWait();
		
		//Start timer
		TimeKeeper::init();
		
		//Language select
		chooseLanguage(VOLUME);
		
		//Start show
		playScript();			
	}
}
