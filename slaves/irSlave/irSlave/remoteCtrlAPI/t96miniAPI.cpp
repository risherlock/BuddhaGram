/*
 * t96miniAPI.cpp
 *
 * Created: 2/5/2020 5:44:01 PM
 *  Author: Rishav
 */ 

#include "t96miniAPI.h"
#include "../ir/IRremote.h"
#include "../configs/remoteConfig.h"

#include <util/delay.h>

// !! Don't edit !!
//Master must wait for 50 secs
void t96mini::init(){	
	_delay_ms(40000);							//monitor + T96Mini startup
	t96mini:: pressButton(irT96mini_LEFT);		//folders
	t96mini:: pressButton(irT96mini_OK);		//select
	_delay_ms(2000);							//wait
	t96mini:: pressButton(irT96mini_LEFT);		//internal flash
	_delay_ms(1500);			    			//wait
	t96mini:: pressButton(irT96mini_DOWN);		//USB
	_delay_ms(500);								//wait
	t96mini:: pressButton(irT96mini_OK);		//select
	_delay_ms(500);								//wait
	t96mini:: pressButton(irT96mini_DOWN);		//0159-9534
	t96mini:: pressButton(irT96mini_OK);		//select
	_delay_ms(500);								//wait
	t96mini:: pressButton(irT96mini_DOWN);		//Android
	t96mini:: pressButton(irT96mini_DOWN);		//LOST.DIR
	t96mini:: pressButton(irT96mini_DOWN);		//System Volume Information
	t96mini:: pressButton(irT96mini_DOWN);		//video
	t96mini:: pressButton(irT96mini_OK);		//select
	_delay_ms(2000);							//wait
	t96mini:: pressButton(irT96mini_OK);		//enable task bar
 	t96mini:: pressButton(irT96mini_PLAY_PAUSE);//pause
 	_delay_ms(1000);								//wait
 	t96mini:: pressButton(irT96mini_RETURN);	//disable task bar
}

void t96mini::play(){
	//t96mini:: pressButton(irT96mini_OK);		 //enable task bar	
	t96mini:: pressButton(irT96mini_PLAY_PAUSE); //play
	//_delay_ms(1000);							 //wait
	//t96mini:: pressButton(irT96mini_RETURN);	 //disable task bar
} 

void t96mini::nextConfig(){
	t96mini:: pressButton(irT96mini_RETURN);	//back
	_delay_ms(1000);							//wait
	t96mini:: pressButton(irT96mini_OK);		//select
	_delay_ms(2000);							//wait
	t96mini:: pressButton(irT96mini_OK);		//enable task bar
	t96mini:: pressButton(irT96mini_PLAY_PAUSE);//pause
	_delay_ms(200);								//wait
	t96mini:: pressButton(irT96mini_RETURN);	//disable task bar
}                                                                                                                                                                                                   

void t96mini::pressButton(unsigned long txData){
	irTransmit.sendNEC(txData, 32);
	_delay_ms(T96MINI_REMOTE_MIN_DELAY);
}
