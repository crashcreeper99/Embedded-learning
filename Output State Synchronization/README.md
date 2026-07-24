# ESP32 Output State Synchronization

## Overview
This project demonstrates how to synchronize multiple output devices using an ESP32 microcontroller. Multiple LEDs are controlled so that they change states together according to programmed logic. This project introduces coordinated digital output control, an important concept in embedded systems and automation.

## Objectives
- Learn how to control multiple GPIO outputs.
- Synchronize output state changes.
- Practice using digitalWrite() with multiple devices.
- Understand how coordinated outputs are used in embedded systems.

## Components
- ESP32 Development Board
- Breadboard
- 3 LEDs (Red, Yellow, Green)
- 3 × 220Ω Resistors
- Jumper Wires
- USB Cable

## Wiring

| ESP32 GPIO | Component |
|------------|-----------|
| GPIO 13 | Red LED |
| GPIO 12 | Yellow LED |
| GPIO 14 | Green LED |
| GND | Common Ground |

Each LED is connected in series with a 220Ω resistor.

## How It Works
The ESP32 updates all output pins together so each LED changes state in synchronization. The outputs can all turn on, all turn off, or follow a predefined synchronized sequence depending on the program logic.

Example flow:

1. Initialize output pins.
2. Set all LEDs LOW.
3. Turn all LEDs HIGH simultaneously.
4. Wait for a delay.
5. Turn all LEDs LOW.
6. Repeat continuously.

## Skills Learned
- GPIO output programming
- Digital output synchronization
- Embedded timing
- Coordinated hardware control
- Writing organized Arduino code

## Applications
- Industrial automation
- Smart lighting
- Status indicator systems
- Robotics
- Traffic signal controllers
- Home automation

## Future Improvements
- Synchronize LEDs using hardware timers.
- Add push-button control.
- Control outputs through Wi-Fi.
- Create custom synchronization patterns.
- Display output status on a web page.

## Author
Lamar Holloway

Computer & Electrical Engineering Student
Loyola University Maryland
