/**
 * LED library, Written by Mark Reds <marco@markreds.it>
 * 
 * Example: LedOnOff
 * 
 * This example shows how to turn on and off a led.
 * 
 */

#include <LED.h>

LED led(LED_BUILTIN);

void setup() {
	
}

void loop() {
	led.on();
	delay(500);
	led.off();
	delay(500);
}
