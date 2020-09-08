#include <BlinkLed.h>

#define BLINK_DEMO 2		// <<-- set 1, 2, or 3

BlinkLed led(11);

void setup() {
#if defined(BLINK_DEMO) && BLINK_DEMO == 1
	led.setMode(kBlinkBreath);
	led.setInterval(5UL);
	led.setCount(2);
#elif defined(BLINK_DEMO) && BLINK_DEMO == 2
	led.setMode(kBlinkMultiple);
	led.setInterval(2000UL);
	led.setCount(4);
#else
	led.setMode(kBlinkSingle);
	led.setInterval(1000UL);
#endif
}

void loop() {
	led.loop();
}
