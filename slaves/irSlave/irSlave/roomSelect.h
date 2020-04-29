/*
 * roomSelect.h
 *
 * Created: 2/4/2020 5:26:34 PM
 *  Author: Rishav
 */ 

/* Description
 * ===========
 * ROOM2 -> Projector 
 * ROOM3 -> WEGA32" TV
 * ROOM4 -> HOLOGRAM1(Durbar)	: WEGA14" 
 *			and HOLOGRAM2(River): a95x TV box
 * ROOM5 -> t96Mini TV box 	 		
 */

#ifndef ROOMSELECT_H_
#define ROOMSELECT_H_

//Select room
#define ROOM 4

/*			!!!For ROOM 4 only!!!
 * 1. Set hologram based on above description
 * 2. if(!HOLOGRAM_USED){comment_it();} 
 */
#define HOLOGRAM 2
 
//Auto slave address selection
#if (ROOM==2)
	#define SLAVE_ADDRESS  0x48
#endif

#if (ROOM==3)
	#define SLAVE_ADDRESS  0x51
#endif

#if (ROOM==4) && (HOLOGRAM==1)
	#define SLAVE_ADDRESS  0x49
#endif

#if (ROOM==4) && (HOLOGRAM==2)
	#define SLAVE_ADDRESS  0x48 
#endif

#if (ROOM==5) 
	#define SLAVE_ADDRESS  0x48
#endif

#endif /* ROOMSELECT_H_ */