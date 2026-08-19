# Ultrasonic Security Alarm

## Overview
This ESP32 project uses an HC-SR04 ultrasonic sensor to detect when an object or person enters a protected distance zone. When the measured distance becomes smaller than the configured threshold, the system activates an alarm indicator.

## Parts Used
- ESP32 DevKit V1
- HC-SR04 ultrasonic sensor
- LED and 220Ω resistor
- Buzzer if available
- Breadboard
- Jumper wires

## What It Does
- Sends ultrasonic pulses from the HC-SR04.
- Measures the echo return time.
- Calculates distance in centimeters.
- Continuously compares the distance against a security threshold.
- Activates an LED and/or buzzer when something enters the protected zone.

## Core Concepts
- Ultrasonic ranging
- Pulse timing
- Distance calculation
- Threshold-based alarms
- Real-time sensor monitoring
- Digital output control

## Build Notes
The HC-SR04 echo signal can reach 5V, while ESP32 GPIO uses 3.3V logic. A voltage divider on the Echo connection is recommended to protect the ESP32 input. The detection threshold can be adjusted in software for different security zones.

## Possible Improvements
- Add an OLED showing live distance and alarm status.
- Add an arming/disarming button.
- Track how many times the alarm is triggered.
- Send a Wi-Fi alert when intrusion is detected.
- Combine it with RFID so authorized users can disable the alarm.

## Status
Planned for the August 18, 2026 ESP32 project sprint.
