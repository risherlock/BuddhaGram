/*
 * includes.h
 *
 * Created: 1/24/2020 4:24:51 PM
 *  Author: Rishav
 */ 

#ifndef INCLUDES_H_
#define INCLUDES_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

// Inc files for main.cpp
#include <avr/io.h>
#include <util/delay.h>

#include "DMX512/DMXapi.h"
#include "arduino/Arduino.h"
#include "DMX512/DMXSerial.h"
#include "modbus/include/mb.h"
#include "modbus/include/mbport.h"

#endif /* INCLUDES_H_ */