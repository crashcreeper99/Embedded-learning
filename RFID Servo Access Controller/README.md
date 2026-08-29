# RFID Servo Access Controller

## Overview
This project combines RFID authentication with physical actuation. An authorized RFID tag unlocks a servo-controlled mechanism for a short period before returning to the locked position.

## Hardware
- ESP32 DEVKIT V1
- MFRC522 RFID reader
- SG90 servo
- External regulated 5V servo supply
- RFID card/tag
- Jumper wires

## Wiring
RC522:
- SDA/SS -> GPIO 5
- SCK -> GPIO 18
- MOSI -> GPIO 23
- MISO -> GPIO 19
- RST -> GPIO 27
- 3.3V -> 3.3V
- GND -> GND

Servo:
- Signal -> GPIO 13
- Power -> external regulated 5V
- GND -> external GND
- External GND must connect to ESP32 GND

## Core Concepts
- SPI communication
- RFID UID authentication
- Access-control logic
- Servo actuation
- Power-domain grounding

## Expected Result
Authorized RFID tags unlock the servo temporarily. Unknown tags are rejected and leave the system locked.

## Stretch Goal
Add OLED feedback, failed-attempt counting, or a keypad for two-factor authentication.

## Portfolio Value
Builds on RFID knowledge by turning identification into a physical access-control system.