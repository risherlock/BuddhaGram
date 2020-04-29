/*
 * a95xAPI.cpp
 *
 * Created: 2/4/2020 10:03:45 PM
 *  Author: Rishav
 */ 


#include "a95xAPI.h"
#include "../ir/IRremote.h"
#include "../configs/remoteConfig.h"

#include <util/delay.h>

//Master must wait for one min 
void a95x::init(){	
	_delay_ms(40000);				//monitor + A95X startup
	a95x::pressButton(irA95X_LEFT);	//media center
	a95x::pressButton(irA95X_OK);	//select
	a95x::pressButton(irA95X_DOWN);	//USB folder
	a95x::pressButton(irA95X_OK);	//select 
	a95x::pressButton(irA95X_DOWN);	//LOST.DIR
	a95x::pressButton(irA95X_DOWN);	//System Volume Info
	a95x::pressButton(irA95X_DOWN);	//video
	a95x::pressButton(irA95X_OK);	//select
	a95x::pressButton(irA95X_RIGHT);//don't resume	
	a95x::pressButton(irA95X_OK);	//select
	a95x::pressButton(irA95X_MENU);	//removes task bar
	a95x::pressButton(irA95X_MENU);	//task bar appears
	a95x::pressButton(irA95X_OK);	//pause
	a95x::pressButton(irA95X_MENU);	//removes task bar	
}

void a95x::play(){
	a95x::pressButton(irA95X_MENU);	//task bar appears
	a95x::pressButton(irA95X_OK);	//pause
	a95x::pressButton(irA95X_MENU);	//removes task bar
}

void a95x::nextConfig(){
	a95x::pressButton(irA95X_RETURN);	//back
	a95x::pressButton(irA95X_OK);		//select
	a95x::pressButton(irA95X_RIGHT);	//don't resume
	a95x::pressButton(irA95X_OK);		//select
	a95x::pressButton(irA95X_MENU);		//removes task bar
	a95x::pressButton(irA95X_MENU);		//task bar appears
	a95x::pressButton(irA95X_OK);		//pause
	a95x::pressButton(irA95X_MENU);		//removes task bar
}

void a95x::pressButton(unsigned long txData){
	irTransmit.sendNEC(txData, 32);
	_delay_ms(A95X_REMOTE_MIN_DELAY);
}