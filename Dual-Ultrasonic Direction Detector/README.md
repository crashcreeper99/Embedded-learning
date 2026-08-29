# Dual-Ultrasonic Direction Detector

## Overview
This project uses two HC-SR04 ultrasonic sensors to determine movement direction. If sensor A triggers before sensor B, the system counts an entry. If sensor B triggers before sensor A, it counts an exit.

## Hardware
- ESP32 DEVKIT V1
- 2x HC-SR04 ultrasonic sensors
- Resistors for two Echo voltage dividers
- Jumper wires
- Optional SSD1306 OLED

## Wiring
Sensor A:
- TRIG -> GPIO 5
- ECHO -> GPIO 18 through voltage divider

Sensor B:
- TRIG -> GPIO 17
- ECHO -> GPIO 16 through voltage divider

Both sensors:
- VCC -> 5V
- GND -> GND

## Core Concepts
- Multi-sensor coordination
- Sequence detection
- Finite-state machines
- Occupancy counting
- Timing and sensor spacing

## Expected Result
A pass from A to B increments occupancy as ENTER. A pass from B to A decrements occupancy as EXIT.

## Stretch Goal
Add an OLED display showing current occupancy and total entries/exits.

## Portfolio Value
Demonstrates state-machine logic and multi-sensor reasoning rather than a single-sensor demo.