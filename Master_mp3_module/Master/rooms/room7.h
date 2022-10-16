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
#define NO_OF_SLAVES 4
#define LIGHT_CONTROLLER 0x45
#define ANGULIMAL 0x47
#define BUDDHA 0x46
#define DMX 0x48

//amp_volume (max:32)
#define VOLUME 27

//command address
#define PNEUMATIC_WRITE_ADDR 1053
#define HOLOGRAM_WRITE_ADDR 1055
#define SERVO_WRITE_ADDR 1057
#define MOUTH_START_WRITE_ADDR 1060
#define MOUTH_STOP_WRITE_ADDR 1063

//lights
#define AUDIENCE_LIGHT R2
#define BUDDHA_FOCUS_LIGHT G1
#define KOUNDAL_FOCUS_LIGHT B2
#define RISHI_FOCUS_LIGHT G2
#define ANGULIMAL_FOCUS_LIGHT B1
#define ATMOSPHERIC_LIGHT L2
#define ATMOSPHERIC_LIGHT_R L1
#define ATMOSPHERIC_LIGHT_G L3
#define ATMOSPHERIC_LIGHT_B L4 

//servo id
#define MOUTH_SERVO 1
#define NECK_SERVO 2
#define HAND_SERVO 3
#define RIGHT_WRIST_SERVO 4
#define LEFT_WRIST_SERVO 5

#define BUDDHA_RIGHT_ELBOW G1
#define BUDDHA_LEFT_ELBOW R1
#define BUDDHA_RIGHT_ARM B2
#define BUDDHA_LEFT_ARM B1
#define	BUDDHA_WAIST_PNEUMATIC G3
#define BUDDHA_STAND G2

//Rishi pneumatic id 
//(left to right as seen from Buddha)
#define RISHI_ONE L1
#define RISHI_TWO L2
#define RISHI_THREE R3
#define RISHI_FOUR B3
#define RISHI_FIVE L4
 
//Servo positions
#define BUDDHA_MOUTH_UP_POS 829
#define BUDDHA_MOUTH_DOWN_POS 459
#define ANGULIMAL_MOUTH_UP_POS 550
#define ANGULIMAL_MOUTH_DOWN_POS 680
#define BUDDHA_NECK_LEFT_POS 475
#define BUDDHA_NECK_RIGHT_POS 590
#define BUDDHA_NECK_EXRIGHT_POS 700
#define BUDDHA_NECK_MID_POS 590
#define BUDDHA_HAND_UP_POS 435
#define BUDDHA_HAND_DOWN_POS 720
#define BUDDHA_RIGHT_WRIST_UP_POS 250
#define BUDDHA_RIGHT_WRIST_DOWN_POS 610
#define BUDDHA_LEFT_WRIST_UP_POS 370
#define BUDDHA_LEFT_WRIST_DOWN_POS 0

//Angulimal
#define ANGULIMAL_WAIST_NEUMATIC 4

#define ON 1
#define OFF 0
#define UP 1
#define DOWN 0

void resetToInitial(){
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,127,6000);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ELBOW, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_LEFT_ELBOW, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ARM, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_LEFT_ARM, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_STAND, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_ONE, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_TWO, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_THREE, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_FOUR, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_FIVE, OFF);
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::mouthStop(ANGULIMAL);
	SlaveCtrlAPI::dmxColour(DMX, 0x00, 0x00, 0x00, CONSTANT);
	SlaveCtrlAPI::dmxSweepAngle(DMX, PAN_MOTOR, 00, 100);
	SlaveCtrlAPI::dmxSweepAngle(DMX, TILT_MOTOR, 00, 100);
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, OFF);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_MID_POS);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_DOWN_POS);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_WRIST_SERVO, BUDDHA_RIGHT_WRIST_DOWN_POS);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, LEFT_WRIST_SERVO, BUDDHA_LEFT_WRIST_DOWN_POS);
}

void playScript(){
	//TIME 0:0
	SlaveCtrlAPI::waitTill(toMillis(0,0));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,0,7000);
	SlaveCtrlAPI::dmxSweepAngle(DMX, PAN_MOTOR, 180, 50);
	SlaveCtrlAPI::dmxSweepAngle(DMX, TILT_MOTOR, 00, 50);
	SlaveCtrlAPI::dmxColour(DMX, 0x22, 0x22, 0x44, CONSTANT);
	//DMX 9933cc (purple value) 20 second for 1 round ko speed
	
	/*
		// Buddha tathastu motion
	

		SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ELBOW, ON);
		SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_LEFT_ELBOW, ON);
		_delay_ms(2000);
		SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ELBOW, OFF);
		SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_WRIST_SERVO, BUDDHA_RIGHT_WRIST_UP_POS);
		SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_UP_POS);
		_delay_ms(2000);
		SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ELBOW, OFF);
		SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_UP_POS);
		SlaveCtrlAPI::servoPosWrite(BUDDHA, LEFT_WRIST_SERVO, BUDDHA_LEFT_WRIST_DOWN_POS);
		SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_WRIST_SERVO, BUDDHA_RIGHT_WRIST_DOWN_POS);
		_delay_ms(6000);
	*/
		
	
	//TIME 1:10
	SlaveCtrlAPI::waitTill(toMillis(1,10));
	SlaveCtrlAPI::dmxColour(DMX, 0xAA, 0x99, 0x33, CONSTANT);
	
	//TIME 1:39
	SlaveCtrlAPI::waitTill(toMillis(1,39));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, RISHI_FOCUS_LIGHT, 127, 4000);
	
	//TIME 1:41
	SlaveCtrlAPI::waitTill(toMillis(1,41));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 88, 4000);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 1:42
	SlaveCtrlAPI::waitTill(toMillis(1,42));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 100, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 100, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_B, 100, 7000);
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
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_EXRIGHT_POS);
	_delay_ms(4000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_RIGHT_POS);
	_delay_ms(4000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_EXRIGHT_POS);
	_delay_ms(4000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_RIGHT_POS);
	
	//TIME 2:10
	SlaveCtrlAPI::waitTill(toMillis(2,10));
	SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_WRIST_SERVO, BUDDHA_RIGHT_WRIST_UP_POS);
	//TIME 2:13
	SlaveCtrlAPI::waitTill(toMillis(2,13));
	SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_WRIST_SERVO, BUDDHA_RIGHT_WRIST_DOWN_POS);
	//TIME 2:15
	SlaveCtrlAPI::waitTill(toMillis(2,15));
	SlaveCtrlAPI::servoPosWrite(BUDDHA, LEFT_WRIST_SERVO, BUDDHA_LEFT_WRIST_UP_POS);
	//TIME 2:18
	SlaveCtrlAPI::waitTill(toMillis(2,18));
	SlaveCtrlAPI::servoPosWrite(BUDDHA, LEFT_WRIST_SERVO, BUDDHA_LEFT_WRIST_DOWN_POS);
	
	
	//TIME 2:27
	SlaveCtrlAPI::waitTill(toMillis(2,27));	
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_EXRIGHT_POS);
	_delay_ms(4000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_RIGHT_POS);
	
	
	//TIME 2:57
	SlaveCtrlAPI::waitTill(toMillis(2,57));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	
	
	//TIME 3:05
	SlaveCtrlAPI::waitTill(toMillis(3,5));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, KOUNDAL_FOCUS_LIGHT, 127, 5000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_RIGHT_POS);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_ONE, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_TWO, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_THREE, OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_FOUR,OFF);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, RISHI_FIVE,OFF);
	
	//TIME 3:10
	SlaveCtrlAPI::waitTill(toMillis(3,10));	
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 3:14
	SlaveCtrlAPI::waitTill(toMillis(3,14));
	SlaveCtrlAPI::dmxColour(DMX, 0x00, 0x00, 0x00, CONSTANT);
	SlaveCtrlAPI::dmxSweepAngle(DMX, PAN_MOTOR, 90, 150);
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, KOUNDAL_FOCUS_LIGHT, 0, 6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, RISHI_FOCUS_LIGHT, 0, 6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 0, 6000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT, 10, 6000);
	
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ELBOW, OFF);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_WRIST_SERVO, BUDDHA_RIGHT_WRIST_UP_POS);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_UP_POS);
		
	//TIME 3:16
	SlaveCtrlAPI::waitTill(toMillis(3,16));
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ELBOW, OFF);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_UP_POS);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_WRIST_SERVO, BUDDHA_RIGHT_WRIST_DOWN_POS);
	SlaveCtrlAPI::mouthStop(BUDDHA);

	
	//TIME 3:18
	SlaveCtrlAPI::waitTill(toMillis(3,18));
	SlaveCtrlAPI::dmxSweepAngle(DMX, PAN_MOTOR, 0, 150);
	SlaveCtrlAPI::dmxSweepAngle(DMX, TILT_MOTOR, 0, 150);
	SlaveCtrlAPI::dmxColour(DMX, 0xEE, 0x00, 0x00, CONSTANT);
	
	//TIME 3:38
	SlaveCtrlAPI::waitTill(toMillis(3,38));
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_STAND, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ELBOW, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_LEFT_ELBOW, ON);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_DOWN_POS);
	SlaveCtrlAPI::dmxColour(DMX, 0xDD, 0x00, 0x00, STROBE);
	
	
	//TIME 3:43
	SlaveCtrlAPI::waitTill(toMillis(3,43));
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, ON);
	//TIME 3:44
	SlaveCtrlAPI::waitTill(toMillis(3,44));
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, OFF);
	//TIME 3:45
	SlaveCtrlAPI::waitTill(toMillis(3,45));
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, ON);
	SlaveCtrlAPI::waitTill(toMillis(3,46));
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, OFF);

	
	//TIME 3:46
	SlaveCtrlAPI::waitTill(toMillis(3,46));
	SlaveCtrlAPI::dmxColour(DMX, 0xCC, 0x00, 0x00, CONSTANT); 
	//angulimal hand motor up
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 127, 1000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 25, 5000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 25, 5000);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	
	SlaveCtrlAPI::waitTill(toMillis(3,47));
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, ON);
	SlaveCtrlAPI::waitTill(toMillis(3,48));
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, OFF);
	SlaveCtrlAPI::waitTill(toMillis(3,49));
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, ON);
	SlaveCtrlAPI::waitTill(toMillis(3,50));
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, OFF);
	SlaveCtrlAPI::waitTill(toMillis(3,51));
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, ON);
	SlaveCtrlAPI::waitTill(toMillis(3,52));
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, OFF);
	
	//TIME 3:54
	SlaveCtrlAPI::waitTill(toMillis(3,54));
	SlaveCtrlAPI::mouthStop(ANGULIMAL);
	SlaveCtrlAPI::dmxColour(DMX, 0xCC, 0x00, 0x10, CONSTANT);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 127, 5000);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_WAIST_PNEUMATIC, ON);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	_delay_ms(500);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, NECK_SERVO, BUDDHA_NECK_LEFT_POS);
	
	//TIME 4:05
	SlaveCtrlAPI::waitTill(toMillis(4,5));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	SlaveCtrlAPI::dmxColour(DMX, 0xAA, 0x22, 0x11, CONSTANT);
	
	//TIME 4:13
	SlaveCtrlAPI::waitTill(toMillis(4,13));
	SlaveCtrlAPI::mouthStop(ANGULIMAL);
	SlaveCtrlAPI::dmxColour(DMX, 0x99, 0x33, 0x33, CONSTANT);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	
	//TIME 4:30
	SlaveCtrlAPI::waitTill(toMillis(4,30));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::dmxColour(DMX, 0x88, 0x44, 0x44, CONSTANT);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	
	//TIME 4:39
	SlaveCtrlAPI::waitTill(toMillis(4,39));
	SlaveCtrlAPI::mouthStop(ANGULIMAL);
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::dmxColour(DMX, 0x77, 0x55, 0x55, CONSTANT);
	
	//TIME 5:25
	SlaveCtrlAPI::waitTill(toMillis(5,25));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::dmxColour(DMX, 0x66, 0x77, 0x77, CONSTANT);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	
	//TIME 5:50
	SlaveCtrlAPI::waitTill(toMillis(5,50));
	SlaveCtrlAPI::mouthStop(ANGULIMAL);
	//Hands down
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::dmxColour(DMX, 0x55, 0x99, 0x99, CONSTANT);
	
	//TIME 6:00
	SlaveCtrlAPI::waitTill(toMillis(6,0));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	SlaveCtrlAPI::dmxColour(DMX, 0x44, 0xAA, 0xAA, CONSTANT);
	
	//TIME 6:11
	SlaveCtrlAPI::waitTill(toMillis(6,11));
	SlaveCtrlAPI::mouthStop(ANGULIMAL);
	SlaveCtrlAPI::dmxColour(DMX, 0x33, 0xBB, 0xBB, CONSTANT);
	
	//TIME 6:13
	SlaveCtrlAPI::waitTill(toMillis(6,13));
	SlaveCtrlAPI::mouthStart(BUDDHA, BUDDHA_MOUTH_UP_POS, BUDDHA_MOUTH_DOWN_POS);
	SlaveCtrlAPI::dmxColour(DMX, 0x33, 0xBB, 0xCC, CONSTANT);

	
	//TIME 6:37
	SlaveCtrlAPI::waitTill(toMillis(6,37));
	SlaveCtrlAPI::mouthStop(BUDDHA);
	SlaveCtrlAPI::dmxColour(DMX, 0x11, 0xCC, 0xEE, CONSTANT);
	
	//buddha hands up
	SlaveCtrlAPI::mouthStart(ANGULIMAL, ANGULIMAL_MOUTH_UP_POS, ANGULIMAL_MOUTH_DOWN_POS);
	
	//TIME 6:39
	SlaveCtrlAPI::waitTill(toMillis(6,39));
	SlaveCtrlAPI::mouthStop(ANGULIMAL);
	SlaveCtrlAPI::dmxColour(DMX, 0x00, 0xCC, 0xFF, CONSTANT);
	SlaveCtrlAPI::pneumaticWrite(ANGULIMAL, ANGULIMAL_WAIST_NEUMATIC, ON);
	
		
	//TIME 7:08
	SlaveCtrlAPI::waitTill(toMillis(7,8));
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ELBOW, ON);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_LEFT_ELBOW, ON);
	_delay_ms(1000);
	SlaveCtrlAPI::pneumaticWrite(BUDDHA, BUDDHA_RIGHT_ELBOW, OFF);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_WRIST_SERVO, BUDDHA_RIGHT_WRIST_UP_POS);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, HAND_SERVO, BUDDHA_HAND_UP_POS);
	_delay_ms(3000);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_WRIST_SERVO, BUDDHA_RIGHT_WRIST_DOWN_POS);
	
	
	//TIME 7:28
	SlaveCtrlAPI::waitTill(toMillis(7,28));
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 0, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT, 0, 7000);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AUDIENCE_LIGHT, 127,7000);
	SlaveCtrlAPI::dmxColour(DMX, 0x00, 0x00, 0x00, CONSTANT);
	SlaveCtrlAPI::servoPosWrite(BUDDHA, RIGHT_WRIST_SERVO, BUDDHA_RIGHT_WRIST_DOWN_POS);
	ampStop();	
}

#endif