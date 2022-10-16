/*
 * ampControlAPI.h
 *
 * Created: 11/28/2021 7:08:44 AM
 *  Author: Rishav
 */ 


#ifndef AMPCONTROLAPI_H_
#define AMPCONTROLAPI_H_

#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(MP3_PLAYER_RX, MP3_PLAYER_TX);
DFRobotDFPlayerMini myDFPlayer;

enum language{
	NEPALI,
	ENGLISH,
	HINDI
};

void ampInit(uint8_t volume)
{
	mySoftwareSerial.begin(9600);
	if (!myDFPlayer.begin(mySoftwareSerial))
	{
		indicator2On();
		while (1);
	}
	myDFPlayer.begin(mySoftwareSerial);
	myDFPlayer.setTimeOut(500); //ms
	myDFPlayer.volume(volume);
	myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
	myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
}

void ampSetVolume(uint8_t volume)
{
	myDFPlayer.volume(volume);
}

void ampStop()
{
	myDFPlayer.pause();
}

void ampPlay(language lan)
{
	switch (lan)
	{
	case NEPALI:
		myDFPlayer.play(1);
		break;
		
	case ENGLISH:
		myDFPlayer.play(2);
		break;
		
	case HINDI:
		myDFPlayer.play(3);
		break;
	}
}
#endif /* AMPCONTROLAPI_H_ */