/************************************************************************************
 * 
 * Name    : mrLED
 * File    : LED.cpp
 * Author  : Mark Reds <marco@markreds.it>
 * Date    : September 8, 2020
 * Version : 1.0.2
 * Notes   : This library allows an Arduino board to control LEDs.
 * 
 * Copyright (C) 2020 Marco Rossi (aka Mark Reds).  All right reserved.
 * 
 * This file is part of mrLED.
 *
 * mrLED is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * mrLED is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with mrLED. If not, see <http://www.gnu.org/licenses/>.
 * 
 ************************************************************************************/

#include "LED.h"

LED::LED(const uint8_t pin) : LED(pin, LOW, HIGH) { }

LED::LED(const uint8_t pin, const uint8_t lo, const uint8_t hi) :
	m_pin(pin),
	m_lo(lo),
	m_hi(hi) {
	m_count = 0;
	m_interval = 0;
}

LED::~LED() {

}

void LED::on() {
	digitalWrite(m_pin, m_hi);
	m_state = kSwitchOn;
}

void LED::off() {
	digitalWrite(m_pin, m_lo);
	m_state = kSwitchOff;
}

void LED::toggle() {
	if (m_state == kSwitchOn) {
		digitalWrite(m_pin, m_lo);
		m_state = kSwitchOff;
	} else {
		digitalWrite(m_pin, m_hi);
		m_state = kSwitchOn;
	}
}

void LED::blink(uint32_t interval) {
	if ((millis() - m_start) > interval) {
		switch (m_state) {
			case kBlinkOn:
				digitalWrite(m_pin, m_lo);
				m_state = kBlinkOff;
				break;
			case kBlinkOff:
				digitalWrite(m_pin, m_hi);
				m_state = kBlinkOn;
				break;
			default:
				digitalWrite(m_pin, m_hi);
				m_state = kBlinkOn;
		}
		m_start = millis();
	}
}

void LED::blink(uint32_t interval, uint32_t duration) {
	switch (m_state) {
		case kBlinkOn:
			if ((millis() - m_start) > duration) {
				digitalWrite(m_pin, m_lo);
				m_state = kBlinkOff;
				m_start = millis();
			}
			break;
		case kBlinkOff:
			if ((millis() - m_start) > interval) {
				digitalWrite(m_pin, m_hi);
				m_state = kBlinkOn;
				m_start = millis();
			}
			break;
		default:
			digitalWrite(m_pin, m_hi);
			m_state = kBlinkOn;
			m_start = millis();
	}
}

void LED::flash(uint8_t count, uint32_t pause, uint32_t timeOn, uint32_t timeOff) {
	if ((millis() - m_start) > m_interval) {
		switch (m_state) {
			case kBlinkOff:
				digitalWrite(m_pin, m_hi);
				m_interval = timeOn;
				m_state = kBlinkOn;
				m_start = millis();
				break;
			case kBlinkOn:
				digitalWrite(m_pin, m_lo);
				m_state = kBlinkOff;
				if (--m_count > 0) {
					m_state = kBlinkOff;
					m_interval = timeOff;
				} else {
					m_state = kBlinkPause;
					m_interval = pause;
				}
				m_start = millis();
				break;
			case kBlinkPause:
				m_state = kBlinkOff;
				m_count = count;
				break;
			default:
				digitalWrite(m_pin, m_lo);
				m_state = kBlinkOff;
				m_count = count;
		}
	}
}

void LED::reset() {
	digitalWrite(m_port, m_pin, m_lo);
	m_state = kBlinkOff;
	m_start = millis();
}

void LED::breath(uint32_t interval) {
	if ((millis() - m_start) > interval) {
		switch (m_state) {
			case kBreathIn:
				#if defined(ARDUINO_ARCH_ESP32)
				ledcWrite(m_pin, m_count);
				#else
				analogWrite(m_pin, m_count);
				#endif
				if (++m_count == 255) {
					m_state = kBreathOut;
				}
				break;
			case kBreathOut:
				#if defined(ARDUINO_ARCH_ESP32)
				ledcWrite(m_pin, m_count);
				#else
				analogWrite(m_pin, m_count);
				#endif
				if (--m_count == 0) {
					m_state = kBreathIn;
				}
				break;
			default:
				m_state = kBreathIn;
				m_count = 0;
		}
		m_start = millis();
	}
}
