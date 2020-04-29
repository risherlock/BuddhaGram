/*
 * SCServo.cpp
 * Series Control Servo for SCS15
 * Created on  : 2015.4.15
 * Author      : Tony tan
 * Modified on : 2015.8.7
 * Modification author: Ilya  and Rishav
 */

#include "scServo.h"

SCServo::SCServo () : _SCSserial(RX_PIN, TX_PIN)
{
	
}

void SCServo::init(long baud_rate){
	
	if(!baud_rate){
		baud_rate = 115200;
	}
	_delay_ms(300);
	_SCSserial.begin(baud_rate);
}

void SCServo::end(){
		_delay_ms(300);
		_SCSserial.end();
}

void SCServo::Printf(byte reg)
{
	_SCSserial.write(reg);
}

int SCServo::ReadSerial(void)
{
	int data;
	data = _SCSserial.read();
	return data;
}

void SCServo::fflushRevBuf(void)
{
	int size;
	while(1){
		size = ReadSerial();
		if(size==-1)
			break;
	}
}

int SCServo::EnableTorque(byte ID, byte Enable, byte ReturnLevel)
{
	int messageLength = 4;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_TORQUE_ENABLE);
	Printf(Enable);
	Printf((~(ID + messageLength + INST_WRITE + Enable + P_TORQUE_ENABLE))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}

int SCServo::WritePos(byte ID, int position, int velocity, byte ReturnLevel)
{
	int messageLength = 7;
	byte posL = position>>8;
	byte posH = position&0xff;	
	byte velL = velocity>>8;
	byte velH = velocity&0xff;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_GOAL_POSITION_L);
	Printf(posL);
	Printf(posH);
	Printf(velL);
	Printf(velH);
	Printf((~(ID + messageLength + INST_WRITE + P_GOAL_POSITION_L + posL + posH + velL + velH))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}

int SCServo::RegWritePos(byte ID, int position, int velocity, byte ReturnLevel)
{
	int messageLength = 7;
	byte posL = position>>8;
	byte posH = position&0xff;
	byte velL = velocity>>8;
	byte velH = velocity&0xff;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_REG_WRITE);
	Printf(P_GOAL_POSITION_L);
	Printf(posL);
	Printf(posH);
	Printf(velL);
	Printf(velH);
	Printf((~(ID + messageLength + INST_REG_WRITE + P_GOAL_POSITION_L + posL + posH + velL + velH))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}

void SCServo::RegWriteAction()
{
	int messageLength = 2;
	byte ID = 0xfe; 
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_ACTION);
	Printf((~(ID + messageLength + INST_ACTION))&0xFF);
}

int SCServo::ReadBuf(byte len, byte *buf)
{
	int Size;
	int ComData;
	unsigned long t_begin = millis();
	unsigned long t_user;
	while(1){
		
		Size = _SCSserial.available();
		if(Size>=len){
			break;
		}
		t_user = millis() - t_begin;
		if(t_user>TIMEOUT){
			break;
		}
	}
	int i;
	for(i=0; i<len; i++){
		if(buf){
			buf[i] = ReadSerial();
		}else{
			ComData = ReadSerial();
		}
	}
	return Size;
}

int SCServo::ReadPos(byte ID)
{	
	byte buf[8];
	int size;
	int pos;
	memset(buf,0,sizeof(buf));

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(4);
	Printf(INST_READ);
	Printf(P_PRESENT_POSITION_L);
	Printf(2);
	Printf((~(ID + 4 + INST_READ + P_PRESENT_POSITION_L + 2))&0xFF);
	size = ReadBuf(8, buf);
	if(size<8)
		return -1;
	pos = buf[5];
	pos <<= 8;
	pos |= buf[6];
	return pos;
}

void SCServo::SyncWritePos(byte ID[], byte IDN, int position, int velocity)
{
	int messageLength = 5*IDN+4;
	byte Sum = 0;
	byte posL = position>>8;
	byte posH = position&0xff;		
	
	byte velL = velocity>>8;
	byte velH = velocity&0xff;

	Printf(startByte);
	Printf(startByte);
	Printf(0xfe);
	Printf(messageLength);
	Printf(INST_SYNC_WRITE);
	Printf(P_GOAL_POSITION_L);
	Printf(4);
	
	Sum = 0xfe + messageLength + INST_SYNC_WRITE + P_GOAL_POSITION_L + 4;
	int i;
	for(i=0; i<IDN; i++){
		Printf(ID[i]);
		Printf(posL);
		Printf(posH);
		Printf(velL);
		Printf(velH);
		Sum += ID[i] + posL + posH + velL + velH;
	}
	Printf((~Sum)&0xFF);
}

int SCServo::WriteID(byte oldID, byte newID, byte ReturnLevel)
{
	int messageLength = 4;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(oldID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_ID);
	Printf(newID);
	Printf((~(oldID + messageLength + INST_WRITE + newID + P_ID))&0xFF);
	if(oldID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}

int SCServo::WriteLimitAngle(byte ID, int MinAngel, int MaxAngle, byte ReturnLevel)
{
	int messageLength = 7;
	byte MinAL = MinAngel>>8;
	byte MinAH = MinAngel&0xff;	
	byte MaxAL = MaxAngle>>8;
	byte MaxAH = MaxAngle&0xff;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_MIN_ANGLE_LIMIT_L);
	Printf(MinAL);
	Printf(MinAH);
	Printf(MaxAL);
	Printf(MaxAH);
	Printf((~(ID + messageLength + INST_WRITE + P_MIN_ANGLE_LIMIT_L + MinAL + MinAH + MaxAL + MaxAH))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}

int SCServo::WriteLimitTroque(byte ID, int MaxTroque, byte ReturnLevel)
{
	int messageLength = 5;
	byte MaxTL = MaxTroque>>8;
	byte MaxTH = MaxTroque&0xff;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_MAX_TORQUE_L);
	Printf(MaxTL);
	Printf(MaxTH);

	Printf((~(ID + messageLength + INST_WRITE + P_MAX_TORQUE_L + MaxTL + MaxTH))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}

int SCServo::WritePunch(byte ID, int Punch, byte ReturnLevel)
{
	int messageLength = 5;
	byte PunchL = Punch>>8;
	byte PunchH = Punch&0xff;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_PUNCH_L);
	Printf(PunchL);
	Printf(PunchH);

	Printf((~(ID + messageLength + INST_WRITE + P_PUNCH_L + PunchL + PunchH))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}

int SCServo::WriteBaund(byte ID, byte Baund, byte ReturnLevel)
{
	int messageLength = 4;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_BAUD_RATE);
	Printf(Baund);

	Printf((~(ID + messageLength + INST_WRITE + P_BAUD_RATE + Baund))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}

int SCServo::WriteDeadBand(byte ID, byte CWDB, byte CCWDB, byte ReturnLevel)
{
	int messageLength = 5;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_CW_DEAD);
	Printf(CWDB);
	Printf(CCWDB);

	Printf((~(ID + messageLength + INST_WRITE + P_CW_DEAD + CWDB + CCWDB))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}

int SCServo::WriteIMax(byte ID, int IMax, byte ReturnLevel)
{
	int messageLength = 5;	

	byte velL = IMax>>8;
	byte velH = IMax&0xff;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_IMAX_L);
	Printf(velL);
	Printf(velH);
	Printf((~(ID + messageLength + INST_WRITE + P_IMAX_L + velL + velH))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}


int SCServo::LockEprom(byte ID, byte Enable, byte ReturnLevel)
{
	int messageLength = 4;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_LOCK);
	Printf(Enable);

	Printf((~(ID + messageLength + INST_WRITE + P_LOCK + Enable))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}

int SCServo::WritePID(byte ID, byte P, byte I, byte D, byte ReturnLevel)
{
	int messageLength = 6;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_COMPLIANCE_P);
	Printf(P);
	Printf(D);
	Printf(I);

	Printf((~(ID + messageLength + INST_WRITE + P_COMPLIANCE_P + P + D + I))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}

int SCServo::WriteSpe(byte ID, int velocity, byte ReturnLevel)
{
	int messageLength = 5;	

	int vel = velocity;
	if(velocity<0){
		vel = -velocity;
		vel |= (1<<10);
	}

	byte velL =  vel>>8;
	byte velH =  vel&0xff;

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(messageLength);
	Printf(INST_WRITE);
	Printf(P_GOAL_SPEED_L);
	Printf(velL);
	Printf(velH);
	Printf((~(ID + messageLength + INST_WRITE + P_GOAL_SPEED_L + velL + velH))&0xFF);
	if(ID != 0xfe && ReturnLevel==2)
		return ReadBuf(6);
	return 0;
}


int SCServo::ReadVoltage(byte ID)
{	
	byte buf[7];
	byte size;
	int vol;
	memset(buf,0,sizeof(buf));

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(4);
	Printf(INST_READ);
	Printf(P_PRESENT_VOLTAGE);
	Printf(1);
	Printf((~(ID + 4 + INST_READ + P_PRESENT_VOLTAGE + 1))&0xFF);
	size = ReadBuf(7, buf);
	if(size<7)
		return -1;
	vol = buf[5];
	return vol;
}

int SCServo::ReadTemper(byte ID)
{	
	byte buf[7];
	byte size;
	int temper;
	memset(buf,0,sizeof(buf));

	fflushRevBuf();
	Printf(startByte);
	Printf(startByte);
	Printf(ID);
	Printf(4);
	Printf(INST_READ);
	Printf(P_PRESENT_TEMPERATURE);
	Printf(1);
	Printf((~(ID + 4 + INST_READ + P_PRESENT_TEMPERATURE + 1))&0xFF);
	size = ReadBuf(7, buf);
	if(size<7)
		return -1;
	temper = buf[5];
	return temper;
}

void SCServo::RotateClockwise(){
	EnableTorque(0xfe, 1);
	_delay_ms(200);
	WritePos(0xfe, 400, 500);
}

void SCServo::RotateCounterClockwise(){
	EnableTorque(0xfe, 1);
	_delay_ms(200);
	WritePos(0xfe, 750, 500);
}