/*
 * slaveConfig.h
 *
 * Created: 12/22/2019 12:45:49 PM
 *  Author: Rishav
 */ 

#ifndef SLAVECONFIG_H_
#define SLAVECONFIG_H_

//Viewing from connector side 
//tip122 pins:  C4, B5, C3, C5, 12V
const uint8_t tip122[4] = {PIN_A4, LED_BUILTIN, PIN_A3, PIN_A5};
 void tip122Init(){
 	for (uint8_t i=0; i<4; i++){
 		pinMode(tip122[i], OUTPUT);
 		digitalWrite(tip122[i], LOW);
 	}
 }

#endif /* SLAVECONFIG_H_ */