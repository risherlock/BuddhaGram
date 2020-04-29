/*
 * remoteCtrlAPI.h
 *
 * Created: 2/4/2020 6:00:04 PM
 *  Author: Rishav
 */ 


#ifndef REMOTECTRLAPI_H_
#define REMOTECTRLAPI_H_

#include "a95xAPI.h"
#include "wegaAPI.h"
#include "t96miniAPI.h"
#include "projectorAPI.h"

class remote{
	public:
		static void init();
		static void play();
		static void nextConfig();
		static void lampOff();
		static void lampOn();
	protected:
	private:
};

#endif /* REMOTECTRLAPI_H_ */