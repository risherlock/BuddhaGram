/*
 * ModbusMasterArray.h
 *
 * Created: 11/10/2013 8:58:18 AM
 *  Author: R_Shrestha
 */ 


#ifndef MODBUSMASTERARRAY_H_
#define MODBUSMASTERARRAY_H_
#include <avr/io.h>

// Data structure to represent array
#define MAX_MODBUSMASTERARRAY_SIZE 10

class ModbusMasterArray{
	private:
	uint8_t len;
	
	public:
	uint16_t data[MAX_MODBUSMASTERARRAY_SIZE];
	ModbusMasterArray(void);
	void Reset(void);
	void Append(uint16_t);
	uint8_t GetLen(void);
	uint16_t GetTail(void);
};

#endif /* MODBUSMASTERARRAY_H_ */