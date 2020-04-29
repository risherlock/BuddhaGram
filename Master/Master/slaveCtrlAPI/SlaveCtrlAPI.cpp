/*
 * slaveCtrlAPI.cpp
 *
 * Created: 12/8/2013 9:17:25 AM
 *  Author: R_Shrestha
 *   Modified: Rishav
 */ 

#include "slaveCtrlAPI.h"

#include "../configs/masterConfig.h"

#include <avr/interrupt.h>
#include <util/delay.h>

#include "../uart/uart.h"
#include "../configs/slaveConfig.h"
#include "../timekeeper/timekeeper.h"
#include "../mbMaster/ModbusMaster.h"

#define UART_BAUD_RATE 9600
ModbusMaster modbus_master;

void SlaveCtrlAPI::init(void){
	uart1_init(UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU));
	sei();
	// why? It works
	_delay_ms(100);
}

uint8_t SlaveCtrlAPI::pneumaticWrite(uint16_t slave_addr, uint8_t pneumaticNumber, uint8_t pinMode){
	while (modbus_master.CheckBusy());
	modbus_master.data_buffer.Reset();

	modbus_master.data_buffer.Append(pneumaticNumber);
	modbus_master.data_buffer.Append(pinMode);
	modbus_master.WriteOutputReg(slave_addr, PNEUMATIC_WRITE_ADDR);
	
	//Second transmission
	while (modbus_master.CheckBusy());
	modbus_master.WriteOutputReg(slave_addr, PNEUMATIC_WRITE_ADDR);
	
	while (modbus_master.CheckBusy());
	return modbus_master.LastTransactionSuccess();	
}

uint8_t  SlaveCtrlAPI::servoPosWrite(uint8_t slave_addr, uint8_t servoId, uint16_t position){
	while (modbus_master.CheckBusy());
	modbus_master.data_buffer.Reset();
	
	// SERVO_WRITE_ADDR -> servoId,
	// (SERVO_WRITE_ADDR + 1) -> Position
	modbus_master.data_buffer.Append(servoId);
	modbus_master.data_buffer.Append(position);
	modbus_master.WriteOutputReg(slave_addr, SERVO_WRITE_ADDR);
	
	//Second transmission
	while (modbus_master.CheckBusy());
	modbus_master.WriteOutputReg(slave_addr, SERVO_WRITE_ADDR);
	
	while (modbus_master.CheckBusy());
	return modbus_master.LastTransactionSuccess();
}

uint8_t SlaveCtrlAPI::mouthStart(uint8_t slave_addr, uint16_t up_pos, uint16_t down_pos){
	while (modbus_master.CheckBusy());
	modbus_master.data_buffer.Reset();
	
	modbus_master.data_buffer.Append(up_pos);
	modbus_master.data_buffer.Append(down_pos);
	modbus_master.WriteOutputReg(slave_addr, MOUTH_START_WRITE_ADDR);
	
	//Second transmission
	while (modbus_master.CheckBusy());
	modbus_master.WriteOutputReg(slave_addr, MOUTH_START_WRITE_ADDR);
	
	while (modbus_master.CheckBusy());
	return modbus_master.LastTransactionSuccess();
}

uint8_t SlaveCtrlAPI::mouthStop(uint8_t slave_addr){
	while (modbus_master.CheckBusy());
	modbus_master.data_buffer.Reset();
	
	modbus_master.data_buffer.Append(63);//dummy data
	modbus_master.WriteOutputReg(slave_addr, MOUTH_STOP_WRITE_ADDR);
	
	while (modbus_master.CheckBusy());
	return modbus_master.LastTransactionSuccess();
}

#define LIGHT_CONTROLLER_BLOCK 2
uint8_t SlaveCtrlAPI::lightGradualWrite(uint16_t slave_addr, uint8_t lightNumber, uint8_t intensity, uint16_t duration){
	
	while (modbus_master.CheckBusy());
	modbus_master.data_buffer.Reset();
	
	modbus_master.data_buffer.Append(duration);
	modbus_master.data_buffer.Append(intensity);
	modbus_master.WriteOutputReg(slave_addr, SLAVE_REG_STARTING_ADDR + lightNumber * LIGHT_CONTROLLER_BLOCK);
	
	while (modbus_master.CheckBusy());
	return modbus_master.LastTransactionSuccess();
}

uint8_t SlaveCtrlAPI::lightInstantWrite(uint16_t slave_addr, uint8_t lightNumber, uint8_t intensity){
	
	while (modbus_master.CheckBusy());
	modbus_master.data_buffer.Reset();
	
	modbus_master.data_buffer.Append(intensity<<8);
	modbus_master.WriteOutputReg(slave_addr, SLAVE_REG_STARTING_ADDR + lightNumber * LIGHT_CONTROLLER_BLOCK+1);
	
	while (modbus_master.CheckBusy());
	return modbus_master.LastTransactionSuccess();
}

uint8_t SlaveCtrlAPI::lightReset(uint16_t slave_addr){
	
	while (modbus_master.CheckBusy());
	
	modbus_master.data_buffer.Reset();
	modbus_master.data_buffer.Append(0);
	modbus_master.WriteOutputReg(slave_addr, LIGHT_RESET_ADDR);
	
	while (modbus_master.CheckBusy());
	return modbus_master.LastTransactionSuccess();
}

uint8_t SlaveCtrlAPI::irSlaveCommand(uint16_t slave_addr, irSlaveCmd command){
	
	//Use lamp command first
	//Two IR commands must have delay 
	while (modbus_master.CheckBusy());
	
	modbus_master.data_buffer.Reset();
	modbus_master.data_buffer.Append(0);
	
	switch (command){
	case LAMP_ON:
		modbus_master.WriteOutputReg(slave_addr, LAMP_ON_ADDR);
		break;
	case LAMP_OFF:
		modbus_master.WriteOutputReg(slave_addr, LAMP_OFF_ADDR);
		break;
	case PLAY_VIDEO:
		modbus_master.WriteOutputReg(slave_addr, PLAY_VIDEO_ADDR);
		break;
	case RECONFIGURE:
		modbus_master.WriteOutputReg(slave_addr, RECONFIGURE_ADDR);
		break;
	}
	
	while (modbus_master.CheckBusy());
	return modbus_master.LastTransactionSuccess();
}

uint8_t SlaveCtrlAPI::dmxSweepAngle(uint16_t slave_addr, dmxMotor m, uint16_t angle, uint8_t speed){
	while (modbus_master.CheckBusy());
	modbus_master.data_buffer.Reset();
	
	switch (m){
		case PAN_MOTOR:
			modbus_master.data_buffer.Append(22);
			break;
		case TILT_MOTOR:
			modbus_master.data_buffer.Append(33);		
			break;			
	}
	
	modbus_master.data_buffer.Append(angle);
	modbus_master.data_buffer.Append(speed);
	modbus_master.WriteOutputReg(slave_addr, DMX_SWEEP_ADDR);
	
	//Second transmission
	while (modbus_master.CheckBusy());
	modbus_master.WriteOutputReg(slave_addr, DMX_SWEEP_ADDR);
	
	while (modbus_master.CheckBusy());
	return modbus_master.LastTransactionSuccess();
}

uint8_t SlaveCtrlAPI::dmxColour(uint16_t slave_addr, uint8_t r, uint8_t g, uint8_t b, dmxEffects e){
		while (modbus_master.CheckBusy());
		modbus_master.data_buffer.Reset();
		
		modbus_master.data_buffer.Append(r);
		modbus_master.data_buffer.Append(g);
		modbus_master.data_buffer.Append(b);
		
		switch (e){
			case STROBE:
			modbus_master.data_buffer.Append(1);
			break;
			case CONSTANT:
			modbus_master.data_buffer.Append(2);
			break;
			case NO_EFFECT:
			modbus_master.data_buffer.Append(3);
			break;	
		}
		modbus_master.WriteOutputReg(slave_addr, DMX_COLOUR_ADDR);
		
		//Second transmission
		while (modbus_master.CheckBusy());
		modbus_master.WriteOutputReg(slave_addr, DMX_COLOUR_ADDR);
		
		while (modbus_master.CheckBusy());
		return modbus_master.LastTransactionSuccess();
	
}

uint8_t SlaveCtrlAPI::dmxSunStart(uint16_t slave_addr){
		while (modbus_master.CheckBusy());
		
		modbus_master.data_buffer.Reset();
		modbus_master.data_buffer.Append(0);
		
		modbus_master.WriteOutputReg(slave_addr, DMX_SUN_START_ADDR);
		
		while (modbus_master.CheckBusy());
		return modbus_master.LastTransactionSuccess();
}

	
uint8_t SlaveCtrlAPI::dmxSunStop(uint16_t slave_addr){
	while (modbus_master.CheckBusy());
	
	modbus_master.data_buffer.Reset();
	modbus_master.data_buffer.Append(0);
	
	modbus_master.WriteOutputReg(slave_addr, DMX_SUN_STOP_ADDR);
	
	while (modbus_master.CheckBusy());
	return modbus_master.LastTransactionSuccess();
}

void SlaveCtrlAPI::waitTill(uint32_t x){
	while(TimeKeeper::millis() < x);
}

