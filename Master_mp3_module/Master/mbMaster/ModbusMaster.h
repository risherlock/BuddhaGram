/*
 * ModbusMaster.h
 *
 * Created: 11/8/2013 9:19:59 PM
 *  Author: R_Shrestha
 */ 


#ifndef MODBUSMASTER_H_
#define MODBUSMASTER_H_

#include "ModbusMasterArray.h"

class ModbusMaster{
	private:
		uint8_t lrc_sum;

		struct{
			uint8_t slave_addr;
			uint8_t function_code;
			uint16_t quantity_of_regs;
			uint16_t starting_addr;
			
		}request_data_struct;
		
		enum{
			RCV_IDLE,
			RCV_SLAVE_ADDR,
			RCV_FUNC_CODE,
			RCV_START_ADDR_HIGH,
			RCV_START_ADDR_LOW,
			RCV_QUANTITY_OF_REG_HIGH,
			RCV_QUANTITY_OF_REG_LOW,
			RCV_LRC,
			RCV_CR,
			RCV_LF,
			RCV_BYTE_COUNT,
			RCV_DATA_HIGH,
			RCV_DATA_LOW
		}response_state;

		enum{
			HIGH_NIBBLE,
			LOW_NIBBLE,
		}response_byte_position;
		
		uint8_t listening_response;
		uint8_t response_valid;
		
		void IntSend(uint16_t data);
		void CharSend(uint8_t data);
		uint8_t Nibble2Ascii(uint8_t data);
		uint8_t Ascii2Nibble(uint8_t character);
		
		void AssertInvalidResponse(void);
		
		void ReadReg(void);
		
		
	public:
		ModbusMasterArray data_buffer;
		
		ModbusMaster(void);
		
		uint8_t CheckBusy(void);
		uint8_t LastTransactionSuccess(void);
		
		void ReadCharacterCB(uint8_t character);
		void WriteCharacterCB(uint8_t character);
		
		void TimeoutStartCB(void);
		void TimeoutStopCB(void);
		void TimeoutResetCB(void);
		void TimeoutCB(void);		
		
		void WriteOutputReg(uint8_t slave_addr,uint16_t register_addr);
		void ReadOutputReg(uint8_t slave_addr,uint16_t register_addr, uint8_t no_of_reg);
		void ReadInputReg(uint8_t slave_addr,uint16_t register_addr, uint8_t no_of_reg);
};




#endif /* MODBUSMASTER_H_ */