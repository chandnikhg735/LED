/************************************************************************************
 * 
 * Name    : BlinkLed.cpp
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

#include "BlinkLed.h"

BlinkLed::BlinkLed(uint8_t pin) : BlinkLed(pin, LOW, HIGH) {
	
}

BlinkLed::BlinkLed(uint8_t pin, uint8_t lo, uint8_t hi) {
	m_pin = pin;
	m_lo = lo;
	m_hi = hi;
	m_count = 0;
	m_interval = 0UL;
	pinMode(m_pin, OUTPUT);
}

void BlinkLed::setMode(BlinkMode mode) {
	m_mode = mode;
}

void BlinkLed::setCount(uint8_t count) {
	m_count = count;
}

void BlinkLed::setInterval(uint32_t interval) {
	m_interval = interval;
}

void BlinkLed::loop(void) {
	static uint32_t previousMillis = millis();
	static uint32_t interval = m_interval;
	static uint8_t count = m_count;
	static bool state = true;

	if ((millis() - previousMillis) > interval) {
		switch (m_mode) {
			case kBlinkSingle:			
				digitalWrite(m_pin, digitalRead(m_pin) == m_hi ? m_lo : m_hi);
				interval = m_interval;
				break;
			case kBlinkMultiple:
				if (digitalRead(m_pin) == m_lo) {
					if (count > 0) {
						digitalWrite(m_pin, m_hi);
						interval = 100UL;
						count--;
					} else {
						interval = m_interval;
						count = m_count;
					}
				} else {
					digitalWrite(m_pin, m_lo);
					interval = 250UL;
				}				
				break;
			case kBlinkBreath:
				analogWrite(m_pin, count);
				if (state) {
					if (count == 255) {
						state = false;
					} else {
						count++;
					}
				} else {
					if (count == 0) {
						state = true;
					} else {
						count--;
					}
				}
				break;
		}
		previousMillis = millis();
	}
			
}
