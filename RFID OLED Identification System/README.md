# RFID OLED Identification System

## Overview
This project combines the ESP32, RC522 RFID reader, and SSD1306 OLED display. When a card or tag is scanned, the system reads its UID and displays identification/access information directly on the OLED instead of relying only on the Serial Monitor.

## Components
- ESP32 DevKit V1
- RC522 RFID reader
- RFID card/key tag
- SSD1306 I2C OLED
- Breadboard
- Jumper wires

## Core Concepts
- SPI communication with the RC522
- I2C communication with the OLED
- RFID UID processing
- User-interface feedback
- Running multiple communication protocols on one ESP32

## How It Works
1. The OLED displays a waiting-for-card message.
2. The RC522 detects an RFID card or tag.
3. The ESP32 reads and formats the UID.
4. The program compares it with known UIDs if identification is enabled.
5. The OLED displays the UID, user name, or access status.
6. The system returns to its waiting screen for the next scan.

## Testing
- Verify that the OLED initializes correctly.
- Scan a tag and confirm its UID appears.
- Scan multiple tags and verify that their UIDs are different.
- Add a known UID and confirm that the correct identity/status appears.

## What I Learned
This project helped me combine SPI and I2C devices in the same embedded system and create a more useful interface for RFID identification.

## Future Improvements
- Store multiple user profiles.
- Add access timestamps using the DS1307 RTC.
- Add a servo lock.
- Add a buzzer and LEDs.
- Save scan history to microSD.

## Status
Planned build for the August 27, 2026 catch-up sprint. Do not mark complete until physically built and tested.
