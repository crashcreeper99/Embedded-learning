# RTC Timestamp Event Logger

## Overview
This ESP32 project uses a DS1307 real-time clock to attach an accurate date and time to button-triggered events. Each event can be shown on an OLED and printed to the Serial Monitor, creating a foundation for access logs, sensor logs, and other timestamped systems.

## Components
- ESP32 DevKit V1
- DS1307 RTC module
- SSD1306 OLED
- Push button
- Breadboard
- Jumper wires

## Core Concepts
- Real-time clocks
- I2C communication
- Event detection
- Timestamps
- Button debouncing
- Data logging concepts

## How It Works
1. The ESP32 reads the current time from the DS1307.
2. The system waits for a button event.
3. When the button is pressed, the current date and time are captured.
4. The timestamp is displayed and printed to Serial.
5. Each later event receives a new timestamp.

## Testing
- Verify that the RTC reports the correct current time.
- Press the event button and verify that a timestamp is captured.
- Wait and trigger another event to confirm that the time changes correctly.
- Reset the ESP32 and confirm that the RTC continues keeping time.

## What I Learned
This project helped me understand how real embedded systems record when events happen instead of only reacting to them. Timestamping is useful for security systems, attendance systems, environmental logging, and diagnostics.

## Future Improvements
- Save timestamps to microSD.
- Add event names/types.
- Log RFID scans.
- Add sensor values to each timestamp.
- Download logs through a web interface.

## Status
Planned build for the August 27, 2026 catch-up sprint. Do not mark complete until physically built and tested.
