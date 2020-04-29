/*
 * room5.h
 *
 * Created: 1/26/2020 1:46:29 PM
 *  Author: Ant
 */ 

#ifndef ROOM5_H_
#define ROOM5_H_

#include "../includes.h"

//slaves
#define NO_OF_SLAVES 4
#define LIGHT_CONTROLLER 0x45
#define SIDDHARTHA 0x46
#define CHANNA 0x47
#define DURBAR_HOLOGRAM 0x48

//amp_volume (max:32)
#define VOLUME 17

//Lights
#define AUDIENCE_LIGHT			L2
#define DURBAR_FOCUS_LIGHT		L4
#define KING_ROOM_LIGHT			R2
#define ATMOSPHERIC_LIGHT_R		R1
#define ATMOSPHERIC_LIGHT_G		G1
#define ATMOSPHERIC_LIGHT_B		B1
#define HORSE_FOCUS_LIGHT		L1
#define SIDDHARTHA_FOCUS_LIGHT	R4
#define BACKGROUND_GREEN_LIGHT  G4

//Holograms
#define HOLOGRAM_LED 1

//Servo Id
#define MOUTH_SERVO 1
#define NECK_SERVO 2
#define LEFT_HAND_SERVO 3
#define RIGHT_HAND_SERVO 4

//Pneumatic Id
#define SIDDHARTHA_ELBOW_PNEUMATIC 2
#define SIDDHARTHA_WAIST_PNEUMATIC 4
#define CHANNA_HEAD_PNEUMATIC 3
#define CHANNA_ELBOW_PNEUMATIC 4
#define HORSE_PNNEUMATIC 3

//Servo positions
#define CHANNA_MOUTH_UP_POS 0
#define CHANNA_MOUTH_DOWN_POS 170
#define SIDDHARTHA_MOUTH_UP_POS 0
#define SIDDHARTHA_MOUTH_DOWN_POS 170

#define CHANNA_RIGHT_HAND_UP_POS 400
#define CHANNA_RIGHT_HAND_DOWN_POS 550
#define CHANNA_LEFT_HAND_UP_POS 500
#define CHANNA_LEFT_HAND_DOWN_POS 650

#define ON 1
#define OFF 0

void resetToInitial(){
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,127,6000);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_HEAD_PNEUMATIC, OFF);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_ELBOW_PNEUMATIC, OFF);
	SlaveCtrlAPI::pneumaticWrite(SIDDHARTHA, SIDDHARTHA_WAIST_PNEUMATIC, OFF);
	SlaveCtrlAPI::pneumaticWrite(SIDDHARTHA, SIDDHARTHA_ELBOW_PNEUMATIC, OFF);
	SlaveCtrlAPI::pneumaticWrite(SIDDHARTHA, HORSE_PNNEUMATIC, OFF);
	motorOn();
	for(int i=0; i<2; i++){
		
		SlaveCtrlAPI::servoPosWrite(CHANNA, LEFT_HAND_SERVO, CHANNA_LEFT_HAND_DOWN_POS);
		SlaveCtrlAPI::servoPosWrite(CHANNA, RIGHT_HAND_SERVO, CHANNA_RIGHT_HAND_DOWN_POS);
		_delay_ms(2000);
	}
}

void playScript(){
	//TIME 0:0
	SlaveCtrlAPI::waitTill(toMillis(0,0));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AUDIENCE_LIGHT, 0, 7000);
	SlaveCtrlAPI::irSlaveCommand(DURBAR_HOLOGRAM, PLAY_VIDEO);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, DURBAR_FOCUS_LIGHT, 20, 7000);
	
	//TIME 0:24
	SlaveCtrlAPI::waitTill(toMillis(0,24));
	
	for(int i=0; i<12; i++){
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, KING_ROOM_LIGHT, 15, 7000);
		_delay_ms(5000);
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, KING_ROOM_LIGHT, 7, 7000);
		_delay_ms(5000);
	}
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, KING_ROOM_LIGHT, 15, 7000);
	
	//TIME 3:00
	SlaveCtrlAPI::waitTill(toMillis(3,00));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, KING_ROOM_LIGHT, 0, 12000);
	
	//TIME 4:35
	SlaveCtrlAPI::waitTill(toMillis(4,35));
	motorOff();
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, DURBAR_FOCUS_LIGHT, 0, 10000);
	
	//TIME 4:50
	SlaveCtrlAPI::waitTill(toMillis(4,50));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 75, 10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 75, 10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_B, 107, 10000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BACKGROUND_GREEN_LIGHT, 10, 10000);
	
	//TIME 4:52
	SlaveCtrlAPI::waitTill(toMillis(4,52));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, SIDDHARTHA_FOCUS_LIGHT, 40, 8000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, HORSE_FOCUS_LIGHT, 40, 8000);
	SlaveCtrlAPI::pneumaticWrite(SIDDHARTHA, HORSE_PNNEUMATIC, ON);
	SlaveCtrlAPI::mouthStart(SIDDHARTHA, SIDDHARTHA_MOUTH_UP_POS, SIDDHARTHA_MOUTH_DOWN_POS);
	
	//TIME 5:04
	SlaveCtrlAPI::waitTill(toMillis(5,04));
	SlaveCtrlAPI::pneumaticWrite(SIDDHARTHA, HORSE_PNNEUMATIC, OFF);
	SlaveCtrlAPI::mouthStart(SIDDHARTHA, SIDDHARTHA_MOUTH_UP_POS, SIDDHARTHA_MOUTH_DOWN_POS);
	
	//TIME 5:34
	SlaveCtrlAPI::waitTill(toMillis(5,34));
	SlaveCtrlAPI::mouthStop(SIDDHARTHA);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_HEAD_PNEUMATIC, ON);
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(SIDDHARTHA, HORSE_PNNEUMATIC, ON);
	
	//TIME 5:55
	SlaveCtrlAPI::waitTill(toMillis(5,55));
	SlaveCtrlAPI::mouthStop(CHANNA);
	SlaveCtrlAPI::mouthStart(SIDDHARTHA, SIDDHARTHA_MOUTH_UP_POS, SIDDHARTHA_MOUTH_DOWN_POS);
	
	//TIME 5:55
	SlaveCtrlAPI::waitTill(toMillis(5,55));
	SlaveCtrlAPI::pneumaticWrite(SIDDHARTHA, SIDDHARTHA_WAIST_PNEUMATIC, ON);
	SlaveCtrlAPI::pneumaticWrite(SIDDHARTHA, SIDDHARTHA_ELBOW_PNEUMATIC, ON);
	
	//TIME 6:05
	SlaveCtrlAPI::waitTill(toMillis(6,05));
	SlaveCtrlAPI::mouthStop(SIDDHARTHA);
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::servoPosWrite(CHANNA, LEFT_HAND_SERVO, CHANNA_LEFT_HAND_UP_POS);
	SlaveCtrlAPI::servoPosWrite(CHANNA, RIGHT_HAND_SERVO, CHANNA_RIGHT_HAND_UP_POS);
	SlaveCtrlAPI::pneumaticWrite(CHANNA, CHANNA_ELBOW_PNEUMATIC, ON);
	
	//TIME 6:14
	SlaveCtrlAPI::waitTill(toMillis(6,14));
	SlaveCtrlAPI::pneumaticWrite(SIDDHARTHA, HORSE_PNNEUMATIC, OFF);
	SlaveCtrlAPI::mouthStop(CHANNA);
	SlaveCtrlAPI::mouthStart(SIDDHARTHA, SIDDHARTHA_MOUTH_UP_POS, SIDDHARTHA_MOUTH_DOWN_POS);
	
	//TIME 6:38
	SlaveCtrlAPI::waitTill(toMillis(6,38));
	SlaveCtrlAPI::mouthStop(SIDDHARTHA);
	SlaveCtrlAPI::mouthStart(CHANNA, CHANNA_MOUTH_UP_POS, CHANNA_MOUTH_DOWN_POS);
	
	//TIME 6:47
	SlaveCtrlAPI::waitTill(toMillis(6,47));
	SlaveCtrlAPI::mouthStop(CHANNA);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 127, 5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 107, 5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_B, 0, 5000);
	
	//TIME 6:54
	SlaveCtrlAPI::waitTill(toMillis(6,54));
	SlaveCtrlAPI::mouthStart(SIDDHARTHA, SIDDHARTHA_MOUTH_UP_POS, SIDDHARTHA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(SIDDHARTHA, HORSE_PNNEUMATIC, ON);
	
	//TIME 7:05
	SlaveCtrlAPI::waitTill(toMillis(7,05));
	SlaveCtrlAPI::mouthStop(SIDDHARTHA);
	
	//TIME 7:25
	SlaveCtrlAPI::waitTill(toMillis(7,25));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 0, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 0, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_B, 0, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, SIDDHARTHA_FOCUS_LIGHT, 0, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BACKGROUND_GREEN_LIGHT, 0, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, HORSE_FOCUS_LIGHT, 0, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AUDIENCE_LIGHT, 127, 7000);
	SlaveCtrlAPI::irSlaveCommand(DURBAR_HOLOGRAM, RECONFIGURE);
	
	
	//TIME 7:27
	SlaveCtrlAPI::waitTill(toMillis(7,27));
	ampStopAudio();
	motorOn();
}

#endif /* ROOM5_H_ */