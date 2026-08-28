# Ultrasonic Fill-Level Monitor

## Overview
This project uses an HC-SR04 ultrasonic sensor with an ESP32 to estimate how full a container is. Instead of only displaying distance, the system converts the measured distance into a useful fill percentage.

## Build Goal
Calibrate an empty and full distance, measure the current distance to the contents of a container, and display an estimated level from 0% to 100%.

## Hardware
- ESP32 DEVKIT V1
- HC-SR04 ultrasonic sensor
- SSD1306 OLED display
- Breadboard
- Jumper wires
- Voltage-divider resistors for the HC-SR04 Echo signal when needed

## Core Concepts
- Ultrasonic distance measurement
- Calibration
- Mapping values into percentages
- Sensor filtering
- Threshold-based alerts
- Embedded user interfaces

## How It Works
The HC-SR04 sends an ultrasonic pulse and measures how long the echo takes to return. The ESP32 calculates the distance and compares it with calibrated empty and full distances. The result is converted into a fill percentage and can be displayed on the OLED.

## Example Display
Level: 68%
Status: OK

## What I Learned
This project helped me move beyond displaying raw sensor distance. I practiced calibration and converting a physical measurement into information that is more useful for a real application.

## Stretch Challenge
Add LOW, OK, and FULL states and trigger an LED or buzzer when the measured level reaches a critical threshold.
