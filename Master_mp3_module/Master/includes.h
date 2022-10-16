/*
 * includes.h
 *
 * Created: 12/23/2019 2:33:46 PM
 *  Author: Rishav
 */ 


#ifndef INCLUDES_H_
#define INCLUDES_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

//Incs for main.cpp
#include <util/delay.h>

#include "configs/masterConfig.h"
#include "configs/slaveConfig.h"

#include "timekeeper/timekeeper.h"
#include "slaveCtrlAPI/slaveCtrlAPI.h"
#include "mp3/ampControlAPI.h"
#include "rooms/commonFunctions.h"

#endif /* INCLUDES_H_ */