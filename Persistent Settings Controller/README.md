# Persistent Settings Controller

## Overview
This project uses the ESP32 Preferences library to store a user setting in nonvolatile flash memory. The setting can be changed with buttons and remains saved after the ESP32 loses power.

## Hardware
- ESP32 DEVKIT V1
- SSD1306 OLED
- 2 push buttons
- Jumper wires

## Wiring
- Up button -> GPIO 25 to GND
- Down button -> GPIO 26 to GND
- OLED SDA -> GPIO 21
- OLED SCL -> GPIO 22
- OLED VCC -> 3.3V
- OLED GND -> GND

## Core Concepts
- Nonvolatile storage
- ESP32 Preferences/NVS
- Persistent configuration
- User input
- Flash-backed settings

## Expected Result
The user can increase or decrease a stored threshold. After unplugging and reconnecting the ESP32, the last saved value is restored automatically.

## Stretch Goal
Store multiple settings such as temperature threshold, display mode, and alarm enable state.

## Portfolio Value
Shows knowledge of persistent embedded configuration rather than relying only on runtime variables.