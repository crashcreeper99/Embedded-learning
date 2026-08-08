# ESP32 OLED Countdown Timer

## Overview

This project is a digital countdown timer built with an ESP32 DevKit V1, an SSD1306 OLED display, and two push buttons. The timer starts at 1 minute and counts down to zero. One button starts and pauses the timer, while the second button resets it.

## Features

* 1-minute countdown timer
* OLED digital display
* Start/Pause functionality
* Reset functionality
* Displays timer status
* Automatically stops at 00:00
* Displays "TIME'S UP!" when the countdown finishes

## Hardware

* ESP32 DevKit V1
* 0.96" I2C SSD1306 OLED
* 2 push buttons
* Breadboard
* Jumper wires

## Wiring

### OLED

| OLED Pin | ESP32 Pin |
| -------- | --------- |
| VCC      | 3.3V      |
| GND      | GND       |
| SDA      | GPIO 21   |
| SCL      | GPIO 22   |

### Buttons

| Component             | ESP32 Pin |
| --------------------- | --------- |
| Start/Pause Button    | GPIO 19   |
| Reset Button          | GPIO 18   |
| Other side of buttons | GND       |

The buttons use the ESP32's internal pull-up resistors through `INPUT_PULLUP`.

## Software

* Arduino IDE
* ESP32 Board Package
* Adafruit GFX Library
* Adafruit SSD1306 Library

## How It Works

The ESP32 keeps track of the remaining time using `millis()`. Every 1,000 milliseconds, the timer decreases by one second.

The Start/Pause button changes the timer between running and paused states. The Reset button stops the timer and returns it to 1:00.

When the timer reaches zero, the ESP32 automatically stops the countdown and displays "TIME'S UP!".

## What I Learned

* How to create a countdown timer using an ESP32
* How to control an OLED display
* How to use push buttons with `INPUT_PULLUP`
* How to track time with `millis()`
* How to create different program states such as running, paused, and finished
* How to combine input devices, display output, and timing logic into one embedded system

## Future Improvements

* Add buttons to increase and decrease the starting time
* Add a buzzer alarm
* Allow countdowns longer than one minute
* Add a graphical progress bar
* Save the selected countdown time in memory
* Add a menu system for different timer settings
