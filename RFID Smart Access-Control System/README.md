# RFID Smart Access-Control System

## Overview
This ESP32 project uses an RC522 RFID reader to recognize an authorized card or tag and provide a visual access result. It is designed as a simple embedded access-control system and can be expanded into a door-lock project later.

## Parts Used
- ESP32 DevKit V1
- RC522 RFID reader
- RFID card or key tag
- RGB LED
- 3 × 220Ω resistors
- Breadboard
- Jumper wires
- Optional buzzer

## What It Does
- Reads RFID card/tag UIDs using the RC522 module.
- Compares the scanned UID to an authorized UID stored in the program.
- Shows an access-granted or access-denied result with the RGB LED.
- Can optionally sound a buzzer for feedback.

## Core Concepts
- SPI communication
- RFID identification
- UID comparison
- Access-control logic
- Digital outputs
- Embedded security basics

## Build Notes
The RC522 should be powered from 3.3V, not 5V. After uploading the initial scanner code, the UID of the authorized card can be copied from the Serial Monitor and added to the access-control program.

## Possible Improvements
- Support multiple authorized cards.
- Add an OLED with the user's status.
- Add a servo to operate a physical lock.
- Save access events with timestamps.
- Send access notifications over Wi-Fi.

## Status
Planned for the August 18, 2026 ESP32 project sprint.
