/*
 * remoteConfig.h
 *
 * Created: 1/12/2020 3:38:36 PM
 *  Author: Rishav
 */ 


#ifndef REMOTECONFIG_H_
#define REMOTECONFIG_H_

//projector (room 2)
#define irPROJECTOR_POWER		0xEF008F70
#define irPROJECTOR_MUTE		0xEF00CF30
#define irPROJECTOR_PREV		0xEF006F90
#define irPROJECTOR_NEXT		0xEF009F60
#define irPROJECTOR_PLAY_PAUSE	0xEF001FE0
#define irPROJECTOR_OK			0xEF000FF0
#define irPROJECTOR_UP			0xEF007F80
#define irPROJECTOR_DOWN		0xEF005FA0
#define irPROJECTOR_LEFT		0xEF00FF00
#define irPROJECTOR_RIGHT		0xEF00BF40
#define irPROJECTOR_BACK		0xEF003FC0
#define irPROJECTOR_MENU		0xEF00DF20
#define irPROJECTOR_INPUT		0xEF00AF50
#define irPROJECTOR_VOL_INC		0xEF00EF10
#define irPROJECTOR_VOL_DEC		0xEF004FB0//wega (room 3 and 4)
#define irWEGA_MENU		0xFE2AD5
#define irWEGA_OK		0xFE5AA5
#define irWEGA_SOURCE	0xFECA35
#define irWEGA_UP		0xFE7A85
#define irWEGA_DOWN		0xFE6A95
#define irWEGA_LEFT		0xFEDA25
#define irWEGA_RIGHT	0xFE1AE5
#define irWEGA_EXIT		0xFEEA15
#define irWEGA_INFO		0xFE9A65
#define irWEGA_CH_INC	0xFEDF20
#define irWEGA_CH_DEC	0xFE5FA0
#define irWEGA_VOL_INC	0xFE9F60
#define irWEGA_VOL_DEC	0xFE1FE0
#define irWEGA_CH_MEDIA	0xFE22DD
#define irWEGA_CH_AUTO	0xFEA25D
#define irWEGA_POWER	0xFE50AF
#define irWEGA_MUTE		0xFED02F
#define irWEGA_ONE		0xFE708F
#define irWEGA_TWO		0xFE609F
#define irWEGA_THREE	0xFEF00F
#define irWEGA_FOUR		0xFE48B7
#define irWEGA_FIVE		0xFEE01F
#define irWEGA_SIX		0xFEC837
#define irWEGA_SEVEN	0xFE6897
#define irWEGA_EIGHT	0xFE40BF
#define irWEGA_NINE		0xFEE817
#define irWEGA_ZERO		0xFE58A7
#define irWEGA_PMODE	0xFE0FF0
#define irWEGA_SMODE	0xFE8F70
#define irWEGA_SLEEP	0xFEAF50
#define irWEGA_AUDIO	0xFE4FB0#define irWEGA_PLAY		0xFED22D#define irWEGA_STOP		0xFE52AD//T96mini TV box (room 3)#define irT96mini_POWER		0x807F02FD#define irT96mini_LEFT		0x807F8A75#define irT96mini_RIGHT		0x807F0AF5#define irT96mini_UP		0x807F6897#define irT96mini_DOWN		0x807F58A7#define irT96mini_SETUP		0x807FC23D#define irT96mini_APP		0x807FF00F#define irT96mini_VOL_INC	0x807F18E7#define irT96mini_VOL_DEC	0x807F08F7#define irT96mini_RETURN	0x807F9867#define irT96mini_HOME		0x807F8877#define irT96mini_MUTE		0x807F827D#define irT96mini_PLAY_PAUSE 0x807F5AA5#define irT96mini_STOP		0x807F4AB5#define irT96mini_FBKD		0x807FAA55#define irT96mini_FFWD		0x807F2AD5#define irT96mini_MEDIA		0x807F22DD#define irT96mini_OK		0x807FC837//android box
#define  irA95X_OK         0x202B04F
#define  irA95X_UP		   0x202D02F
#define  irA95X_DOWN	   0x202708F
#define  irA95X_LEFT       0x20208F7#define  irA95X_RIGHT      0x2028877
#define  irA95X_VOL_INC    0x202A857
#define  irA95X_VOL_DEC    0x20238C7
#define  irA95X_POWER      0x202B24D
#define  irA95X_RETURN     0x20242BD
#define  irA95X_MENU       0x202A25D
#define  irA95X_HOME       0x20258A7
#define  irA95X_MOUSE      0x20222DD
#define  irA95X_MUTE       0x202C23D#define  irA95X_MEDIA      0x202CA35#define  irA95X_TV         0x202DA25#define  irA95X_APP        0x2022AD5
#endif /* REMOTECONFIG_H_ */