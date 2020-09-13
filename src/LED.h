/************************************************************************************
 * 
 * Name    : LED.h
 * Author  : Mark Reds <marco@markreds.it>
 * Date    : September 8, 2020
 * Version : 1.0.0
 * Notes   : An Arduno library to drive status led in multiple modes to aid in multitasking.
 * 
 * Copyright (c) 2020 Mark Reds.  All right reserved.
 * 
 * 
 * BlinkLed is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * BlinkLed is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with BlinkLed.  If not, see <http://www.gnu.org/licenses/>.
 * 
 ************************************************************************************/

#ifndef LED_h
#define LED_h

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include "pins_arduino.h"
#endif

enum ledstate_t {
	kSwitchOff,
	kSwitchOn,
	kBlinkOn,
	kBlinkOff,
	kBlinkPause,
	kBreathIn,
	kBreathOut
};

class LED {
	private:
		uint8_t m_pin;
		uint8_t m_lo;
		uint8_t m_hi;
		uint8_t m_count;
		uint32_t m_start;
		uint32_t m_interval;
		ledstate_t m_state;
	public:
		LED(uint8_t pin);
		LED(uint8_t pin, uint8_t lo, uint8_t hi);
		virtual ~LED();
		void on(void);
		void off(void);
		void blink(uint32_t interval);
		void blink(uint8_t count, uint32_t pause, uint32_t timeOn = 180UL, uint32_t timeOff = 120UL);
		void breath(uint32_t interval);
		inline uint8_t state(void) { return m_state; }
};

#endif
