/*
 * room1.h
 *
 * Created: 1/26/2020 1:45:58 PM
 *  Author: Rishav and Ant
 */ 

#ifndef ROOM1_H_
#define ROOM1_H_

#include "../includes.h"

//Slaves
#define NO_OF_SLAVES 1
#define LIGHT_CONTROLLER 0x45

//amp_volume (max:32)
#define VOLUME 27

//Lights
#define MIRROR_REFLECTION_LIGHT R3
#define BUDDHA_FOCUS_LIGHT G3
#define BUDDHA_BACK_LIGHT B3
#define GLOBE_FOCUS_LIGHT L1
#define BORDER_BLUE_LIGHT G4
#define ATMOSPHERIC_LIGHT R4
#define GLOBE_TOP_R R1
#define GLOBE_TOP_G G1
#define GLOBE_TOP_B B1
#define AUDIENCE_LIGHT L3
#define STAR_LIGHT R2
#define UV_LIGHT L2


void resetToInitial(){
	motorOn();
	SlaveCtrlAPI::lightInstantWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,127);	
}

void playScript(){	
	//TIME 0:0
	SlaveCtrlAPI::waitTill(toMillis(0,0));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,0,5000);
	
	//TIME 0:5
	SlaveCtrlAPI::waitTill(toMillis(0,5));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,UV_LIGHT,127,30000);
	motorOff();
	
	
	//TIME 0:15
	SlaveCtrlAPI::waitTill(toMillis(0,15));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,STAR_LIGHT,127,10000);
	
	//TIME 0:25
	SlaveCtrlAPI::waitTill(toMillis(0,25));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,STAR_LIGHT,0,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,5,10000);
	
	
	//TIME 0:30
	//UV and blue light alternate
	SlaveCtrlAPI::waitTill(toMillis(0,25));
	
	//TIME 0:35
	SlaveCtrlAPI::waitTill(toMillis(0,35));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,7,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,STAR_LIGHT,127,10000);
	
	//TIME 0:40
	SlaveCtrlAPI::waitTill(toMillis(0,40));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,30,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 0:45
	SlaveCtrlAPI::waitTill(toMillis(0,45));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,5,7000);
	
	//TIME 0:50
	SlaveCtrlAPI::waitTill(toMillis(0,50));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,30,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,10,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,UV_LIGHT,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 0:55
	SlaveCtrlAPI::waitTill(toMillis(0,50));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_BACK_LIGHT,127,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,5,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,UV_LIGHT,127,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,7000);
	
	//TIME 1:00
	SlaveCtrlAPI::waitTill(toMillis(1,00));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 1:05
	SlaveCtrlAPI::waitTill(toMillis(1,05));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,10,7000);
	
	//TIME 1:10
	SlaveCtrlAPI::waitTill(toMillis(1,10));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 1:15
	SlaveCtrlAPI::waitTill(toMillis(1,15));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,10,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,7000);
	
	//TIME 1:20
	SlaveCtrlAPI::waitTill(toMillis(1,20));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 1:27
	SlaveCtrlAPI::waitTill(toMillis(1,27));
	_delay_ms(500);
	SlaveCtrlAPI::lightReset(LIGHT_CONTROLLER);//darkness
	SlaveCtrlAPI::lightInstantWrite(LIGHT_CONTROLLER,MIRROR_REFLECTION_LIGHT,127);
	motorOn();
	
	//TIME 1:45
	SlaveCtrlAPI::waitTill(toMillis(1,45));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,MIRROR_REFLECTION_LIGHT,0,10000);
	
	//TIME 1:55
	SlaveCtrlAPI::waitTill(toMillis(1,55));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_BACK_LIGHT,127,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	motorOff();

	//TIME 2:00
	SlaveCtrlAPI::waitTill(toMillis(2,0));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,127,9000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ATMOSPHERIC_LIGHT,127,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,7000);

	//TIME 2:05
	SlaveCtrlAPI::waitTill(toMillis(2,05));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,10,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 2:10
	SlaveCtrlAPI::waitTill(toMillis(2,10));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,7000);
	
	//TIME 2:16
	SlaveCtrlAPI::waitTill(toMillis(2,16));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_FOCUS_LIGHT,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,UV_LIGHT,127,4000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,10,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 2:20
	SlaveCtrlAPI::waitTill(toMillis(2,20));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,100,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,8000);
	
	//TIME 2:25
	SlaveCtrlAPI::waitTill(toMillis(2,25));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,10,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 2:30
	SlaveCtrlAPI::waitTill(toMillis(2,30));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,7000);
	
	//TIME 2:35
	SlaveCtrlAPI::waitTill(toMillis(2,35));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,10,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 2:40
	SlaveCtrlAPI::waitTill(toMillis(2,40));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,7000);
	
	//TIME 2:45
	SlaveCtrlAPI::waitTill(toMillis(2,45));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 2:50
	SlaveCtrlAPI::waitTill(toMillis(2,20));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,100,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,8000);
	
	//TIME 2:55
	SlaveCtrlAPI::waitTill(toMillis(2,55));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,10,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 3:00
	SlaveCtrlAPI::waitTill(toMillis(3,00));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,7000);
	
	//TIME 3:05
	SlaveCtrlAPI::waitTill(toMillis(3,05));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 3:10
	SlaveCtrlAPI::waitTill(toMillis(3,10));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,100,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,8000);
	
	//TIME 3:15
	SlaveCtrlAPI::waitTill(toMillis(3,15));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,10,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 3:25
	SlaveCtrlAPI::waitTill(toMillis(3,25));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 3:35
	SlaveCtrlAPI::waitTill(toMillis(3,35));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,10,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);

	//TIME 3:40
	SlaveCtrlAPI::waitTill(toMillis(3,40));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R, 0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G, 10,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B, 127,7000);
	
	//TIME 3:45
	SlaveCtrlAPI::waitTill(toMillis(3,45));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,UV_LIGHT,127,6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,127,6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 3:55
	SlaveCtrlAPI::waitTill(toMillis(3,55));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	motorOn();
	
	//TIME 4:01
	SlaveCtrlAPI::waitTill(toMillis(4,1));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,UV_LIGHT,0,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,0,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,0,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,100,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_FOCUS_LIGHT,25,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ATMOSPHERIC_LIGHT,25,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_BACK_LIGHT,25,24000);
	
	//TIME 4:05
	SlaveCtrlAPI::waitTill(toMillis(4,05));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 4:10
	SlaveCtrlAPI::waitTill(toMillis(4,10));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,7000);
	
	//TIME 4:15
	SlaveCtrlAPI::waitTill(toMillis(4,15));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,100,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 4:20
	SlaveCtrlAPI::waitTill(toMillis(4,20)); //darkness
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,UV_LIGHT,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_FOCUS_LIGHT,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ATMOSPHERIC_LIGHT,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_BACK_LIGHT,0,5000);
	
	//TIME 4:25
	SlaveCtrlAPI::waitTill(toMillis(4,25));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 4:35
	SlaveCtrlAPI::waitTill(toMillis(4,35));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	
	//TIME 4:45
	SlaveCtrlAPI::waitTill(toMillis(4,45));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 4:55
	SlaveCtrlAPI::waitTill(toMillis(4,55));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	
	//TIME 5:5
	SlaveCtrlAPI::waitTill(toMillis(5,5));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 5:15
	SlaveCtrlAPI::waitTill(toMillis(5,15));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 5:25
	SlaveCtrlAPI::waitTill(toMillis(5,25));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 5:35
	SlaveCtrlAPI::waitTill(toMillis(5,35));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 5:45
	SlaveCtrlAPI::waitTill(toMillis(5,45));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_BACK_LIGHT,100,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 5:46
	SlaveCtrlAPI::waitTill(toMillis(5,46));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_FOCUS_LIGHT,100,7000);
	
	//TIME 5:48
	SlaveCtrlAPI::waitTill(toMillis(5,48));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,0,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,8000);
	
	//TIME 5:53
	SlaveCtrlAPI::waitTill(toMillis(5,53));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,UV_LIGHT,127,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ATMOSPHERIC_LIGHT,100,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,100,8000);
	motorOff();
	
	//TIME 5:55
	SlaveCtrlAPI::waitTill(toMillis(5,55));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//IME 6:00
	SlaveCtrlAPI::waitTill(toMillis(6,0));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,0,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,8000);
	
	
	//TIME 6:5
	SlaveCtrlAPI::waitTill(toMillis(6,5));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 6:08
	SlaveCtrlAPI::waitTill(toMillis(6,8));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,90,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,10,8000);
	
	//TIME 6:15
	SlaveCtrlAPI::waitTill(toMillis(6,15));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,90,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 6:25
	SlaveCtrlAPI::waitTill(toMillis(6,25));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,100,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 6:35
	SlaveCtrlAPI::waitTill(toMillis(6,35));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,0,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 6:45
	SlaveCtrlAPI::waitTill(toMillis(6,45));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,70,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 6:53
	SlaveCtrlAPI::waitTill(toMillis(6,56));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,100,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,0,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 7:2
	SlaveCtrlAPI::waitTill(toMillis(7,2)); //darkness
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,UV_LIGHT,0,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_BACK_LIGHT,0,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ATMOSPHERIC_LIGHT,0,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_FOCUS_LIGHT,0,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,10,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,127,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,70,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	motorOn();
	
	//TIME 7:10
	SlaveCtrlAPI::waitTill(toMillis(7,10));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,127,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,100,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	//TIME 7:15
	SlaveCtrlAPI::waitTill(toMillis(7,15));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,50,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,127,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 127, 10000);
	
	//TIME 7:22
	SlaveCtrlAPI::waitTill(toMillis(7,22));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_R,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_G,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GLOBE_TOP_B,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BORDER_BLUE_LIGHT,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_BACK_LIGHT,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,127,15000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, STAR_LIGHT, 0, 10000);
	
	_delay_ms(5000);
	ampStop();	
}

#endif /* ROOM1_H_ */