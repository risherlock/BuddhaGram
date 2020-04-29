/*
 * projectorAPI.h
 *
 * Created: 2/2/2020 12:32:53 AM
 *  Author: Rishav
 */ 


#ifndef PROJECTORAPI_H_
#define PROJECTORAPI_H_

#include <stdint.h>

#define PROJECTOR_REMOTE_MIN_DELAY	700	 //millis
#define PROJECTOR_WAIT_AFTER_PLAY	4000 //millis
#define PROJECTOR_LAMP_PIN 19 //c5

//room 2 (Some Chinese projector)
class projector{
	public:
		static void nextConfig();
		static void lampOff();
		static void lampOn();
		static void play();
		static void init();
		
	protected:
	private:
		static void pressButton(unsigned long txData);
};

#endif /* PROJECTORAPI_H_ */