# Ultrasonic Fill-Level System

## Overview
This project uses an HC-SR04 ultrasonic sensor to estimate how full a container is. Instead of displaying raw distance only, the ESP32 maps calibrated empty and full distances to a 0-100% level.

## Hardware
- ESP32 DEVKIT V1
- HC-SR04 ultrasonic sensor
- SSD1306 OLED
- 1k and 2k resistors for Echo voltage divider
- Jumper wires

## Wiring
- HC-SR04 VCC -> 5V
- HC-SR04 GND -> GND
- TRIG -> GPIO 5
- ECHO -> GPIO 18 through voltage divider
- OLED SDA -> GPIO 21
- OLED SCL -> GPIO 22
- OLED VCC -> 3.3V
- OLED GND -> GND

## Core Concepts
- Distance measurement
- Calibration
- Data mapping
- Percentage conversion
- Threshold classification
- Sensor safety with 5V-to-3.3V level reduction

## Expected Result
The OLED shows the measured distance, estimated fill percentage, and a status such as LOW, NORMAL, or FULL.

## Stretch Goal
Add a buzzer or LED warning when the level becomes critically low or nearly full.

## Portfolio Value
Shows how raw sensor data can be calibrated and converted into a useful real-world measurement.