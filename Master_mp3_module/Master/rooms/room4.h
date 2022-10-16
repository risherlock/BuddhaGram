/*
 * room4.h
 *
 * Created: 1/25/2020 8:51:55 PM
 *  Author: Rishav and Ant
 */ 


#ifndef ROOM4_H_
#define ROOM4_H_

#include "../includes.h"

//Slaves
#define NO_OF_SLAVES 4
#define LIGHT_CONTROLLER 0x45
#define BUDDHA 0x46
#define CHANNA 0x47
#define HOLOGRAM_DURBAR 0x49
#define HOLOGRAM_RIVER 0x48

//amp_volume (max:32)
#define VOLUME 27

//Lights
#define AUDIENCE_LIGHT G1
#define BUDDHA_FOCUS_LIGHT R1
#define CHANNA_FOCUS_LIGHT L1
#define TREE_FOCUS_LIGHT B1
#define ATMOSPHERIC_LIGHT_R R2
#define ATMOSPHERIC_LIGHT_G G2
#define ATMOSPHERIC_LIGHT_B B2
#define GROUND_LIGHT B3
#define ISLAND_LIGHT G3
#define MOTOR_LIGHT L2
#define HOLOGRAPHIC_LIGHT L4
#define FAN_MOTOR R3

//Servo Id
#define MOUTH_SERVO 1
#define NECK_SERVO 2
#define SHOULDER_SERVO 3
#define WRIST_SERVO 4
#define HAND_SERVO 5

//Pneumatic Id
#define HEAD_PNEUMATIC 1
#define CHANNA_ELBOW_PNEUMATIC 4
#define CHANNA_WAIST_PNEUMATIC 3
#define BUDDHA_ELBOW_PNEUMATIC 4
#define BUDDHA_WAIST_PNEUMATIC 2

//Servo positions
#define BUDDHA_MOUTH_UP_POS 681
#define BUDDHA_MOUTH_DOWN_POS 600
#define CHANNA_MOUTH_UP_POS 760
#define CHANNA_MOUTH_DOWN_POS 665
#define BUDDHA_HAND_UP_POS 500
#define BUDDHA_HAND_DOWN_POS 600
#define BUDDHA_NECK_CHANNA_POS 600
#define BUDDHA_NECK_SCREEN_POS 800
#define BUDDHA_NECK_MID_POS (BUDDHA_NECK_CHANNA_POS+BUDDHA_NECK_SCREEN_POS)/2

//Waist rotation
#define _b2CHANNA 1
#define _c2BUDDHA 0
#define _b2SCREEN 0
#define _c2SCREEN 1

#define UP 1
#define DOWN 0


void resetToInitial(){
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,127,7000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_MID_POS);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_ELBOW_PNEUMATIC, DOWN);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, DOWN);
	//SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_WAIST_PNEUMATIC, _c2BUDDHA);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, _b2CHANNA);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_CHANNA_POS);
	motorOn();
}
void playScript(){
	//TIME 0:0
	SlaveCtrlAPI::waitTill(toMillis(0,0));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,0,7000);
	SlaveCtrlAPI::irSlaveCommand(HOLOGRAM_DURBAR, PLAY_VIDEO);
	
	//TIME 0:15
	SlaveCtrlAPI::waitTill(toMillis(0,15));
	
	//TIME 2:19
	SlaveCtrlAPI::waitTill(toMillis(2,19));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ATMOSPHERIC_LIGHT_R,127,15000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ATMOSPHERIC_LIGHT_G,127,15000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ATMOSPHERIC_LIGHT_B,80,15000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BUDDHA_FOCUS_LIGHT,30,15000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GROUND_LIGHT,65,15000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ISLAND_LIGHT,65,15000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_MID_POS);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	motorOff();
	 
	//TIME 2:38
	SlaveCtrlAPI::waitTill(toMillis(2,38));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, HOLOGRAPHIC_LIGHT, 50, 5000);
	
	//TIME 2:41
	SlaveCtrlAPI::waitTill(toMillis(2,41));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ATMOSPHERIC_LIGHT_R,127,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ATMOSPHERIC_LIGHT_G,85,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ATMOSPHERIC_LIGHT_B,0,5000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_SCREEN_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, _b2SCREEN);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_WAIST_PNEUMATIC, _c2SCREEN);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_ELBOW_PNEUMATIC, DOWN);
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::irSlaveCommand(HOLOGRAM_RIVER, PLAY_VIDEO);
	
	//TIME 2:54
	SlaveCtrlAPI::waitTill(toMillis(2,54));
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_UP_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, UP);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 3:00
	SlaveCtrlAPI::waitTill(toMillis(3,0));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, _b2CHANNA);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, DOWN);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_CHANNA_POS);
	
	//TIME 3:3
	SlaveCtrlAPI::waitTill(toMillis(3,3));
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_WAIST_PNEUMATIC, _c2BUDDHA);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_ELBOW_PNEUMATIC, UP);

	//TIME 3:7
	SlaveCtrlAPI::waitTill(toMillis(3,7));
	SlaveCtrlAPI::mouthStop(CHANNA);
	
	//TIME 3:8
	SlaveCtrlAPI::waitTill(toMillis(3,8));
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 3:13
	SlaveCtrlAPI::waitTill(toMillis(3,13));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	
	//TIME 3:14
	SlaveCtrlAPI::waitTill(toMillis(3,14));
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	
	//TIME 3:23
	SlaveCtrlAPI::waitTill(toMillis(3,23));
	SlaveCtrlAPI::mouthStop(CHANNA);
	
	//TIME 3:24
	SlaveCtrlAPI::waitTill(toMillis(3,24));
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 3:37
	SlaveCtrlAPI::waitTill(toMillis(3,37));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	
	//TIME 3:38
	SlaveCtrlAPI::waitTill(toMillis(3,38));
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	
	//TIME 3:41
	SlaveCtrlAPI::waitTill(toMillis(3,41));
	SlaveCtrlAPI::mouthStop(CHANNA);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_SCREEN_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, _b2SCREEN);
	//SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_WAIST_PNEUMATIC, _c2SCREEN);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_ELBOW_PNEUMATIC, DOWN);
	
	//TIME 3:57
	SlaveCtrlAPI::waitTill(toMillis(3,57));
	SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_UP_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, DOWN);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, UP);
	
	//TIME 4:1
	SlaveCtrlAPI::waitTill(toMillis(4,1));
	SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, _b2CHANNA);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, DOWN);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_CHANNA_POS);
	//SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_WAIST_PNEUMATIC, _c2BUDDHA);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_ELBOW_PNEUMATIC, UP);
	
	//TIME 4:2
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::waitTill(toMillis(4,2));
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	
	//TIME 4:8
	SlaveCtrlAPI::waitTill(toMillis(4,8));
	SlaveCtrlAPI::mouthStop(CHANNA);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 4:11
	SlaveCtrlAPI::waitTill(toMillis(4,11));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	
	//TIME 4:12
	SlaveCtrlAPI::waitTill(toMillis(4,12));
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	
	//TIME 4:16
	SlaveCtrlAPI::waitTill(toMillis(4,16));
	SlaveCtrlAPI::mouthStop(CHANNA);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 4:20
	SlaveCtrlAPI::waitTill(toMillis(4,20));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	
	//TIME 4:21
	SlaveCtrlAPI::waitTill(toMillis(4,21));
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	
	//TIME 4:24
	SlaveCtrlAPI::waitTill(toMillis(4,24));
	SlaveCtrlAPI::mouthStop(CHANNA);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 4:28
	SlaveCtrlAPI::waitTill(toMillis(4,28));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, _b2SCREEN);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_SCREEN_POS);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_WAIST_PNEUMATIC, _c2SCREEN);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_ELBOW_PNEUMATIC, DOWN);
	
	//TIME 4:36
	SlaveCtrlAPI::waitTill(toMillis(4,36));
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, UP);
	
	//TIME 4:43
	SlaveCtrlAPI::waitTill(toMillis(4,43));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, DOWN);
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, _b2CHANNA);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, DOWN);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_CHANNA_POS);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_WAIST_PNEUMATIC, _c2BUDDHA);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_ELBOW_PNEUMATIC, UP);
	
	//TIME 4:53
	SlaveCtrlAPI::waitTill(toMillis(4,53));
	SlaveCtrlAPI::mouthStop(CHANNA);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 4:59
	SlaveCtrlAPI::waitTill(toMillis(4,59));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	
	//TIME 5:00
	SlaveCtrlAPI::waitTill(toMillis(05,0));
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	
	//TIME 5:14
	SlaveCtrlAPI::waitTill(toMillis(5,14));
	SlaveCtrlAPI::mouthStop(CHANNA);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 5:20
	SlaveCtrlAPI::waitTill(toMillis(5,20));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	
	//TIME 5:21
	SlaveCtrlAPI::waitTill(toMillis(5,21));
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	
	//TIME 5:30
	SlaveCtrlAPI::waitTill(toMillis(5,30));
	SlaveCtrlAPI::mouthStop(CHANNA);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, HOLOGRAPHIC_LIGHT, 0,5000);
	
	
	//TIME 5:31
	SlaveCtrlAPI::waitTill(toMillis(5,31));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 5,24000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 5,24000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_B, 0,24000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 0,24000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,GROUND_LIGHT,0,24000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,ISLAND_LIGHT,0,24000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, MOTOR_LIGHT, 100,30000);
	SlaveCtrlAPI::lightInstantWrite(LIGHT_CONTROLLER, FAN_MOTOR, 127);
	motorOn();
	
	//TIME 5:44
	SlaveCtrlAPI::waitTill(toMillis(5,44));
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 6:24
	SlaveCtrlAPI::waitTill(toMillis(6,24));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, CHANNA_FOCUS_LIGHT, 0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, TREE_FOCUS_LIGHT, 0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, MOTOR_LIGHT, 0,10000);
	SlaveCtrlAPI::lightInstantWrite(LIGHT_CONTROLLER, FAN_MOTOR, 0);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, _b2SCREEN);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_SCREEN_POS);
	//SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_WAIST_PNEUMATIC, _c2SCREEN);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_ELBOW_PNEUMATIC, DOWN);
	
	//TIME 6:38
	SlaveCtrlAPI::waitTill(toMillis(6,38));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 110,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 80,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_B, 60,5000);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, DOWN);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, HOLOGRAPHIC_LIGHT, 100,5000);
	
	//TIME 6:42
	SlaveCtrlAPI::waitTill(toMillis(6,42));
	SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_UP_POS);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, UP);

	//TIME 6:47
	SlaveCtrlAPI::waitTill(toMillis(6,47));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_UP_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, _b2CHANNA);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_ELBOW_PNEUMATIC, DOWN);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_CHANNA_POS);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_WAIST_PNEUMATIC, _c2BUDDHA);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_ELBOW_PNEUMATIC, UP);

	//TIME 6:48
	SlaveCtrlAPI::waitTill(toMillis(6,48));
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	
	//TIME 6:50
	SlaveCtrlAPI::waitTill(toMillis(6,50));
	SlaveCtrlAPI::mouthStop(CHANNA);
	
	//TIME 6:51
	SlaveCtrlAPI::waitTill(toMillis(6,51));
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 6:52
	SlaveCtrlAPI::waitTill(toMillis(6,52));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	
	//TIME 6:53
	SlaveCtrlAPI::waitTill(toMillis(6,53));
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	
	//TIME 7:04
	SlaveCtrlAPI::waitTill(toMillis(7,4));
	SlaveCtrlAPI::mouthStop(CHANNA);
	
	//TIME 7:06
	SlaveCtrlAPI::waitTill(toMillis(7,6));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 20, 15000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 10, 15000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_B, 110, 15000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, HOLOGRAPHIC_LIGHT, 0,5000);
	
	//TIME 7:26
	SlaveCtrlAPI::waitTill(toMillis(7,26));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_B, 0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AUDIENCE_LIGHT, 127,5000);
	
	//TIME 7:35
	SlaveCtrlAPI::waitTill(toMillis(7,35));
	motorOn();
	ampStop();
	SlaveCtrlAPI::irSlaveCommand(HOLOGRAM_DURBAR, RECONFIGURE);
	SlaveCtrlAPI::irSlaveCommand(HOLOGRAM_RIVER, RECONFIGURE);
}

#endif /* ROOM4_H_ */