/*
 * room7.h
 *
 * Created: 1/26/2020 1:47:14 PM
 *  Author: Rishav and Ant
 */ 


#ifndef ROOM7_H_
#define ROOM7_H_

#include "../includes.h"

//slaves
#define NO_OF_SLAVES 3
#define LIGHT_CONTROLLER 0x45
#define ANGULIMAL 0x47
#define BUDDHA 0x46
#define DMX 0x48

//amp_volume (max:32)
#define VOLUME 20

//command address
#define PNEUMATIC_WRITE_ADDR 1053
#define HOLOGRAM_WRITE_ADDR 1055
#define SERVO_WRITE_ADDR 1057
#define MOUTH_START_WRITE_ADDR 1060
#define MOUTH_STOP_WRITE_ADDR 1063

//lights
#define AUDIENCE_LIGHT R2
#define BUDDHA_FOCUS_LIGHT R1
#define KOUNDAL_FOCUS_LIGHT B1
#define RISHI_FOCUS_LIGHT G2
#define ANGULIMAL_FOCUS_LIGHT G1
#define ATMOSPHERIC_LIGHT 22
#define ATMOSPHERIC_LIGHT_R 22
#define ATMOSPHERIC_LIGHT_G 22
#define ATMOSPHERIC_LIGHT_B 22


//servo id
#define MOUTH_SERVO 1
#define NECK_SERVO 2
#define SHOULDER_SERVO 3
#define WRIST_SERVO 4
#define HAND_SERVO 5
#define RIGHT_HAND_SERVO 4

//Buddha pneumatic id
#define BUDDHA_RIGHT_ELBOW L3
#define BUDDHA_LEFT_ELBOW R3
#define BUDDHA_RIGHT_ARM L2
#define BUDDHA_LEFT_ARM L1
#define BUDDHA_WAIST_PNEUMATIC R4
#define BUDDHA_LEG G2
#define ANGULIMAL_WAIST_NEUMATIC 4

//rishi pneumatic id 
//(left to right as seen from Buddha)
#define RISHI_ONE R2
#define RISHI_TWO G4
#define RISHI_THREE R1
#define RISHI_FOUR G1
#define RISHI_FIVE B3
 
//Servo positions
#define BUDDHA_MOUTH_UP_POS 718
#define BUDDHA_MOUTH_DOWN_POS 540
#define ANGULIMAL_MOUTH_UP_POS 550
#define ANGULIMAL_MOUTH_DOWN_POS 680
#define BUDDHA_NECK_LEFT_POS 594
#define BUDDHA_NECK_RIGHT_POS 750
#define BUDDHA_NECK_MID_POS 694
#define BUDDHA_PALM_UP_POS 420
#define BUDDHA_PALM_DOWN_POS 654
#define BUDDHA_NADI_RIGHT_UP_POS 470
#define BUDDHA_NADI_RIGHT_DOWN_POS 677
#define BUDDHA_NADI_LEFT_UP_POS 0
#define BUDDHA_NADI_LEFT_DOWN_POS 220


#define ON 1
#define OFF 0
#define UP 1
#define DOWN 0

void resetToInitial(){
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,0,6000);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ELBOW, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_LEFT_ELBOW, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_ONE, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_TWO, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_THREE, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_FOUR, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_FIVE, ON);
}

void playScript(){
	//TIME 0:0
	SlaveCtrlAPI::waitTill(toMillis(0,0));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,0,7000);
	//DMX 9933cc (purple value) 20 second for 1 round ko speed
	SlaveCtrlAPI::dmxSweepAngle(DMX, PAN_MOTOR, 45, 255);
	SlaveCtrlAPI::dmxSunStart(DMX);
	//speed slow
	
	//TIME 1:06
	SlaveCtrlAPI::waitTill(toMillis(1,6));
	//DMX
	SlaveCtrlAPI::dmxSunStop(DMX);
	
	//TIME 1:39
	SlaveCtrlAPI::waitTill(toMillis(1,39));
	SlaveCtrlAPI::dmxSweepAngle(DMX, PAN_MOTOR, 25, 255);
	SlaveCtrlAPI::dmxSweepAngle(DMX, TILT_MOTOR, 25, 255);
	SlaveCtrlAPI::dmxColour(DMX, 0xFF, 0xFF, 0x66, CONSTANT);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, RISHI_FOCUS_LIGHT, 127, 4000);
	
	//TIME 1:41
	SlaveCtrlAPI::waitTill(toMillis(1,41));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 127, 4000);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 1:42
	SlaveCtrlAPI::waitTill(toMillis(1,42));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT, 127, 7000);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_ONE, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_TWO, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_THREE, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_FOUR,OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_FIVE,OFF);
	
	//TIME 1:50
	SlaveCtrlAPI::waitTill(toMillis(1,50));
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_ONE, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_TWO, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_THREE, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_FOUR, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_FIVE, ON);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_LEFT_POS);
	_delay_ms(4000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_RIGHT_POS);
	_delay_ms(4000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_MID_POS);
	
	//TIME 2:35
	SlaveCtrlAPI::waitTill(toMillis(2,35));
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_LEFT_POS);
	_delay_ms(4000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_RIGHT_POS);
	_delay_ms(4000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_MID_POS);
	
	//TIME 3:05
	SlaveCtrlAPI::waitTill(toMillis(3,5));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, KOUNDAL_FOCUS_LIGHT, 127, 5000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_RIGHT_POS);
	
	//TIME 3:14
	SlaveCtrlAPI::waitTill(toMillis(3,14));
	SlaveCtrlAPI::dmxColour(DMX, 0xCC, 0x00, 0x00, CONSTANT);
	SlaveCtrlAPI::dmxSweepAngle(DMX, PAN_MOTOR, 90, 150);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, KOUNDAL_FOCUS_LIGHT, 0, 6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, RISHI_FOCUS_LIGHT, 0, 6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 0, 6000);
		
	//TIME 3:15
	SlaveCtrlAPI::waitTill(toMillis(3,15));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	
	//TIME 3:38
	SlaveCtrlAPI::waitTill(toMillis(3,8));
	SlaveCtrlAPI::dmxSweepAngle(DMX, PAN_MOTOR, 0, 150);
	SlaveCtrlAPI::dmxSweepAngle(DMX, TILT_MOTOR, 0, 150);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, ON);
	//DMX focuses red behind angulimal
	
	//TIME 3:41
	SlaveCtrlAPI::waitTill(toMillis(3,42));
	SlaveCtrlAPI::dmxColour(DMX, 0xCC, 0x00, 0x00, STROBE);
	//DMX flashed until 3:46
	_delay_ms(2000);
	SlaveCtrlAPI::dmxColour(DMX, 0xCC, 0x00, 0x00, CONSTANT);
	_delay_ms(1000);
	SlaveCtrlAPI::dmxColour(DMX, 0xCC, 0x00, 0x00, STROBE);
	_delay_ms(2000);
	
	//TIME 3:46
	SlaveCtrlAPI::waitTill(toMillis(3,46));
	SlaveCtrlAPI::dmxColour(DMX, 0xCC, 0x00, 0x00, CONSTANT);
	//DMX focuses red on angulimal
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 100, 5000);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	
	//TIME 3:54
	SlaveCtrlAPI::waitTill(toMillis(3,54));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 100, 6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 127, 5000);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 4:05
	SlaveCtrlAPI::waitTill(toMillis(4,5));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	
	//TIME 4:13
	SlaveCtrlAPI::waitTill(toMillis(4,13));
	SlaveCtrlAPI::mouthStop(ANGULIMAL);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 4:30
	SlaveCtrlAPI::waitTill(toMillis(4,30));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	
	//TIME 4:39
	SlaveCtrlAPI::waitTill(toMillis(4,39));
	SlaveCtrlAPI::mouthStop(ANGULIMAL);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 5:25
	SlaveCtrlAPI::waitTill(toMillis(5,25));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::dmxColour(DMX, 0xFF, 0xCC, 0x00, CONSTANT);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	
	//TIME 5:50
	SlaveCtrlAPI::waitTill(toMillis(5,50));
	SlaveCtrlAPI::mouthStop(ANGULIMAL);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 6:00
	SlaveCtrlAPI::waitTill(toMillis(6,0));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	
	//TIME 6:13
	SlaveCtrlAPI::waitTill(toMillis(6,13));
	SlaveCtrlAPI::mouthStop(ANGULIMAL);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);

	
	//TIME 6:37
	SlaveCtrlAPI::waitTill(toMillis(6,37));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	
	//TIME 6:39
	SlaveCtrlAPI::waitTill(toMillis(6,39));
	SlaveCtrlAPI::dmxColour(DMX, 0x00, 0xCC, 0xFF, CONSTANT);
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, ON);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	
	//TIME 7:08
	SlaveCtrlAPI::waitTill(toMillis(7,8));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT, 127, 7000);
	
	//TIME 7:08
	SlaveCtrlAPI::waitTill(toMillis(7,8));
	//RIGHT_hand_uthaune
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ELBOW, ON);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_HAND_SERVO, BUDDHA_PALM_UP_POS);
	
	//TIME 7:28
	SlaveCtrlAPI::waitTill(toMillis(7,28));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 0, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT, 0, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AUDIENCE_LIGHT, 127,7000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_HAND_SERVO, BUDDHA_PALM_DOWN_POS);
	ampStopAudio();	
}

#endif