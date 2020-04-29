/*
 * slaveConfig.h
 *
 * Description: Command addresses of slaves
 *  Created: 1/25/2020 11:49:03 PM
 *   Author: Rishav
 */ 


#ifndef SLAVECONFIG_H_
#define SLAVECONFIG_H_

//Fuse-bit(Atmega328P): 07 D9 FF

#define SLAVE_ADDR_START		0x45

//Modbus regs address and size
#define SLAVE_REG_STARTING_ADDR 1000
#define REG_INPUT_START			1000
#define REG_INPUT_NREGS			4
#define REG_OUTPUT_START		1000
#define REG_OUTPUT_NREGS		64

//lightController command address
#define LIGHT_RESET_ADDR 1032

//roboSlave command address
#define PNEUMATIC_WRITE_ADDR	1053
#define HOLOGRAM_WRITE_ADDR		1055
#define SERVO_WRITE_ADDR		1057
#define MOUTH_START_WRITE_ADDR	1060
#define MOUTH_STOP_WRITE_ADDR	1063

//irSlave command address
#define RECONFIGURE_ADDR	1015
#define LAMP_ON_ADDR		1014
#define LAMP_OFF_ADDR		1013
#define PLAY_VIDEO_ADDR		1012

//dmxSlave command address
#define DMX_SWEEP_ADDR		1011
#define DMX_SUN_START_ADDR	1015
#define DMX_SUN_STOP_ADDR	1016
#define DMX_COLOUR_ADDR		1017

//lightController pins
#define B1 0
#define G1 1
#define R1 2
#define B2 3
#define G2 4
#define R2 5
#define L1 6
#define L2 7
#define L3 8
#define L4 9
#define R3 10
#define G3 11
#define B3 12
#define R4 13
#define G4 14
#define B4 15

#endif /* SLAVECONFIG_H_ */