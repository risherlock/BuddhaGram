/*
 * wegaAPI.h
 *
 * Created: 2/4/2020 4:07:15 PM
 *  Author: Rishav
 */ 

#ifndef wegaAPI_H_
#define wegaAPI_H_

#define WEGA_REMOTE_MIN_DELAY	100	 
 
//room 3 and room 4
class wega{
	private:
		static void pressButton(unsigned long txData);
		
	public:
		static void init();
		static void play();
		static void nextConfig();
};

#endif /* wega32CtrlAPI_H_ */