/*
 * t96miniAPI.h
 *
 * Created: 2/5/2020 5:43:42 PM
 *  Author: Rishav
 */ 


#ifndef T96MINIAPI_H_
#define T96MINIAPI_H_

#define T96MINI_REMOTE_MIN_DELAY	150

//room 5 (T96Mini TV box)
class t96mini{
	private:
	static void pressButton(unsigned long txData);
	
	public:
	static void init();
	static void play();
	static void nextConfig();
};

#endif /* T96MINIAPI_H_ */