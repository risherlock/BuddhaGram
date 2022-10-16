/*
 * room2.h
 *
 * Created: 1/26/2020 1:46:08 PM
 *  Author: Ant
 */ 


#ifndef ROOM2_H_
#define ROOM2_H_

#include "../includes.h"

//slaves
#define NO_OF_SLAVES 4
#define KING 0x46
#define RISHI 0x47
#define PROJECTOR 0x48
#define LIGHT_CONTROLLER 0x45

//amp_volume (max:32)
#define VOLUME 27

//Lights
#define QUEEN_FOCUS_LIGHT B1
#define QUEEN_PET_LIGHT L1
#define RISHI_FOCUS_LIGHT L2
#define KING_FOCUS_LIGHT L3
#define WINDOW_RISHI_LIGHT R1
#define WINDOW_KING_LIGHT G1
#define BACKGROUND_R R4
#define BACKGROUND_G G4
#define BACKGROUND_B B4
#define AUDIENCE_LIGHT G2
#define WARM_LIGHT L4
#define BOARDER_R R3
#define BOARDER_G G3
#define BOARDER_B B3
#define TEMPLE_LIGHT B2
#define DIYO R2

//Servo Id
#define MOUTH_SERVO 1
#define NECK_SERVO 2
#define SHOULDER_SERVO 3
#define WRIST_SERVO 4
#define HAND_SERVO 5
#define HAND_SERVO_2 6

//Pneumatic Id
#define KING_ELBOW_PNEUMATIC 3
#define KING_WAIST_PNEUMATIC 4
#define RISHI_HEAD_PNEUMATIC 3
#define RISHI_ELBOW_PNEUMATIC 1
#define RISHI_WAIST_PNEUMATIC 2
#define BUDDHA_LEG_PNEUMATIC 4

//Servo positions
#define KING_MOUTH_UP_POS 450
#define KING_MOUTH_DOWN_POS 300
#define KING_WRIST_UP_POS 390
#define KING_WRIST_DOWN_POS 715
#define RISHI_MOUTH_UP_POS 640
#define RISHI_MOUTH_DOWN_POS 540
#define SIDDHARTHA_HAND_UP_POS 340
#define SIDDHARTHA_HAND_DOWN_POS 645
#define SIDDHARTHA_HAND2_UP_POS 340
#define SIDDHARTHA_HAND2_DOWN_POS 645
#define KING_NECK_LEFT_POSITION 333
#define KING_NECK_RIGHT_POSITION 423
#define KING_NECK_MID_POSITION 380

#define ON 1
#define OFF 0

void resetToInitial(){
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,127,5000);
	SlaveCtrlAPI::lightInstantWrite(LIGHT_CONTROLLER,TEMPLE_LIGHT,127);
	
	SlaveCtrlAPI::servoPosWrite(RISHI, HAND_SERVO, SIDDHARTHA_HAND_DOWN_POS);
	SlaveCtrlAPI::servoPosWrite(KING,NECK_SERVO,KING_NECK_RIGHT_POSITION);
	SlaveCtrlAPI::pneumaticWrite(KING,KING_ELBOW_PNEUMATIC,OFF);
	SlaveCtrlAPI::pneumaticWrite(KING,KING_WAIST_PNEUMATIC,OFF);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_ELBOW_PNEUMATIC,OFF);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);
	SlaveCtrlAPI::pneumaticWrite(RISHI,BUDDHA_LEG_PNEUMATIC,OFF);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_WAIST_PNEUMATIC, OFF);
		
}

void playScript(){
	//TIME 0:0
	SlaveCtrlAPI::waitTill(toMillis(0,0));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,0,5000);
	SlaveCtrlAPI::lightInstantWrite(LIGHT_CONTROLLER,TEMPLE_LIGHT,0);
	SlaveCtrlAPI::lightInstantWrite(LIGHT_CONTROLLER,DIYO,127);
	
	//TIME 0:30
	SlaveCtrlAPI::waitTill(toMillis(0,30));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,QUEEN_FOCUS_LIGHT,20,15000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,QUEEN_PET_LIGHT,80,1000);
	SlaveCtrlAPI::irSlaveCommand(PROJECTOR, PLAY_VIDEO);
	
	//TIME 0:44
	SlaveCtrlAPI::waitTill(toMillis(0,44));
	SlaveCtrlAPI::irSlaveCommand(PROJECTOR, LAMP_ON);//projector on
	
	//TIME 1:10
	SlaveCtrlAPI::waitTill(toMillis(1,10));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,QUEEN_FOCUS_LIGHT,0,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,QUEEN_PET_LIGHT,00,1000);
	
	//TIME 2:02
	SlaveCtrlAPI::waitTill(toMillis(2,02));
	SlaveCtrlAPI::irSlaveCommand(PROJECTOR,LAMP_OFF);    //projector off
	SlaveCtrlAPI::irSlaveCommand(PROJECTOR,RECONFIGURE); //reset for next play
	
	//TIME 2:40
	SlaveCtrlAPI::waitTill(toMillis(2,40));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,WARM_LIGHT,50,10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,WINDOW_RISHI_LIGHT,50,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,WINDOW_KING_LIGHT,50,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BOARDER_R,46,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BOARDER_G,26,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BOARDER_B,12,8000);
	
	//TIME 2:41
	SlaveCtrlAPI::waitTill(toMillis(2,41));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,KING_FOCUS_LIGHT,60,8000);
	SlaveCtrlAPI::mouthStart(KING,KING_MOUTH_UP_POS,KING_MOUTH_DOWN_POS);
	
	//TIME 2:43
	SlaveCtrlAPI::waitTill(toMillis(2,43));
	SlaveCtrlAPI::pneumaticWrite(KING,KING_WAIST_PNEUMATIC,ON);//bow
	
	
	//TIME 2:46
	SlaveCtrlAPI::waitTill(toMillis(2,46));
	SlaveCtrlAPI::pneumaticWrite(KING,KING_ELBOW_PNEUMATIC,ON);
	SlaveCtrlAPI::servoPosWrite(KING, WRIST_SERVO, KING_WRIST_UP_POS);
	
	//TIME 2:48
	SlaveCtrlAPI::waitTill(toMillis(2,48));
	SlaveCtrlAPI::pneumaticWrite(KING,KING_WAIST_PNEUMATIC,OFF);
	
	//TIME 2:50
	SlaveCtrlAPI::waitTill(toMillis(2,50));
	SlaveCtrlAPI::pneumaticWrite(KING,KING_ELBOW_PNEUMATIC,OFF);
	SlaveCtrlAPI::servoPosWrite(KING, WRIST_SERVO, KING_WRIST_DOWN_POS);
	
	//TIME 2:52
	SlaveCtrlAPI::waitTill(toMillis(2,52));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BACKGROUND_R,102,6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BACKGROUND_G,51,6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BACKGROUND_B,0,6000);
	
	//TIME 2:55
	SlaveCtrlAPI::waitTill(toMillis(2,55));
	SlaveCtrlAPI::servoPosWrite(KING, NECK_SERVO, KING_NECK_MID_POSITION);
	
	//TIME 2:56
	SlaveCtrlAPI::waitTill(toMillis(2,56));
	SlaveCtrlAPI::servoPosWrite(KING, NECK_SERVO, KING_NECK_RIGHT_POSITION);
	
	//TIME 3:00
	SlaveCtrlAPI::waitTill(toMillis(3,00));
	SlaveCtrlAPI::pneumaticWrite(KING, KING_ELBOW_PNEUMATIC, ON);
	SlaveCtrlAPI::servoPosWrite(KING, WRIST_SERVO, KING_WRIST_UP_POS);
	SlaveCtrlAPI::mouthStart(KING, KING_MOUTH_UP_POS, KING_MOUTH_DOWN_POS);
	
	
	//TIME 3:05
	SlaveCtrlAPI::waitTill(toMillis(3,05));
	SlaveCtrlAPI::mouthStop(KING);
	SlaveCtrlAPI::pneumaticWrite(KING, KING_ELBOW_PNEUMATIC, OFF);
	SlaveCtrlAPI::servoPosWrite(KING, WRIST_SERVO, KING_WRIST_DOWN_POS);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,RISHI_FOCUS_LIGHT,60,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,KING_FOCUS_LIGHT,0,5000);
	
	//TIME 3:06
	SlaveCtrlAPI::waitTill(toMillis(3,06));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_UP_POS);
	
	//TIME 3:08
	SlaveCtrlAPI::waitTill(toMillis(3,8));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_DOWN_POS);
	
	//TIME 3:09
	SlaveCtrlAPI::waitTill(toMillis(3,9));
	SlaveCtrlAPI::mouthStart(RISHI, RISHI_MOUTH_UP_POS,RISHI_MOUTH_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(RISHI,BUDDHA_LEG_PNEUMATIC, ON);
	
	//TIME 3:11
	SlaveCtrlAPI::waitTill(toMillis(3,11));
	SlaveCtrlAPI::mouthStop(RISHI);
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_UP_POS);
	
	//TIME 3:12
	SlaveCtrlAPI::waitTill(toMillis(3,12));
	SlaveCtrlAPI::pneumaticWrite(RISHI, BUDDHA_LEG_PNEUMATIC, OFF);
	
	//TIME 3:13
	SlaveCtrlAPI::waitTill(toMillis(3,13));
	SlaveCtrlAPI::servoPosWrite(RISHI, HAND_SERVO, SIDDHARTHA_HAND_DOWN_POS);
	
	//TIME 3:15
	SlaveCtrlAPI::waitTill(toMillis(3,15));
	SlaveCtrlAPI::servoPosWrite(RISHI, HAND_SERVO, SIDDHARTHA_HAND_UP_POS);
	SlaveCtrlAPI::pneumaticWrite(RISHI, RISHI_ELBOW_PNEUMATIC, ON);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC, ON);
	
	//TIME 3:18
	SlaveCtrlAPI::waitTill(toMillis(3,18));
	SlaveCtrlAPI::servoPosWrite(RISHI, HAND_SERVO, SIDDHARTHA_HAND_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC, OFF);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_WAIST_PNEUMATIC,OFF);//lowers
	
	//TIME 3:20
	SlaveCtrlAPI::waitTill(toMillis(3,20));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_ELBOW_PNEUMATIC,OFF);
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO, SIDDHARTHA_HAND_UP_POS);
	
	//TIME 3:22
	SlaveCtrlAPI::waitTill(toMillis(3,22));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,ON);
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO, SIDDHARTHA_HAND_DOWN_POS);
	
	//TIME 3:23
	SlaveCtrlAPI::waitTill(toMillis(3,23));
	SlaveCtrlAPI::pneumaticWrite(RISHI,BUDDHA_LEG_PNEUMATIC,ON);
	
	//TIME 3:24
	SlaveCtrlAPI::waitTill(toMillis(3,24));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO, SIDDHARTHA_HAND_UP_POS);
	
	//TIME 3:25
	SlaveCtrlAPI::waitTill(toMillis(3,25));
	
	//TIME 3:26
	SlaveCtrlAPI::waitTill(toMillis(3,26));
	SlaveCtrlAPI::pneumaticWrite(RISHI,BUDDHA_LEG_PNEUMATIC,OFF);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,ON);
	
	//TIME 3:27
	SlaveCtrlAPI::waitTill(toMillis(3,27));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO, SIDDHARTHA_HAND_DOWN_POS);

	//TIME 3:29
	SlaveCtrlAPI::waitTill(toMillis(3,29));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);


	//TIME 3:38
	SlaveCtrlAPI::waitTill(toMillis(3,38));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,KING_FOCUS_LIGHT,60,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,RISHI_FOCUS_LIGHT,0,5000);
	SlaveCtrlAPI::mouthStart(KING,KING_MOUTH_UP_POS,KING_MOUTH_DOWN_POS);
	
	//TIME 3:41
	SlaveCtrlAPI::waitTill(toMillis(3,41));
	
	//TIME 3:46
	SlaveCtrlAPI::waitTill(toMillis(3,46));
	SlaveCtrlAPI::pneumaticWrite(KING, KING_ELBOW_PNEUMATIC, ON);
	SlaveCtrlAPI::pneumaticWrite(RISHI, BUDDHA_LEG_PNEUMATIC, ON);
	SlaveCtrlAPI::mouthStart(KING, KING_MOUTH_UP_POS, KING_MOUTH_DOWN_POS);
	
	//TIME 3:48
	SlaveCtrlAPI::waitTill(toMillis(3,48));
	SlaveCtrlAPI::pneumaticWrite(KING,KING_ELBOW_PNEUMATIC,OFF);
	SlaveCtrlAPI::pneumaticWrite(RISHI,BUDDHA_LEG_PNEUMATIC,OFF);
	SlaveCtrlAPI::servoPosWrite(RISHI, HAND_SERVO, SIDDHARTHA_HAND_UP_POS);
	
	//TIME 3:56
	SlaveCtrlAPI::waitTill(toMillis(3,56));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_WAIST_PNEUMATIC,ON);
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_DOWN_POS);
	SlaveCtrlAPI::servoPosWrite(KING,NECK_SERVO,KING_NECK_MID_POSITION);
	SlaveCtrlAPI::mouthStop(KING);
	
	//TIME 3:58
	SlaveCtrlAPI::waitTill(toMillis(3,58));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,KING_FOCUS_LIGHT,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,RISHI_FOCUS_LIGHT,60,5000);
	SlaveCtrlAPI::mouthStart(RISHI, RISHI_MOUTH_UP_POS, RISHI_MOUTH_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,ON);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_WAIST_PNEUMATIC,ON);
	SlaveCtrlAPI::servoPosWrite(KING,NECK_SERVO,KING_NECK_RIGHT_POSITION);
	
	//TIME 4:08
	SlaveCtrlAPI::waitTill(toMillis(4,8));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);
	
	
	//TIME 4:15
	SlaveCtrlAPI::waitTill(toMillis(4,15));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_UP_POS);
	SlaveCtrlAPI::pneumaticWrite(RISHI, RISHI_ELBOW_PNEUMATIC, ON);
	
	//TIME 4:20
	SlaveCtrlAPI::waitTill(toMillis(4,20));
	SlaveCtrlAPI::pneumaticWrite(RISHI, RISHI_ELBOW_PNEUMATIC, OFF);
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_DOWN_POS);
	
	//TIME 4:24
	SlaveCtrlAPI::waitTill(toMillis(4,24));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,ON);
	
	//TIME 4:38
	SlaveCtrlAPI::waitTill(toMillis(4,38));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);
	
	//TIME 4:41
	SlaveCtrlAPI::waitTill(toMillis(4,41));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,ON);
	
	//TIME 4:45
	SlaveCtrlAPI::waitTill(toMillis(4,45));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_UP_POS);
	
	//TIME 4:51
	SlaveCtrlAPI::waitTill(toMillis(4,51));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_DOWN_POS);
	
	//TIME 5:08
	SlaveCtrlAPI::waitTill(toMillis(5,8));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);
	
	//TIME 5:10
	SlaveCtrlAPI::waitTill(toMillis(5,10));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_WAIST_PNEUMATIC,OFF);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,ON);
	
	//TIME 5:12
	SlaveCtrlAPI::waitTill(toMillis(5,12));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);
	
	//TIME 5:19
	SlaveCtrlAPI::waitTill(toMillis(5,19));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC, ON);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_WAIST_PNEUMATIC,ON);
	
	//TIME 5:21
	SlaveCtrlAPI::waitTill(toMillis(5,21));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_ELBOW_PNEUMATIC,ON);
	
	//TIME 5:23
	SlaveCtrlAPI::waitTill(toMillis(5,31));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_ELBOW_PNEUMATIC,OFF);
	
	//TIME 5:25
	SlaveCtrlAPI::waitTill(toMillis(5,31));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_ELBOW_PNEUMATIC,ON);
	
	//TIME 5:25
	SlaveCtrlAPI::waitTill(toMillis(5,25));
	
	//TIME 5:42
	SlaveCtrlAPI::waitTill(toMillis(5,42));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,KING_FOCUS_LIGHT,60,4000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,RISHI_FOCUS_LIGHT,0,4000);
	SlaveCtrlAPI::mouthStart(KING, KING_MOUTH_UP_POS, KING_MOUTH_DOWN_POS);
	
	//TIME 5:46
	SlaveCtrlAPI::waitTill(toMillis(5,46));
	SlaveCtrlAPI::pneumaticWrite(KING, KING_WAIST_PNEUMATIC, ON);
	
	
	//TIME 5:48
	SlaveCtrlAPI::waitTill(toMillis(5,48));
	SlaveCtrlAPI::mouthStop(RISHI);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,KING_FOCUS_LIGHT,60,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,RISHI_FOCUS_LIGHT,0,5000);
	SlaveCtrlAPI::pneumaticWrite(KING, KING_WAIST_PNEUMATIC, OFF);
	SlaveCtrlAPI::pneumaticWrite(KING, KING_ELBOW_PNEUMATIC, ON);
	SlaveCtrlAPI::servoPosWrite(KING, WRIST_SERVO, KING_WRIST_UP_POS);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);
	
	//TIME 5:50
	SlaveCtrlAPI::waitTill(toMillis(5,50));
	SlaveCtrlAPI::servoPosWrite(KING, WRIST_SERVO, KING_WRIST_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(KING, KING_ELBOW_PNEUMATIC, OFF);
	_delay_ms(1000);
	SlaveCtrlAPI::servoPosWrite(KING, NECK_SERVO, KING_NECK_MID_POSITION);
	
	//TIME 5:53	
	SlaveCtrlAPI::waitTill(toMillis(5,53));
	SlaveCtrlAPI::servoPosWrite(KING, NECK_SERVO, KING_NECK_RIGHT_POSITION);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,KING_FOCUS_LIGHT,0,5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,RISHI_FOCUS_LIGHT,60,5000);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);
	SlaveCtrlAPI::mouthStart(RISHI,RISHI_MOUTH_UP_POS,RISHI_MOUTH_DOWN_POS);
	SlaveCtrlAPI::mouthStop(KING);
	
	//TIME 6:08
	SlaveCtrlAPI::waitTill(toMillis(6,8));
	SlaveCtrlAPI::mouthStop(RISHI);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,ON);
	
	//TIME 6:10
	SlaveCtrlAPI::waitTill(toMillis(6,10));
	
	//TIME 6:15
	SlaveCtrlAPI::waitTill(toMillis(6,15));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_UP_POS);
	
	//TIME 6:20
	SlaveCtrlAPI::waitTill(toMillis(6,20));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_DOWN_POS);
	
	//TIME 6:22
	SlaveCtrlAPI::waitTill(toMillis(6,22));
	SlaveCtrlAPI::pneumaticWrite(RISHI,BUDDHA_LEG_PNEUMATIC,ON);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_WAIST_PNEUMATIC,ON);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,ON);
	
	//TIME 6:24
	SlaveCtrlAPI::waitTill(toMillis(6,24));
	SlaveCtrlAPI::pneumaticWrite(RISHI,BUDDHA_LEG_PNEUMATIC,OFF);
	
	//TIME 6:25
	SlaveCtrlAPI::waitTill(toMillis(6,25));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_UP_POS);
	
	//TIME 6:27
	SlaveCtrlAPI::waitTill(toMillis(6,27));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_DOWN_POS);
	
	//TIME 6:28
	SlaveCtrlAPI::waitTill(toMillis(6,28));
	SlaveCtrlAPI::pneumaticWrite(RISHI,BUDDHA_LEG_PNEUMATIC, ON);
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_UP_POS);
	
	//TIME 6:30
	SlaveCtrlAPI::waitTill(toMillis(6,30));
	SlaveCtrlAPI::pneumaticWrite(RISHI,BUDDHA_LEG_PNEUMATIC,OFF);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_WAIST_PNEUMATIC,ON);
	
	//TIME 6:32
	SlaveCtrlAPI::waitTill(toMillis(6,32));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_WAIST_PNEUMATIC,OFF);
	
	//TIME 6:45 
	SlaveCtrlAPI::waitTill(toMillis(6,45));
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_HEAD_PNEUMATIC,OFF);
	SlaveCtrlAPI::pneumaticWrite(RISHI,RISHI_WAIST_PNEUMATIC,ON);
	
	//TIME 6:49
	SlaveCtrlAPI::waitTill(toMillis(6,49));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,RISHI_FOCUS_LIGHT,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,WARM_LIGHT,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BOARDER_R,40,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BOARDER_G,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BOARDER_B,120,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BACKGROUND_R,40,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BACKGROUND_G,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BACKGROUND_B,120,7000);
	SlaveCtrlAPI::mouthStop(RISHI);
	
	//TIME 6:50
	SlaveCtrlAPI::waitTill(toMillis(6,50));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_UP_POS);
	
	//TIME 6:52
	SlaveCtrlAPI::waitTill(toMillis(6,52));
	SlaveCtrlAPI::servoPosWrite(RISHI,HAND_SERVO,SIDDHARTHA_HAND_DOWN_POS);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,WINDOW_KING_LIGHT,0,8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,WINDOW_RISHI_LIGHT,0,8000);
	
	//TIME 6:58
	SlaveCtrlAPI::waitTill(toMillis(6,58));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,DIYO,0,2000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,WARM_LIGHT,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,KING_FOCUS_LIGHT,45,7000);
	
	
	//TIME 7:06
	SlaveCtrlAPI::waitTill(toMillis(7,06));
	SlaveCtrlAPI::servoPosWrite(KING,NECK_SERVO,KING_NECK_LEFT_POSITION);
	SlaveCtrlAPI::pneumaticWrite(KING,KING_WAIST_PNEUMATIC,ON);//straight
	
	//TIME 7:20
	SlaveCtrlAPI::waitTill(toMillis(7,20));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,KING_FOCUS_LIGHT,0,8000);
	
	//TIME 7:22
	SlaveCtrlAPI::waitTill(toMillis(7,22));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BACKGROUND_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BACKGROUND_G,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BACKGROUND_B,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BOARDER_R,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BOARDER_G,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,BOARDER_B,0,7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WINDOW_KING_LIGHT,0,0);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, WINDOW_RISHI_LIGHT,0,0);
	
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,127,5000);
	SlaveCtrlAPI::lightInstantWrite(LIGHT_CONTROLLER,TEMPLE_LIGHT,127);
	
	//TIME 7:30
	SlaveCtrlAPI::waitTill(toMillis(7,30));
	ampStop();
	SlaveCtrlAPI::servoPosWrite(KING,NECK_SERVO,KING_NECK_RIGHT_POSITION);
}
#endif /* ROOM2_H_ */