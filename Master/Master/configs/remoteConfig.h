/*
 * remoteConfig.h
 *
 * Created: 1/12/2020 3:38:36 PM
 *  Author: Rishav
 */ 


#ifndef REMOTECONFIG_H_
#define REMOTECONFIG_H_

// vacuum tube amp
#define AMP_REMOTE_MIN_DELAY  45 // millis
#define AMP_MAX_VOLUME 32

#define AMP_MUTE        0xFF22DD
#define AMP_STOP        0xFF629D
#define AMP_INPUT       0xFF9867
#define AMP_VOL_INC     0xFF9867
#define AMP_VOL_DEC     0xFF6897
#define AMP_CH_INC      0xFFA857
#define AMP_CH_DEC      0xFF01F
#define AMP_PLAY_PAUSE  0xFF906F
#define AMP_REPEAT      0xFF02FD
#define AMP_EQ          0xFFC23D
#define AMP_FFWD        0xFFE01F
#define AMP_FBKD        0xFFA857
#define AMP_ONE         0xFF30CF
#define AMP_TWO         0xFF18E7
#define AMP_THREE		0xFF7A85
#define AMP_FOUR		0xFF10EF
#define AMP_FIVE		0xFF38C7
#define AMP_SIX			0xFF5AA5
#define AMP_SEVEN		0xFF42BD
#define AMP_EIGHT		0xFF4AB5
#define AMP_NINE		0xFF52AD
#define AMP_ZERO		0xFFB04F
// android box
#define  TV_BOX_OK         0x202B04F
#define  TV_BOX_CH_INC     0x202D02F
#define  TV_BOX_CH_DEC     0x202708F
#define  TV_BOX_LEFT       0x20208F7#define  TV_BOX_RIGHT      0x2028877
#define  TV_BOX_VOL_INC    0x202A857 
#define  TV_BOX_VOL_DEC    0x20238C7
#define  TV_BOX_POWER      0x202B24D
#define  TV_BOX_RETURN     0x20242BD
#define  TV_BOX_MENU       0x202A25D
#define  TV_BOX_HOME       0x20258A7
#define  TV_BOX_MOUSE      0x20222DD
#define  TV_BOX_MUTE       0x202C23D#define  TV_BOX_MEDIA      0x202CA35#define  TV_BOX_TV         0x202DA25#define  TV_BOX_APP        0x2022AD5
#endif /* REMOTECONFIG_H_ */