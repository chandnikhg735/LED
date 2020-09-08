# BlinkLed
An Arduno library to drive status led in multiple modes to aid in multitasking

BlinkLed creates a led object that can be turned on and off within a sketch and the library takes care of the blinking or breathing in the background. There are three diffent modes:

* kBlinkSingle: it turns ON/OFF alternatively.
* kBlinkMultiple: it blinks *count* time, then pauses for *interval* time and repeat.
* kBlinkBreath: it turns ON and then OFF in *breathe* manner. It needs an analogue GPIO output.

See the example for usage.

To install, download the .zip file: https://github.com/markreds81/BlinkLed/archive/master.zip and rename the BlinkLed-master folder to BlinkLed.  Move the BlinkLed folder to your Arduino/libraries folder and restart the Arduino IDE.  This library should work for Arduino IDE v1.0 and newer.
