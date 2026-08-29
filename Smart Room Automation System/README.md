# Smart Room Automation System

## Overview
This project combines multiple sensors and outputs into one room-control system. A PIR sensor detects occupancy, a DHT22 measures temperature, and the ESP32 controls a relay while showing system state on an OLED.

## Hardware
- ESP32 DEVKIT V1
- PIR motion sensor
- DHT22 sensor
- Relay module
- SSD1306 OLED
- Push button
- Jumper wires

## Wiring
- DHT22 DATA -> GPIO 4
- PIR OUT -> GPIO 27
- Relay IN -> GPIO 26
- Mode button -> GPIO 25 to GND
- OLED SDA -> GPIO 21
- OLED SCL -> GPIO 22
- Common GND between modules

## Core Concepts
- Sensor fusion
- State-based control
- Hysteresis
- Automatic vs manual modes
- Multi-module integration
- Human-readable system feedback

## Expected Result
In automatic mode, the system uses occupancy and temperature conditions to decide whether the relay should be active. The OLED reports mode, temperature, occupancy, and output state.

## Safety
Use the relay indicator or a safe low-voltage load for testing. Do not connect household mains voltage for this portfolio build.

## Stretch Goal
Add a true manual-output button, persistent settings, Wi-Fi monitoring, or a web dashboard.

## Portfolio Value
This is a stronger integration project because it combines sensing, decision logic, user input, display output, and actuation into one embedded system.