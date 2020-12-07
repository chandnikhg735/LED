# mrLED
This library allows an Arduino board to control LEDs.

A LED object has many useful methods to make it blinking or breathing in non blocking mode.

## Example

```c++
#include <LED.h>

LED led(11);

void setup() {

}

void loop() {
	led.blink(500UL);	// this is an asynchronous method call
}
```
See other examples for usage.

## Documentation

### Construction

```c++
LED led1(11);
LED led2(12, HIGH, LOW);
```
Pass the GPIO number as argument or 1) the GPIO number, 2) the value to switch on and 3) the value to switch off.

### Functions

```c++
void on(void);
```
Switch the led ON.

```c++
void off(void);
```
Switch the led OFF.

```c++
void blink(uint32_t interval);
```
Make the led blinking ON and OFF with a pause of `interval` milliseconds. This function call is asynchronous.

```c++
void blink(uint8_t count, uint32_t pause, uint32_t timeOn = 180UL, uint32_t timeOff = 120UL);
```
Make the led blinking ON and OFF `count` times, then pauses for `interval` milliseconds. If desired it is possible to specify the ON and OFF stated duration passing a value to `timeOn` and `timeOff` parameters. This function call is asynchronous.

```c++
void breath(uint32_t interval);
```
Make the led "breathing". It requires a PWM GPIO. `interval` value make the transition slower or faster. This function call is asynchronous.

```c++
uint8_t state(void);
```
Return the current state of the LED object. It could be one of the following values:
* `kSwitchOff`: the led is currently switched OFF (after a call to `off()` function).
* `kSwitchOn`: the led is currently switched ON (after a call to `on()` function).
* `kBlinkOn`: the led is blinking ON (a call to `blink()` function has occurred).
* `kBlinkOff`: the led is blinkg OFF (a call to `blink()` function has occurred).
* `kBlinkPause`: the led has blinked and it is currently paused (a call to `blink(count ...)` function has occurred).
* `kBreathIn`: the led is currently breathing in (a call to `breathe()` function has occurred).
* `kBreathOut`: the led is currently breathing out (a call to `breathe()` function has occurred).

## Installation

To install, download the .zip file: https://github.com/markreds81/LED/archive/master.zip and rename the *LED-master* folder to *LED*.  Move the *LED* folder to your *Arduino/libraries* folder and restart the Arduino IDE.  This library should work on Arduino IDE v1.5 and later.

## License

Copyright (C) 2020 Marco Rossi (aka Mark Reds).  All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library. If not, see <http://www.gnu.org/licenses/>.