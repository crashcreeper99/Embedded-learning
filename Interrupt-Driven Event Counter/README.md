# Interrupt-Driven Event Counter

## Overview
This project counts button events using a hardware interrupt instead of continuously polling the input in the main loop.

## Hardware
- ESP32 DEVKIT V1
- Push button
- SSD1306 OLED
- Jumper wires

## Wiring
- Button -> GPIO 27 to GND
- OLED SDA -> GPIO 21
- OLED SCL -> GPIO 22
- OLED VCC -> 3.3V
- OLED GND -> GND

## Core Concepts
- Hardware interrupts
- ISR design
- volatile variables
- Debouncing
- Safe shared-data access

## Expected Result
Each valid button press increments a counter, while the display is updated outside the interrupt service routine.

## Stretch Goal
Measure event timing or compare interrupt-driven response with a polling-based implementation.

## Portfolio Value
Demonstrates lower-level event handling and embedded concurrency concepts beyond basic digital input polling.