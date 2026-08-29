# I2C Device Diagnostic Scanner

## Overview
This project turns the ESP32 into a reusable I2C debugging tool. It scans the I2C bus, detects connected devices, and reports their addresses through the Serial Monitor.

## Why This Project Matters
Unlike a normal sensor demo, this project focuses on communication-protocol debugging. It is useful for diagnosing OLEDs, RTC modules, sensors, and other I2C hardware in future projects.

## Hardware
- ESP32 DEVKIT V1
- SSD1306 OLED (optional test device)
- DS1307 RTC (optional test device)
- Jumper wires

## Wiring
- SDA -> GPIO 21
- SCL -> GPIO 22
- Common GND between all devices
- OLED VCC -> 3.3V
- DS1307 VCC -> appropriate module supply

## Core Concepts
- I2C communication
- Device addressing
- Bus scanning
- Hardware troubleshooting
- Shared SDA/SCL bus architecture

## Expected Result
The Serial Monitor lists every responding I2C address. Typical examples are 0x3C for an SSD1306 OLED and 0x68 for a DS1307 RTC.

## Stretch Goal
Add an OLED interface that displays the number and addresses of detected devices without requiring a computer.

## Portfolio Value
Demonstrates practical embedded debugging and understanding of a shared communication bus rather than only using prebuilt libraries.