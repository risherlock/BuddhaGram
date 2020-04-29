/*
 * room8.h
 *
 * Created: 1/25/2020 11:34:16 PM
 *  Author: Rishav and Ant
 */ 


#ifndef ROOM8_H_
#define ROOM8_H_

#include "../includes.h"

//slaves
#define NO_OF_SLAVES 3
#define LIGHT_CONTROLLER 0x45
#define BUDDHA 0x46
#define AANANDA 0x47

//amp_volume (max:32)
#define VOLUME 18

//Lights
#define MIRROR_REFLECTION_LIGHT L3
#define AANANDA_FOCUS_LIGHT     B2
#define AUDIENCE_STAR_LIGHT		B1
#define BUDDHA_FOCUS_LIGHT		L4
#define VIXU_FOCUS_LIGHT        L1
#define ATMOSPHERIC_LIGHT       R2
#define SUBHADRA_FOCUS_LIGHT    G1
#define AUDIENCE_LIGHT			G2
#define FRONT_LIGHT				L2
#define WALL_LIGHT_R			B3
#define WALL_LIGHT_G			R3
#define WALL_LIGHT_B			G3

//Servo Id
#define SHOULDER_SERVO 3
#define MOUTH_SERVO 1

//Pneumatic Id
#define BUDDHA_HEAD_PNEUMATIC 4
#define AANANDA_HEAD_PNEUMATIC 1
#define AANANDA_ELBOW_PNEUMATIC 2

//Servo positions
#define BUDDHA_MOUTH_UP_POS 70
#define BUDDHA_MOUTH_DOWN_POS 160
#define AANANDA_MOUTH_UP_POS 525
#define AANANDA_MOUTH_DOWN_POS 440

#define ON 1
#define OFF 0
#define UP 1
#define DOWN 0

void resetToInitial(){
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AUDIENCE_LIGHT,127,6000);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::mouthStart(AANANDA, AANANDA_MOUTH_UP_POS, AANANDA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_HEAD_PNEUMATIC, OFF);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_ELBOW_PNEUMATIC, OFF);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, OFF);
	_delay_ms(1000);
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::mouthStop(AANANDA);
}

void playScript(){
	//TIME 0:0
	SlaveCtrlAPI::waitTill(toMillis(0,0));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 90, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 50, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 25, 8000);
	
	//TIME 0:8
	SlaveCtrlAPI::waitTill(toMillis(0,8));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 10, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 5, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 0, 8000);
	
	//TIME 0:16
	SlaveCtrlAPI::waitTill(toMillis(0,16));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 90, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 50, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 25, 8000);
	
	//TIME 0:24
	SlaveCtrlAPI::waitTill(toMillis(0,24));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 10, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 5, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 0, 8000);
	
	//TIME 0:32
	SlaveCtrlAPI::waitTill(toMillis(0,32));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 90, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 50, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 25, 8000);
	
	//TIME 0:40
	SlaveCtrlAPI::waitTill(toMillis(0,40));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 10, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 5, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 0, 8000);
	
	//TIME 0:48
	SlaveCtrlAPI::waitTill(toMillis(0,48));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 90, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 50, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 25, 8000);
	
	//TIME 0:56
	SlaveCtrlAPI::waitTill(toMillis(0,56));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 10, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 5, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 0, 8000);
	
	//TIME 1:4
	SlaveCtrlAPI::waitTill(toMillis(1,4));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 90, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 50, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 25, 8000);
	
	//TIME 1:12
	SlaveCtrlAPI::waitTill(toMillis(1,12));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 10, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 5, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 0, 8000);
	
	//TIME 1:20
	SlaveCtrlAPI::waitTill(toMillis(1,20));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 90, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 50, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 25, 8000);
	
	//TIME 1:28
	SlaveCtrlAPI::waitTill(toMillis(1,28));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 10, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 5, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 0, 8000);
	
	//TIME 1:36
	SlaveCtrlAPI::waitTill(toMillis(1,36));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 90, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 50, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 25, 8000);
	
	//TIME 1:40
	SlaveCtrlAPI::waitTill(toMillis(1,41));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 10, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 5, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 0, 8000);
	
	//TIME 1:45
	SlaveCtrlAPI::waitTill(toMillis(1,45));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 90, 6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 50, 6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 20, 6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, FRONT_LIGHT, 127, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, VIXU_FOCUS_LIGHT, 20, 8000);
		
	
	//TIME 1:58
	SlaveCtrlAPI::waitTill(toMillis(1,58));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 100, 8000);
	
	//TIME 2:00
	SlaveCtrlAPI::waitTill(toMillis(2,0));
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_HEAD_PNEUMATIC, ON);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 2:05
	SlaveCtrlAPI::waitTill(toMillis(2,0));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AANANDA_FOCUS_LIGHT, 127, 8000);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, ON);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, ON);
	_delay_ms(300);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, OFF);
	_delay_ms(300);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, ON);
	_delay_ms(300);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, OFF);
	
	
	//TIME 2:11 
	SlaveCtrlAPI::waitTill(toMillis(2,11));
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_HEAD_PNEUMATIC, OFF);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, OFF);
	SlaveCtrlAPI::mouthStart(AANANDA, AANANDA_MOUTH_UP_POS, AANANDA_MOUTH_DOWN_POS);
	
	//TIME 2:12
	SlaveCtrlAPI::waitTill(toMillis(2,12));
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_ELBOW_PNEUMATIC, ON);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, ON);
	
	//TIME 2:14
	SlaveCtrlAPI::waitTill(toMillis(2,14));
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_ELBOW_PNEUMATIC, OFF);
	
	//TIME 2:20
	SlaveCtrlAPI::waitTill(toMillis(2,12));
	SlaveCtrlAPI::mouthStop(AANANDA);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, OFF);
	_delay_ms(300);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, ON);
	_delay_ms(300);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, OFF);
	_delay_ms(300);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, ON);
	_delay_ms(300);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, OFF);
		
	//TIME 2:24
	SlaveCtrlAPI::waitTill(toMillis(2,24));
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_HEAD_PNEUMATIC, ON);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	
	//TIME 2:29
	SlaveCtrlAPI::waitTill(toMillis(2,29));
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_HEAD_PNEUMATIC, OFF);
	
	//TIME 2:55
	SlaveCtrlAPI::waitTill(toMillis(2,54));
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_HEAD_PNEUMATIC, OFF);
	SlaveCtrlAPI::mouthStop(BUDDHA);
	
	
	//TIME 2:56
	SlaveCtrlAPI::waitTill(toMillis(2,56));
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, ON);
	_delay_ms(300);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, OFF);
	_delay_ms(300);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, ON);
	_delay_ms(300);
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, OFF);
	
	//TIME 3:02
	SlaveCtrlAPI::waitTill(toMillis(3,2));
	SlaveCtrlAPI::mouthStart(AANANDA, AANANDA_MOUTH_UP_POS, AANANDA_MOUTH_DOWN_POS);
	
	//TIME 3:10
	SlaveCtrlAPI::waitTill(toMillis(3,10));
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, ON);
	
	//TIME 3:18
	SlaveCtrlAPI::waitTill(toMillis(3,18));
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, OFF);
	SlaveCtrlAPI::mouthStop(AANANDA);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 3:44
	SlaveCtrlAPI::waitTill(toMillis(3,44));
	SlaveCtrlAPI::pneumaticWrite(AANANDA, AANANDA_HEAD_PNEUMATIC, OFF);
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AANANDA_FOCUS_LIGHT, 0, 7000);
	
	//TIME 3:52
	SlaveCtrlAPI::waitTill(toMillis(3,52));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, SUBHADRA_FOCUS_LIGHT, 127, 7000);
	
	//TIME 4:25
	SlaveCtrlAPI::waitTill(toMillis(4,25));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, SUBHADRA_FOCUS_LIGHT, 0, 7000);
	
	//TIME 4:30
	SlaveCtrlAPI::waitTill(toMillis(4,30));
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 5:14
	SlaveCtrlAPI::waitTill(toMillis(5,14));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 45, 2000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 24, 2000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 5, 2000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, FRONT_LIGHT, 74, 2000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 60, 2000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, VIXU_FOCUS_LIGHT, 0, 10000);
	
	//TIME 5:18
	SlaveCtrlAPI::waitTill(toMillis(5,18));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 25, 2000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 12, 2000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 0, 2000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, FRONT_LIGHT, 40, 2000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 30, 2000);
	
	//TIME 5:22
	SlaveCtrlAPI::waitTill(toMillis(5,22));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_R, 5, 4000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_G, 1, 4000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WALL_LIGHT_B, 0, 4000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, FRONT_LIGHT, 0, 4000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 0, 4000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AUDIENCE_STAR_LIGHT, 127, 20000);
	
	//TIME 5:40
	SlaveCtrlAPI::waitTill(toMillis(5,40));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AUDIENCE_STAR_LIGHT, 0, 7000);
	
	//TIME 5:48
	SlaveCtrlAPI::waitTill(toMillis(5,48));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AUDIENCE_STAR_LIGHT, 127, 7000);
	
	//TIME 5:55
	SlaveCtrlAPI::waitTill(toMillis(5,55));
	SlaveCtrlAPI::lightReset(LIGHT_CONTROLLER);
	SlaveCtrlAPI::lightInstantWrite(LIGHT_CONTROLLER, MIRROR_REFLECTION_LIGHT, 127);
	
	//TIME 6:35
	SlaveCtrlAPI::waitTill(toMillis(6,35));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, MIRROR_REFLECTION_LIGHT, 5, 7000);
	
	//TIME 7:25
	SlaveCtrlAPI::waitTill(toMillis(7,25));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, MIRROR_REFLECTION_LIGHT, 0, 5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AUDIENCE_LIGHT, 127,5000);
	
	ampStopAudio();	
}

#endif /* ROOM8_H_ */