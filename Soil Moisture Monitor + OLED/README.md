# Soil Moisture Monitor + OLED

## Overview
This ESP32 project measures soil moisture and displays the reading on a 0.96-inch SSD1306 OLED. The goal is to turn a raw analog sensor value into a simple, readable moisture status that can be used for plant monitoring.

## Parts Used
- ESP32 DevKit V1
- Soil moisture sensor module
- 0.96-inch SSD1306 OLED (I2C)
- Breadboard
- Jumper wires

## What It Does
- Reads the soil moisture sensor using an ESP32 analog input.
- Converts the sensor reading into an easy-to-understand moisture level.
- Displays the live value and status on the OLED.
- Can classify the soil as dry, normal, or wet depending on calibrated thresholds.

## Core Concepts
- Analog-to-digital conversion (ADC)
- Sensor calibration
- I2C communication
- OLED display output
- Threshold-based decision logic

## Build Notes
The moisture sensor should be calibrated using both dry and wet soil because the raw readings can vary between sensors. The OLED provides a cleaner visual output than using the Serial Monitor alone.

## Possible Improvements
- Add a buzzer or LED warning when the soil is too dry.
- Add Wi-Fi monitoring from a phone or browser.
- Log moisture data over time.
- Add automatic pump control for a basic irrigation system.

## Status
Planned for the August 18, 2026 ESP32 project sprint.
