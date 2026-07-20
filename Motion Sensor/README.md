# ESP32 PIR Motion Sensor

## Overview

This project demonstrates how to interface a PIR (Passive Infrared) motion sensor with an ESP32 development board. The ESP32 continuously monitors the sensor's digital output and reports when motion is detected.

## Features

* Detects human movement using a PIR sensor
* Reads digital input from the sensor
* Displays motion status through the Serial Monitor
* Real-time motion detection
* Simple and expandable embedded systems project

## Components

* ESP32 Development Board
* HC-SR501 PIR Motion Sensor
* Breadboard
* Jumper Wires
* USB Cable

## Wiring

| PIR Sensor | ESP32                     |
| ---------- | ------------------------- |
| VCC        | 5V (or 3.3V if supported) |
| GND        | GND                       |
| OUT        | GPIO (project pin)        |

## How It Works

1. The ESP32 initializes the PIR sensor input.
2. The PIR sensor monitors changes in infrared energy.
3. When motion is detected, the sensor output changes from LOW to HIGH.
4. The ESP32 reads the signal and prints **"Motion Detected!"** to the Serial Monitor.
5. When no movement is present, the ESP32 continues monitoring for the next event.

## Skills Learned

* ESP32 GPIO input
* PIR motion sensor operation
* Digital signal processing
* Embedded programming
* Hardware and software integration
* Sensor-based event detection

## Applications

* Home security systems
* Smart lighting
* Motion-activated alarms
* Occupancy detection
* IoT automation
* Wildlife monitoring

## Project Status

✅ Completed

## Reflection

This project helped me understand how embedded systems detect motion using digital sensors. I gained hands-on experience reading sensor inputs, processing real-time events, and integrating hardware with software. It strengthened my knowledge of ESP32 programming and prepared me for more advanced automation and IoT projects.
