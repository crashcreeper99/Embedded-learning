# ESP32 OLED Display

## Project Overview
This project demonstrates how to interface an ESP32 with a 0.96-inch SSD1306 OLED display using the I2C communication protocol. The ESP32 initializes the display and prints text and graphics, showing how OLED displays can be used for user interfaces in embedded systems.

## Objectives
- Learn I2C communication with the ESP32.
- Connect and configure an SSD1306 OLED display.
- Display text on the OLED screen.
- Understand graphics rendering using the Adafruit SSD1306 and GFX libraries.

## Components Used
- ESP32 DevKit V1
- SSD1306 0.96" OLED Display (I2C)
- Breadboard
- Jumper Wires
- USB Cable
- Computer with Arduino IDE

## Wiring

| OLED Pin | ESP32 Pin |
|----------|-----------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

## Libraries Required
- Adafruit SSD1306
- Adafruit GFX
- Wire

## Features
- Initializes the OLED display.
- Displays custom text.
- Demonstrates I2C communication.
- Uses graphics library for rendering.
- Provides a foundation for future sensor dashboards.

## What I Learned
- How I2C devices communicate with the ESP32.
- How to install and use Arduino libraries.
- How OLED displays render text and graphics.
- The importance of display initialization and memory management.
- How displays improve embedded system usability.

## Possible Improvements
- Display temperature and humidity data.
- Add Wi-Fi status indicators.
- Create menus using push buttons.
- Show sensor graphs.
- Build a real-time monitoring dashboard.

## Skills Practiced
- ESP32 Programming
- Embedded Systems
- I2C Communication
- OLED Graphics
- Arduino Libraries
- Hardware Debugging
- Breadboarding

## Future Applications
This project serves as the foundation for future smart IoT projects where the OLED display can be used to visualize:
- Sensor readings
- Wi-Fi connection status
- IP addresses
- Weather stations
- Smart home systems
- Robotics
- Battery monitoring
