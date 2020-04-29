/*
 * ModbusMasterArray.cpp
 *
 * Created: 11/10/2013 8:58:52 AM
 *  Author: R_Shrestha
 */ 
#include "ModbusMasterArray.h"

void ModbusMasterArray::Reset(){
	this->len=0;
}

uint8_t ModbusMasterArray::GetLen(void){
	return this->len;
}

/*Access MyArray as stack*/
uint16_t ModbusMasterArray::GetTail(void){
	if (this->len==0) return 0;
	this->len--;
	return this->data[this->len];
}

void ModbusMasterArray::Append(uint16_t input){
	this->data[len]=input;
	len++;
}

ModbusMasterArray::ModbusMasterArray(void){
	this->Reset();
}
