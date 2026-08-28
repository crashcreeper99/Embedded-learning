# RFID + Servo Smart Lock

## Overview
This project combines an ESP32, RC522 RFID reader, and SG90 servo to create a physical access-control system. When an authorized RFID card or tag is scanned, the ESP32 moves the servo to the unlocked position. Unknown tags are rejected.

## Components
- ESP32 DevKit V1
- MFRC522 / RC522 RFID reader
- RFID card or key tag
- SG90 servo
- External regulated 5V supply for the servo
- Breadboard
- Jumper wires

## Main Connections
### RC522
- SDA / SS -> GPIO 5
- SCK -> GPIO 18
- MOSI -> GPIO 23
- MISO -> GPIO 19
- RST -> GPIO 22
- 3.3V -> 3.3V
- GND -> GND

### Servo
- Signal -> GPIO 13
- VCC -> external 5V
- GND -> external supply GND
- External supply GND must also connect to ESP32 GND

## How It Works
1. The ESP32 waits for an RFID card or tag.
2. The RC522 reads its UID.
3. The UID is compared with the authorized UID stored in the program.
4. An authorized scan moves the servo to the unlocked position.
5. After a short delay, the servo returns to the locked position.
6. Unauthorized tags do not unlock the system.

## Core Concepts
- SPI communication
- RFID authentication
- Servo control
- Access-control logic
- External actuator power
- Combining input and output devices

## Testing
1. Read the UID of the card that will be authorized.
2. Add that UID to the program.
3. Scan the authorized card and verify that the servo unlocks.
4. Wait for the servo to return to the locked position.
5. Scan another tag and verify that it remains locked.

## What I Learned
This project builds on basic RFID reading by using identification data to control a real physical output. It also reinforces the importance of powering a servo correctly while sharing a common ground with the ESP32.

## Future Improvements
- Add an OLED status screen.
- Add a buzzer and status LEDs.
- Support multiple users.
- Add RTC timestamps for entry events.
- Log access events to microSD.
- Add Wi-Fi notifications.

## Status
Planned build for the August 27, 2026 catch-up sprint. Do not mark complete until physically built and tested.
