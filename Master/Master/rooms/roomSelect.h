/*
 * roomSelect.h
 *
 * Created: 1/25/2020 11:54:37 PM
 *  Author: Rishav
 */ 


#ifndef ROOMSELECT_H_
#define ROOMSELECT_H_

#if defined(ROOM) && ROOM == 1
	#include "room1.h"
#endif
#if defined(ROOM) && ROOM == 2
	#include "room2.h"
#endif
#if defined(ROOM) && ROOM == 3
	#include "room3.h"
#endif
#if defined(ROOM) && ROOM == 4
	#include "room4.h"
#endif
#if defined(ROOM) && ROOM == 5
	#include "room5.h"
#endif
#if defined(ROOM) && ROOM == 6
	#include "room6.h"
#endif
#if defined(ROOM) && ROOM == 7
	#include "room7.h"
#endif
#if defined(ROOM) && ROOM == 8
	#include "room8.h"
#endif

#endif /* ROOMSELECT_H_ */