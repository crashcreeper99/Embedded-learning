# Multi-Sensor Room Automation Controller

## Overview
This project combines multiple ESP32 inputs with an output device to create a more complete embedded control system. PIR motion and DHT22 environmental readings are used together to make automatic relay-control decisions, with system information displayed locally.

## Build Goal
Create an automatic room controller that considers both occupancy and environmental conditions before switching a relay-controlled device.

## Hardware
- ESP32 DEVKIT V1
- HC-SR501 PIR motion sensor
- DHT22 temperature/humidity sensor
- Relay module
- SSD1306 OLED display
- Optional push button
- Breadboard
- Jumper wires

## Core Concepts
- Multi-sensor integration
- Sensor fusion
- State-machine logic
- Relay/actuator control
- Thresholds and hysteresis
- Non-blocking timing
- Embedded user feedback

## System Flow
PIR + DHT22 -> ESP32 decision logic -> relay output -> OLED status

The controller reads occupancy and environmental conditions, applies the programmed automation rules, and decides whether the relay should be on or off. Hysteresis can be used around environmental thresholds to prevent rapid relay switching.

## Example States
- ROOM EMPTY - Relay OFF
- OCCUPIED - Monitoring
- AUTO ACTIVE - Relay ON

## What I Learned
This project helped me practice designing a system where multiple inputs influence one decision. It is a step beyond controlling an output directly from one sensor because the ESP32 has to maintain state and evaluate several conditions before acting.

## Stretch Challenge
Add AUTO and MANUAL modes. In AUTO mode, the ESP32 makes the decision from sensor readings. In MANUAL mode, a push button lets the user control the relay while the OLED clearly displays the selected mode.
