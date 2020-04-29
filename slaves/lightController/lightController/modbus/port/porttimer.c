/*
 * FreeModbus Libary: ATMega168 Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: porttimer.c,v 1.4 2006/09/03 11:53:10 wolti Exp $
 */

/* ----------------------- AVR includes -------------------------------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
//#include <avr/signal.h>

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "../include/mb.h"
#include "../include/mbport.h"

/* ----------------------- Defines ------------------------------------------*/
#define MB_TIMER_PRESCALER      ( 1024UL )
#define MB_TIMER_TICKS          ( F_CPU / MB_TIMER_PRESCALER )
#define MB_50US_TICKS           ( 20000UL )

/* ----------------------- Static variables ---------------------------------*/
static USHORT   usTimerOCRADelta;
//static USHORT   usTimerOCRBDelta;

static UCHAR   usTimerOCRDeltaHi;
static UCHAR   usTimerOCRDeltaLo;

static UCHAR TCNT2_Hi;
static UCHAR OCR2_Hi;

/* ----------------------- Start implementation -----------------------------*/
BOOL
xMBPortTimersInit( USHORT usTim1Timerout50us )
{
    /* Calculate overflow counter an OCR values for Timer1. */
    usTimerOCRADelta =
        ( MB_TIMER_TICKS * usTim1Timerout50us ) / ( MB_50US_TICKS );

    usTimerOCRDeltaHi = usTimerOCRADelta >> 8;
    usTimerOCRDeltaLo = usTimerOCRADelta & 0xFF;

    //TCCR1A = 0x00;
    //TCCR1B = 0x00;
    //TCCR1C = 0x00;
#if defined(__AVR_ATmega168__) || \
	defined(__AVR_ATmega328P__) || \
	defined(__AVR_ATmega328__)
    TCCR2A = 0;
    TCCR2B = 0;
#elif defined(__AVR_ATmega8__)
    TCCR2 = 0;
#endif

    vMBPortTimersDisable(  );

    return TRUE;
}


inline void
vMBPortTimersEnable(  )
{

    //TCNT1 = 0x0000;
	TCNT2_Hi = 0;
	TCNT2 = 0;

//	if( usTimerOCRADelta > 0 )
//    {
//        TIMSK1 |= _BV( OCIE1A );
//        OCR1A = usTimerOCRADelta;
//    }

	if (usTimerOCRDeltaHi > 0)
	{
		//overflow init
#if defined(__AVR_ATmega168__) || \
	defined(__AVR_ATmega328P__) || \
	defined(__AVR_ATmega328__)
		TIMSK2 |= _BV( TOV2 );
		TIMSK2 &= ~_BV( OCIE2A );
		OCR2_Hi = usTimerOCRDeltaHi;
		OCR2A = usTimerOCRDeltaLo;
#elif defined(__AVR_ATmega8__)
		TIMSK |= _BV( TOV2 );
		TIMSK &= ~_BV( OCIE2 );
		OCR2_Hi = usTimerOCRDeltaHi;
		OCR2 = usTimerOCRDeltaLo;
#endif

	}
	else if (usTimerOCRDeltaLo > 0)
	{
		//only compare
#if defined(__AVR_ATmega168__) || \
	defined(__AVR_ATmega328P__) || \
	defined(__AVR_ATmega328__)
		TIMSK2 |= _BV( OCIE2A );
		TIMSK2 &= ~_BV( TOV2 );
		OCR2_Hi = usTimerOCRDeltaHi;
		OCR2A = usTimerOCRDeltaLo;
#elif defined(__AVR_ATmega8__)
		TIMSK |= _BV( OCIE2 );
		TIMSK &= ~_BV( TOV2 );
		OCR2_Hi = usTimerOCRDeltaHi;
		OCR2 = usTimerOCRDeltaLo;
#endif
	}

//    TCCR1B |= _BV( CS12 ) | _BV( CS10 );
#if defined(__AVR_ATmega168__) || \
	defined(__AVR_ATmega328P__) || \
	defined(__AVR_ATmega328__)
	TCCR2B |= _BV( CS22 ) | _BV( CS21 ) | _BV( CS20 );
#elif defined(__AVR_ATmega8__)
	TCCR2 |= _BV( CS22 ) | _BV( CS21 ) | _BV( CS20 );
#endif
}

inline void
vMBPortTimersDisable(  )
{
    /* Disable the timer. */
//    TCCR1B &= ~( _BV( CS12 ) | _BV( CS10 ) );
    /* Disable the output compare interrupts for channel A/B. */
//    TIMSK1 &= ~( _BV( OCIE1A ) );
    /* Clear output compare flags for channel A/B. */
//    TIFR1 |= _BV( OCF1A ) ;

#if defined(__AVR_ATmega168__) || \
	defined(__AVR_ATmega328P__) || \
	defined(__AVR_ATmega328__)
	TCCR2B &= ~(_BV( CS22 ) | _BV( CS21 ) | _BV( CS20 ));
	TIMSK2 &= ~( _BV( OCIE2A ) | _BV( TOIE2 ));
	TIFR2 |= _BV( OCF2A ) | _BV( TOV2 );
#elif defined(__AVR_ATmega8__)
	TCCR2 |= ~(_BV( CS22 ) | _BV( CS21 ) | _BV( CS20 ));
	TIMSK &= ~( _BV( OCIE2 ) | _BV( TOIE2 ));
	TIFR |= _BV( OCF2 ) | _BV( TOV2 );
#endif

}


//ISR( TIMER1_COMPA_vect )
/*SIGNAL( SIG_OUTPUT_COMPARE1A )*/
#if defined(__AVR_ATmega168__) || \
	defined(__AVR_ATmega328P__) || \
	defined(__AVR_ATmega328__)
ISR( TIMER2_COMPA_vect )
#elif defined(__AVR_ATmega8__)
ISR( TIMER2_COMP_vect )
#else
#error "Part Not Supported"
#endif
{
    ( void )pxMBPortCBTimerExpired(  );
}

ISR( TIMER2_OVF_vect )
{
	TCNT2_Hi++;
	if (TCNT2_Hi < OCR2_Hi)
	{
		//TCNT2_Hi < OCR2_Hi
	}
	else if (TCNT2_Hi == OCR2_Hi)
	{
		//enable ocr2 interrupt
		//disable ovf interrupt
#if defined(__AVR_ATmega168__) || \
	defined(__AVR_ATmega328P__) || \
	defined(__AVR_ATmega328__)
		TIMSK2 |= _BV( OCIE2A );
		OCR2A = usTimerOCRDeltaLo;
		TCCR2B &= ~(_BV( CS22 ) | _BV( CS21 ) | _BV( CS20 ));
		TIMSK2 &= ~_BV( TOIE2 );
		TIFR2 |= _BV( OCF2A ) | _BV( TOV2 );
#elif defined(__AVR_ATmega8__)
		TIMSK |= _BV( OCIE2 );
		OCR2 = usTimerOCRDeltaLo;
#endif

	}
	else
	{	//TCNT2_Hi > OCR2_Hi
		//for sanity's sake
	    ( void )pxMBPortCBTimerExpired(  );
	}
}

