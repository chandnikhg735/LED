/**
 * LED library, Written by Mark Reds <marco@markreds.it>
 * 
 * Example: BlinkCountLed
 * 
 * In this example a led blinks for count times, then pause.
 * 
 * This is done asynchronously so MCU is not stuck and it 
 * can do other tasks.
 * 
 */

#include <LED.h>

LED led(11);

void setup() {
	
}

void loop() {
	led.blink(3, 1500UL);	// this is an asynchronous method call
}
