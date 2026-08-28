# PIR Activity Counter + RTC

## Overview
This ESP32 project combines a PIR motion sensor with a DS1307 real-time clock to count motion events and record when activity was most recently detected.

## Build Goal
Detect individual motion events, increment an activity counter, and show the time of the latest detection.

## Hardware
- ESP32 DEVKIT V1
- HC-SR501 PIR motion sensor
- DS1307 RTC module
- SSD1306 OLED display
- Breadboard
- Jumper wires

## Core Concepts
- Digital sensor input
- Event detection
- Counters and program state
- I2C communication
- RTC timestamps
- Avoiding repeated counts from one continuous detection

## How It Works
The ESP32 monitors the PIR output. When the signal changes from no motion to motion, the program treats that transition as a new event, increments the counter, reads the current time from the DS1307, and updates the display.

## Example Display
Activity: 14
Last: 18:42:11

## What I Learned
This project helped me understand the difference between continuously reading a HIGH signal and detecting a new event. Combining the PIR sensor with an RTC also gave the motion data more meaning by recording when activity occurred.

## Stretch Challenge
Track activity counts by hour so the system can show which time period had the most detected motion.
