/*
 * ModbusMaster.cpp
 *
 * Created: 11/8/2013 9:21:46 PM
 *  Author: R_Shrestha
 */ 

#include "ModbusMaster.h"

#define FUNC_CODE_WRITE_OUTPUT 0X10
#define FUNC_CODE_READ_OUTPUT 0X03
#define FUNC_CODE_READ_INPUT 0x04

ModbusMaster::ModbusMaster(void){
	this->lrc_sum=0;
	
	this->listening_response=0;
	this->response_valid=0;
	
	this->response_state = RCV_IDLE;
	this->response_byte_position = HIGH_NIBBLE;
	
}

uint8_t ModbusMaster::CheckBusy(void){
	return this->listening_response;
}

uint8_t ModbusMaster::LastTransactionSuccess(void){
	return this->response_valid;
}

void ModbusMaster::AssertInvalidResponse(void){
	this->response_state = RCV_IDLE;
	this->response_valid = 0;
	this->listening_response=0;
	
	this->TimeoutStopCB();
}

void ModbusMaster::TimeoutCB(void){
	this->AssertInvalidResponse();
}

uint8_t ModbusMaster::Ascii2Nibble(uint8_t character){
	if (character >='0' && character <= '9'){
		return character - '0';
	}
	else if (character>='A' && character<='F'){
		return character - 55;//ascii of 'A' is 65, need 10 for 'A'
	}
	else{
		return 0;
	}
}

uint8_t ModbusMaster::Nibble2Ascii(uint8_t data){
	data&=0x0F;
	if (data<10){
		return '0'+data;
	}
	else{
		return 55+data;//ascii of 'A' is 65, data is at least 10
	}
}
void ModbusMaster::CharSend(uint8_t data){
	this->WriteCharacterCB(Nibble2Ascii(data>>4));
	this->WriteCharacterCB(Nibble2Ascii(data));
	this->lrc_sum+=data;
}


void ModbusMaster::IntSend(uint16_t data){
	this->CharSend(data>>8);
	this->CharSend(data);
}

void ModbusMaster::WriteOutputReg(uint8_t slave_addr, uint16_t register_addr){//void ModbusMaster::WriteOutputReg(uint8_t slave_addr, uint16_t register_addr, ModbusMasterArray* data_buffer){
	this->lrc_sum=0;
	this->response_valid=0;//invalid until valid
	
	this->request_data_struct.function_code = FUNC_CODE_WRITE_OUTPUT;
	this->request_data_struct.slave_addr = slave_addr;
	this->request_data_struct.quantity_of_regs = this->data_buffer.GetLen();//data_buffer->GetLen();
	this->request_data_struct.starting_addr = register_addr;
	
	//message header is colon(':')
	this->WriteCharacterCB(':');
	//slave address
	this->CharSend(slave_addr);
	//function code (for writing multiple registers) ie 0x10
	this->CharSend(FUNC_CODE_WRITE_OUTPUT);
	//register starting address
	this->IntSend(register_addr-1);//register address starts from 1 (in free-modbus implementation)
	//quantity of registers
	this->IntSend(this->data_buffer.GetLen());
	//byte count
	this->CharSend(2*this->data_buffer.GetLen());
	//data
	for(uint8_t i=0; i<this->data_buffer.GetLen(); i++){
		this->IntSend(this->data_buffer.data[i]);
	}
	//LRC
	this->CharSend(-((int8_t)this->lrc_sum));
	//Carriage Return (CR)
	this->WriteCharacterCB(0x0D);
	//Line Feed (LF)
	this->WriteCharacterCB(0x0A);
	
	this->response_state = RCV_IDLE;
	this->listening_response=1;
	this->TimeoutStartCB();
	
}

void ModbusMaster::ReadReg(void){
	this->lrc_sum=0;

	this->response_valid=0;//invalid until valid
	

	//message header is colon(':')
	this->WriteCharacterCB(':');
	//slave address
	this->CharSend(this->request_data_struct.slave_addr);
	//function code 
	this->CharSend(this->request_data_struct.function_code);
	//register starting address
	this->IntSend(this->request_data_struct.starting_addr-1);//register address starts from 1 (in free-modbus implementation)
	//quantity of registers
	this->IntSend(this->request_data_struct.quantity_of_regs);
	
	//LRC
	this->CharSend(-((int8_t)this->lrc_sum));
	//Carriage Return (CR)
	this->WriteCharacterCB(0x0D);
	//line Feed (LF)
	this->WriteCharacterCB(0x0A);
	
	this->response_state = RCV_IDLE;
	this->listening_response=1;
	this->TimeoutStartCB();
}

void ModbusMaster::ReadOutputReg(uint8_t slave_addr,uint16_t register_addr, uint8_t no_of_reg){
	this->request_data_struct.function_code = FUNC_CODE_READ_OUTPUT;
	this->request_data_struct.slave_addr = slave_addr;
	this->request_data_struct.quantity_of_regs = no_of_reg;
	this->request_data_struct.starting_addr = register_addr;
	
	this->ReadReg();
}

//can use the same code for reading both the input and holding (output) registers, with only the function codes changed
void ModbusMaster::ReadInputReg(uint8_t slave_addr,uint16_t register_addr, uint8_t no_of_reg){
	this->request_data_struct.function_code = FUNC_CODE_READ_INPUT;
	this->request_data_struct.slave_addr = slave_addr;
	this->request_data_struct.quantity_of_regs = no_of_reg;
	this->request_data_struct.starting_addr = register_addr;
	
	this->ReadReg();
}

//FSM of response from the slave
//TODO make this method more readable and intuitive 
void ModbusMaster::ReadCharacterCB(uint8_t character){
	static uint16_t FSM_buffer;
	
	static uint8_t lrc_sum;
	
	//if master doesn't need to listen
	if (!this->listening_response) return; 
	this->TimeoutResetCB();
	
	switch(this->response_state){
		case RCV_IDLE:
			if (character == ':'){
				this->response_state = RCV_SLAVE_ADDR;
				this->response_byte_position = HIGH_NIBBLE;
				lrc_sum = 0;
			}			
			break;
			
		case RCV_SLAVE_ADDR:
			if (this->response_byte_position == HIGH_NIBBLE){
				FSM_buffer = (this->Ascii2Nibble(character))<<4;
				this->response_byte_position = LOW_NIBBLE;
			}			
			else{
				FSM_buffer |= (this->Ascii2Nibble(character));
				this->response_byte_position = HIGH_NIBBLE;
				
				if (FSM_buffer == this->request_data_struct.slave_addr){
					 this->response_state = RCV_FUNC_CODE;
					 lrc_sum+=FSM_buffer;
					 
				}				
				else{
					this->AssertInvalidResponse(); 
				}				
			}			
			break;
			
		case RCV_FUNC_CODE:
			if (this->response_byte_position == HIGH_NIBBLE){
				FSM_buffer = (this->Ascii2Nibble(character))<<4;
				this->response_byte_position = LOW_NIBBLE;
			}
			else{
				FSM_buffer |= (this->Ascii2Nibble(character));
				this->response_byte_position = HIGH_NIBBLE;
				
				if (FSM_buffer == this->request_data_struct.function_code){
					lrc_sum+=FSM_buffer;
					if (FSM_buffer == FUNC_CODE_WRITE_OUTPUT){
						this->response_state = RCV_START_ADDR_HIGH;
						
					}	
					else if (FSM_buffer == FUNC_CODE_READ_OUTPUT || FSM_buffer == FUNC_CODE_READ_INPUT){
						this->response_state = RCV_BYTE_COUNT;
					}								
				}
				//function code mismatch, the frame is incorrect				
				else{
					this->AssertInvalidResponse();
				}				
			}
			break;
			
			case RCV_BYTE_COUNT:
				if (this->response_byte_position == HIGH_NIBBLE){
					FSM_buffer = (this->Ascii2Nibble(character))<<4;
					this->response_byte_position = LOW_NIBBLE;
				}
				else{
					FSM_buffer |= (this->Ascii2Nibble(character));
					this->response_byte_position = HIGH_NIBBLE;
				
					if (FSM_buffer == 2*this->request_data_struct.quantity_of_regs){
						lrc_sum+=FSM_buffer;
						this->response_state = RCV_DATA_HIGH;
						this->data_buffer.Reset();
					}
					//function code mismatch, the frame is incorrect
					else{
						this->AssertInvalidResponse();
					}
				}
				break;
			
		case RCV_START_ADDR_HIGH:
			if (this->response_byte_position == HIGH_NIBBLE){
				FSM_buffer = ((uint16_t)(this->Ascii2Nibble(character)))<<12;
				this->response_byte_position = LOW_NIBBLE;
			}
			else{
				FSM_buffer |= ((uint16_t)((this->Ascii2Nibble(character))))<<8;
				this->response_byte_position = HIGH_NIBBLE;
				this->response_state = RCV_START_ADDR_LOW;
				
				lrc_sum+=(uint8_t)(FSM_buffer>>8);	
			}
			break;
			
		case RCV_START_ADDR_LOW:
			if (this->response_byte_position == HIGH_NIBBLE){
				FSM_buffer |= ((uint16_t)(this->Ascii2Nibble(character)))<<4;
				this->response_byte_position = LOW_NIBBLE;
			}
			else{
				FSM_buffer |= (uint16_t)((this->Ascii2Nibble(character))&0xFF);
				this->response_byte_position = HIGH_NIBBLE;
				
				//the address in physical layer starts from 0, ours from 1
				if ((FSM_buffer+1) == this->request_data_struct.starting_addr){
					 this->response_state = RCV_QUANTITY_OF_REG_HIGH;
					 lrc_sum+=(uint8_t)(FSM_buffer & 0xFF); 
				}	
				//starting mismatch, the frame is incorrect			
				else{
					this->AssertInvalidResponse();
					
				}
			}			
			break;
		
		case RCV_QUANTITY_OF_REG_HIGH:
			if (this->response_byte_position == HIGH_NIBBLE){
				FSM_buffer = (this->Ascii2Nibble(character))<<12;
				this->response_byte_position = LOW_NIBBLE;
			}
			else{
				FSM_buffer |= (this->Ascii2Nibble(character))<<8;
				this->response_byte_position = HIGH_NIBBLE;
				this->response_state = RCV_QUANTITY_OF_REG_LOW;
				
				lrc_sum+=(uint8_t)(FSM_buffer>>8);
				
			}
			break;
		
		case RCV_QUANTITY_OF_REG_LOW:
			if (this->response_byte_position == HIGH_NIBBLE){
				FSM_buffer |= (this->Ascii2Nibble(character))<<4;
				this->response_byte_position = LOW_NIBBLE;
			}
			else{
				FSM_buffer |= (this->Ascii2Nibble(character));
				this->response_byte_position = HIGH_NIBBLE;
			
			
				if (FSM_buffer == this->request_data_struct.quantity_of_regs){
					this->response_state = RCV_LRC;
					lrc_sum+=(uint8_t)(FSM_buffer & 0xFF);
				}
				//quantity of register mismatch, the frame is incorrect
				else{
					this->AssertInvalidResponse();
				}
			}			
			break;
			
		case RCV_DATA_HIGH:
			if (this->response_byte_position == HIGH_NIBBLE){
				FSM_buffer = (this->Ascii2Nibble(character))<<12;
				this->response_byte_position = LOW_NIBBLE;
			}
			else{
				FSM_buffer |= (this->Ascii2Nibble(character))<<8;
				this->response_byte_position = HIGH_NIBBLE;
				this->response_state = RCV_DATA_LOW;
			
				lrc_sum+=(uint8_t)(FSM_buffer>>8);
			}
			break;
		
		case RCV_DATA_LOW:
			if (this->response_byte_position == HIGH_NIBBLE){
				FSM_buffer |= (this->Ascii2Nibble(character))<<4;
				this->response_byte_position = LOW_NIBBLE;
			}
			else{
				FSM_buffer |= (this->Ascii2Nibble(character));
				this->response_byte_position = HIGH_NIBBLE;
			
				lrc_sum+=(uint8_t)(FSM_buffer & 0xFF);
				
				this->data_buffer.Append(FSM_buffer);
				
			
				if (this->data_buffer.GetLen() >= this->request_data_struct.quantity_of_regs){
					this->response_state = RCV_LRC;
				}
				else{
					this->response_state = RCV_DATA_HIGH;
				}
				
			}
			break;
			
		case RCV_LRC:
			if (this->response_byte_position == HIGH_NIBBLE){
				FSM_buffer = (this->Ascii2Nibble(character))<<4;
				this->response_byte_position = LOW_NIBBLE;
			}
			else{
				FSM_buffer |= (this->Ascii2Nibble(character));
				this->response_byte_position = HIGH_NIBBLE;
								
				
				if (FSM_buffer == (uint8_t)(-((int8_t)lrc_sum))){
					this->response_state = RCV_CR;
				}
				//LRC mismatch, the frame is incorrect
				else{
					this->AssertInvalidResponse();					
				}
			}
			break;
		
		case RCV_CR:
			//carriage return
			if (character==0x0D){
				this->response_state = RCV_LF;
			}
			else{
				this->AssertInvalidResponse();
			}
			break;
			
		case RCV_LF:
			
			if (character==0x0A){//line feed
				this->response_state = RCV_IDLE;
				this->response_valid = 1;
				this->listening_response=0;
				
				this->TimeoutStopCB();
			}
			else{
				this->AssertInvalidResponse();
			}
	}
			
}
	

