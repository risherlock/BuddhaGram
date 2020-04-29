/*
 * remoteCtrlAPI.cpp
 *
 * Created: 2/4/2020 6:01:09 PM
 *  Author: Rishav
 */ 


#include "../roomSelect.h"
#include "remoteCtrlAPI.h"

/*
 * 1. Used only when device is first plugged into AC 
 * 2. Initializes remote slave based on selected ROOM 
 * 3. Cursor to video and waits for the play command
 */
void remote::init(){
	#if defined(ROOM) && (ROOM==2)
		projector::init();
	#endif
	
	#if defined(ROOM) && (ROOM==3)
		wega::init();
	#endif
	
	#if defined(ROOM) && (ROOM==4) && (HOLOGRAM==1)
		wega::init();
	#endif	
	
	#if defined(ROOM) && (ROOM==4) && (HOLOGRAM==2)
		t96mini::init();
	#endif
	
	#if defined(ROOM) && (ROOM==5)
		a95x::init();
	#endif
}

//Plays the video
void remote::play(){
	#if defined(ROOM) && (ROOM==2)
		projector::play();
	#endif
	
	#if defined(ROOM) && (ROOM==3)
		wega::play();
	#endif
	
	#if defined(ROOM) && (ROOM==4) && (HOLOGRAM==1)
		wega::play();
	#endif
	
	#if defined(ROOM) && (ROOM==4) && (HOLOGRAM==2)
		t96mini::play();
	#endif
	
	#if defined(ROOM) && (ROOM==5)
		a95x::play();
	#endif	
}

//Reset for next show
void remote::nextConfig(){
	#if defined(ROOM) && (ROOM==2)
		projector::nextConfig();
	#endif
	
	#if defined(ROOM) && (ROOM==3)
		wega::nextConfig();
	#endif
	
	#if defined(ROOM) && (ROOM==4) && (HOLOGRAM==1) 
		wega::nextConfig();
	#endif
	
	#if defined(ROOM) && (ROOM==4) && (HOLOGRAM==2)
		t96mini::nextConfig();
	#endif
	
	#if defined(ROOM) && (ROOM==5)
		a95x::nextConfig();
	#endif
}

//Projector lamp off
void remote::lampOff(){
	#if defined(ROOM) && (ROOM==2)
		projector::lampOff();
	#endif
}

//Projector lamp on
void remote::lampOn(){
	#if defined(ROOM) && (ROOM==2)
		projector::lampOn();
	#endif
}