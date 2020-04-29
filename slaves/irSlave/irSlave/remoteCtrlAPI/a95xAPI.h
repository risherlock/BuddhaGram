/*
 * a95xAPI.h
 *
 * Created: 2/4/2020 10:04:08 PM
 *  Author: Rishav
 */ 


#ifndef A95XAPI_H_
#define A95XAPI_H_

#define A95X_REMOTE_MIN_DELAY	100	 

//room 4 (A95X TV box)
class a95x{
	private:
	static void pressButton(unsigned long txData);
	
	public:
	static void init();
	static void play();
	static void nextConfig();
};

#endif /* A95XAPI_H_ */