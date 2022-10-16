/*
 * room6.h
 *
 * Created: 1/26/2020 1:46:46 PM
 *  Author: Ant
 */ 


#ifndef ROOM6_H_
#define ROOM6_H_

#include "../includes.h"

//slaves
#define LIGHT_CONTROLLER 0x45
#define DMX 0x48
#define KANYA 0x47

//amp_volume (max:32)
#define VOLUME 27

//Lights
#define AUDIENCE_LIGHT L4
#define TREE_LIGHT_R R1
#define TREE_LIGHT_G R1
#define TREE_LIGHT_B B1
#define ATMOSPHERIC_LIGHT_R R2
#define ATMOSPHERIC_LIGHT_G G2
#define FLASHBACK_HOLOGRAPHIC_LIGHT B4
#define BUDDHA_HOLOGRAPHIC_LIGHT G1
#define BUDDHA_BACK_LIGHT G3
#define BUDDHA_FOCUS_LIGHT L1
#define KANYA_FOCUS_LIGHT L2
#define SUJATA_FOCUS_LIGHT L3
#define LIGHTENING_LIGHT R3
#define LIGHTENING_PROJECTION_LIGHT R3
#define MOON_LIGHT B2

//Servo Id
#define NECK_SERVO 2
#define HOLOGRAPHIC_SERVO 5

//Pneumatic Id
#define KANYA_WAIST_PNEUMATIC 4

//Servo positions
#define KANYA_NECK_LEFT_POS 500
#define KANYA_NECK_RIGHT_POS 700
#define HOLOGRAPHIC_SERVO_POS1 750
#define HOLOGRAPHIC_SERVO_POS2 250

#define ON 1
#define OFF 0
#define UP 1
#define DOWN 0

void resetToInitial(){

	SlaveCtrlAPI::lightReset(LIGHT_CONTROLLER);
	SlaveCtrlAPI::pneumaticWrite(KANYA, KANYA_WAIST_PNEUMATIC, OFF);
	SlaveCtrlAPI::servoPosWrite(KANYA, NECK_SERVO, KANYA_NECK_RIGHT_POS);
	SlaveCtrlAPI::servoPosWrite(KANYA, HOLOGRAPHIC_SERVO, HOLOGRAPHIC_SERVO_POS1);
	SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,127,6000);
	motorOn();
	motor2On();
	SlaveCtrlAPI::dmxColour(DMX, 0, 0, 0, CONSTANT);
}

void playScript(){	
		//TIME 0:0
		SlaveCtrlAPI::waitTill(toMillis(0,0));
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER,AUDIENCE_LIGHT,0,7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 87, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 127, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_B, 87, 7000);
		
		//TIME 0:25
		SlaveCtrlAPI::waitTill(toMillis(0,25));
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 1, 5000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 1, 5000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_B, 1, 5000);
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_BACK_LIGHT, 127, 5000);
		SlaveCtrlAPI::dmxSweepAngle(DMX, PAN_MOTOR, 0, 255);
		
		//TIME 1:00
		SlaveCtrlAPI::waitTill(toMillis(1,00));
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 127, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 50, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_B, 127, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 6, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 4, 7000);
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_BACK_LIGHT, 0, 5000);
		SlaveCtrlAPI::dmxSweepAngle(DMX, PAN_MOTOR, 127, 255);
		
		//TIME 1:03
		SlaveCtrlAPI::waitTill(toMillis(1,03));
		SlaveCtrlAPI::dmxSunStart(DMX);
		
		//TIME 1:30
		SlaveCtrlAPI::waitTill(toMillis(1,30));
		//FLASHBACK ko scene
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, FLASHBACK_HOLOGRAPHIC_LIGHT, 127, 5000);
		SlaveCtrlAPI::servoPosWrite(KANYA, HOLOGRAPHIC_SERVO, HOLOGRAPHIC_SERVO_POS1);
		motor2Off();
		
		//TIME 1:42
		SlaveCtrlAPI::waitTill(toMillis(1,42));
		motor2On();
		SlaveCtrlAPI::servoPosWrite(KANYA, HOLOGRAPHIC_SERVO, HOLOGRAPHIC_SERVO_POS2);
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, FLASHBACK_HOLOGRAPHIC_LIGHT, 0, 5000);
	
		//TIME 1:46
		SlaveCtrlAPI::waitTill(toMillis(1,46));
		SlaveCtrlAPI::dmxSunStart(DMX);
		
		//TIME 1:52
		SlaveCtrlAPI::waitTill(toMillis(1,52));
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 0, 5000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 1, 5000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_B, 3, 5000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 0, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 0, 7000);
		
		//TIME 2:00
		SlaveCtrlAPI::waitTill(toMillis(2,00));
		SlaveCtrlAPI::dmxSunStop(DMX);
		
		//TIME 2:31
		SlaveCtrlAPI::waitTill(toMillis(2,31));
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_HOLOGRAPHIC_LIGHT, 127, 5000);
		
		//TIME 2:46
		SlaveCtrlAPI::waitTill(toMillis(2,46));
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_HOLOGRAPHIC_LIGHT, 0, 5000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 0, 20000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 0, 20000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_B, 0, 20000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 65, 20000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 32, 20000);
		
		//TIME 3:02
		SlaveCtrlAPI::waitTill(toMillis(3,02));
		for(int i=0; i<2; i++){
			SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 5, 8000);
			SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 127, 8000);
			SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 64, 8000);
			_delay_ms(8000);
			SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 20, 8000);
			SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 20, 8000);
			SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 10, 8000);
			_delay_ms(8000);
		}
		
		//TIME 3:50
		SlaveCtrlAPI::waitTill(toMillis(3,50));
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 5, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 20, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 10, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 60, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 30, 7000);
		
		//TIME 4:00
		SlaveCtrlAPI::waitTill(toMillis(4,00));
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, SUJATA_FOCUS_LIGHT, 40, 7000);
		
		//TIME 4:21
		SlaveCtrlAPI::waitTill(toMillis(4,21));
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, SUJATA_FOCUS_LIGHT, 0, 7000);
		
		//TIME 4:30
		SlaveCtrlAPI::waitTill(toMillis(4,30));
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 0, 8000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 0, 8000);
		
		
		//TIME 4:44
		SlaveCtrlAPI::waitTill(toMillis(4,44));
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 10, 5000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 10, 5000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_B, 20, 5000);
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 0, 5000);
		
		//TIME 4:53
		SlaveCtrlAPI::waitTill(toMillis(4,53));
		motorOff();
		
		//TIME 5:00
		SlaveCtrlAPI::waitTill(toMillis(5,00));
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 127);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 127);
		_delay_ms(30);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 0);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 0);
		_delay_ms(30);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 127);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 127);
		_delay_ms(30);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 0);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 0);
		_delay_ms(30);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 127);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 127);
		_delay_ms(30);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 0);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 0);
		
		//TIME 5:08
		SlaveCtrlAPI::waitTill(toMillis(5,8));
		
		//TIME 5:18
		SlaveCtrlAPI::waitTill(toMillis(5,18));
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 127);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 127);
		_delay_ms(30);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 0);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 0);
		_delay_ms(30);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 127);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 127);
		_delay_ms(30);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 0);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 0);
		_delay_ms(30);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 127);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 127);
		_delay_ms(30);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_LIGHT, 0);
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, LIGHTENING_PROJECTION_LIGHT, 0);
		
		//TIME 5:29
		SlaveCtrlAPI::waitTill(toMillis(5,29));
		motorOn();
				
		//TIME 5:38
		SlaveCtrlAPI::waitTill(toMillis(5,38));
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, KANYA_FOCUS_LIGHT, 120);
		SlaveCtrlAPI::pneumaticWrite(KANYA, KANYA_WAIST_PNEUMATIC, ON);
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, MOON_LIGHT, 127, 10000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 1, 5000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 1, 5000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_B, 3, 5000);
		
		//TIME 5:53
		SlaveCtrlAPI::waitTill(toMillis(5,53));
		SlaveCtrlAPI::servoPosWrite(KANYA, NECK_SERVO, KANYA_NECK_LEFT_POS);
		
		//TIME 5:58
		SlaveCtrlAPI::waitTill(toMillis(5,58));
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 30, 5000);
		
		//TIME 6:30
		SlaveCtrlAPI::waitTill(toMillis(6,30));
		SlaveCtrlAPI::lightInstantWrite (LIGHT_CONTROLLER, KANYA_FOCUS_LIGHT, 0);
		SlaveCtrlAPI::servoPosWrite(KANYA, NECK_SERVO, KANYA_NECK_RIGHT_POS);
		SlaveCtrlAPI::pneumaticWrite(KANYA, KANYA_WAIST_PNEUMATIC, OFF);
		
		//TIME 6:37
		SlaveCtrlAPI::waitTill(toMillis(6,37));
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 127, 20000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 127, 20000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_B, 127, 20000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 127, 20000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 90, 20000);
		
		//TIME 6:51
		SlaveCtrlAPI::waitTill(toMillis(6,51));
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 127, 5000);
		
		//TIME 6:43
		SlaveCtrlAPI::waitTill(toMillis(6,43));
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, BUDDHA_BACK_LIGHT, 127, 12000);
		
		//TIME 7:27
		SlaveCtrlAPI::waitTill(toMillis(7,27));
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, BUDDHA_FOCUS_LIGHT, 0, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_R, 0, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_G, 0, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, TREE_LIGHT_B, 0, 7000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_R, 0, 7500);
		ampStop();
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, ATMOSPHERIC_LIGHT_G, 0, 6000);
		SlaveCtrlAPI::lightGradualWrite (LIGHT_CONTROLLER, MOON_LIGHT, 0, 7000);
		SlaveCtrlAPI::lightGradualWrite(LIGHT_CONTROLLER, AUDIENCE_LIGHT, 127,7000);
		
}

#endif /* ROOM6_H_ */