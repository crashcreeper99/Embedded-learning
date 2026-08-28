# Wi-Fi Signal Strength Meter

## Overview
This ESP32 project measures the received signal strength (RSSI) of the Wi-Fi network the board is connected to and turns the raw dBm reading into an easy-to-understand signal-quality status. The project is useful for testing Wi-Fi coverage and finding areas where a wireless connection becomes weak.

## Build Goal
Connect the ESP32 to Wi-Fi, continuously read RSSI, and display the current signal strength and quality level.

## Hardware
- ESP32 DEVKIT V1
- SSD1306 OLED display (optional for local display)
- Breadboard
- Jumper wires
- Wi-Fi network

## Core Concepts
- ESP32 Wi-Fi networking
- RSSI and dBm measurements
- Threshold-based classification
- Mapping sensor/network data into a user-friendly display
- Periodic measurements

## How It Works
After connecting to Wi-Fi, the ESP32 reads the network RSSI value. Stronger signals are closer to 0 dBm, while increasingly negative values indicate weaker reception. The program can classify readings as GOOD, FAIR, or WEAK and display the result through the Serial Monitor or OLED.

## Example Behavior
- Strong RSSI -> GOOD
- Medium RSSI -> FAIR
- Weak RSSI -> WEAK

## What I Learned
This project helped me understand that Wi-Fi quality can be measured directly instead of only checking whether the ESP32 is connected. I also practiced converting technical network information into a simple status that a user can understand.

## Stretch Challenge
Track the strongest and weakest RSSI values observed during a session and use the device as a portable Wi-Fi dead-zone finder.
