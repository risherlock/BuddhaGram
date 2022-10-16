/*
 * TimeKeeper.h
 *
 * Created: 12/11/2013 9:21:53 AM
 *  Author: R_Shrestha
 */ 


#ifndef TIMEKEEPER_H_
#define TIMEKEEPER_H_


class TimeKeeper{
	public:
	
	static void init(void);
	static unsigned long millis(void);
};

#endif /* TIMEKEEPER_H_ */