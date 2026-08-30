# Smart Room Automation System — Planned Build

> **Status:** Planned / not yet completed.

## Goal
Build a multi-sensor room-control system that combines occupancy sensing, temperature monitoring, user input, display feedback, and relay control on one ESP32.

## Planned Hardware
- ESP32 DEVKIT V1
- PIR motion sensor
- DHT22 sensor
- Relay module
- SSD1306 OLED
- Push button
- Jumper wires

## Planned Wiring
- DHT22 DATA -> GPIO 4
- PIR OUT -> GPIO 27
- Relay IN -> GPIO 26
- Mode button -> GPIO 25 to GND
- OLED SDA -> GPIO 21
- OLED SCL -> GPIO 22
- Common GND between modules

## Skills This Build Should Practice
- Multi-sensor integration
- State-based control
- Hysteresis
- Automatic vs manual modes
- OLED system feedback
- Safe actuator control

## Completion Criteria
This project should not be treated as complete until the folder includes working source code, a tested hardware build, a reflection, and at least one photo or short demo.

## Safety
Use the relay indicator or a safe low-voltage load for testing. Do not connect household mains voltage for this portfolio build.

## Stretch Goals
Add persistent settings, Wi-Fi monitoring, or a web dashboard.