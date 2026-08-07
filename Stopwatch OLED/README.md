# Digital Stopwatch with OLED Display (ESP32)

## Project Overview

This project is a digital stopwatch built with an ESP32 and a 0.96-inch I2C OLED display. The stopwatch can start, pause, and reset using two push buttons. It demonstrates how to use timers without blocking code by utilizing the `millis()` function.

## Features

* Displays elapsed time in minutes, seconds, and milliseconds.
* Start and pause functionality using a push button.
* Reset functionality using a second push button.
* Real-time updates on a 128×64 OLED display.
* Uses non-blocking timing with `millis()`.

## Components Used

* DOIT ESP32 DEVKIT V1
* 0.96" SSD1306 I2C OLED Display
* 2 Push Buttons
* Breadboard
* Jumper Wires

## Wiring

### OLED Display

* VCC → 3.3V
* GND → GND
* SDA → GPIO 21
* SCL → GPIO 22

### Buttons

**Start/Pause Button**

* One leg → GPIO 19
* Other leg → GND

**Reset Button**

* One leg → GPIO 18
* Other leg → GND

The buttons use the ESP32's internal pull-up resistors (`INPUT_PULLUP`), so no external resistors are required.

## How It Works

1. Press the Start/Pause button (GPIO 19) to begin timing.
2. Press the same button again to pause the stopwatch.
3. Press the Reset button (GPIO 18) to reset the timer back to 00:00:000.
4. The OLED continuously displays the elapsed time and indicates whether the stopwatch is running or paused.

## Skills Learned

* Programming with the ESP32
* Using I2C communication
* Interfacing with an SSD1306 OLED display
* Reading push button inputs
* Implementing non-blocking timing using `millis()`
* Creating simple user interfaces on embedded systems
* Managing program state (running, paused, reset)

## Future Improvements

* Add lap/split time functionality.
* Store lap times in memory.
* Add a buzzer for button feedback.
* Include battery operation for portability.
* Build a menu system with additional stopwatch modes.

