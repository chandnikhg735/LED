/**
 * LED library, Written by Mark Reds <marco@markreds.it>
 * 
 * Example: BlinkLed
 * 
 * This example shows how to make a led blinking on and off.
 * This is done asynchronously so MCU is not stuck and it 
 * can do other tasks.
 * 
 */

#include <LED.h>

LED led(11);

void setup() {

}

void loop() {
	led.blink(500UL);	// this is an asynchronous method call
}
