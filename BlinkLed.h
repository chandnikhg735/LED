/************************************************************************************
 * 
 * Name    : BlinkLed.h
 * Author  : Mark Reds <marco@markreds.it>
 * Date    : September 8, 2020
 * Version : 0.1
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

#ifndef BlinkLed_h
#define BlinkLed_h

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

enum BlinkMode {
	kBlinkSingle,
	kBlinkMultiple,
	kBlinkBreath
};

class BlinkLed {
	public:
		BlinkLed(uint8_t pin);
		void setMode(BlinkMode mode);
		void setCount(uint8_t count);
		void setInterval(uint32_t interval);
		void loop(void);
	private:
		uint8_t m_pin;
		uint8_t m_count;
		uint32_t m_interval;
		BlinkMode m_mode;
};

#endif
