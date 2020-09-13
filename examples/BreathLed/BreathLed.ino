/**
 * LED library, Written by Mark Reds <marco@markreds.it>
 * 
 * Example: BreathLed
 * 
 * This example shows how to make a led "breathing".
 * Please note you need an analogue output pin.
 * 
 */

#include <LED.h>

LED led(11);			// Pin 11 is PWM capable

void setup() {
	
}

void loop() {
	led.breath(2UL);	// this is an asynchronous method call
}
