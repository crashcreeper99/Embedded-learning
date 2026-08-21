# RFID Card/Tag UID Reader

## Overview
This project uses an ESP32 and an RC522 RFID reader to detect RFID cards or tags and print each tag's unique identifier (UID) in the Serial Monitor. It is a simple introduction to RFID systems and SPI communication.

## Components
- ESP32 DevKit V1
- MFRC522 / RC522 RFID reader
- RFID card or key tag
- Breadboard
- Jumper wires
- USB cable

## Wiring
| RC522 Pin | ESP32 Pin |
|---|---|
| SDA / SS | GPIO 5 |
| SCK | GPIO 18 |
| MOSI | GPIO 23 |
| MISO | GPIO 19 |
| IRQ | Not connected |
| GND | GND |
| RST | GPIO 22 |
| 3.3V | 3.3V |

> Important: Power the RC522 from 3.3V, not 5V.

## Libraries
- SPI
- MFRC522

## How It Works
1. The ESP32 initializes the SPI bus and RC522 reader.
2. The reader waits for an RFID card or tag.
3. When a tag is detected, the ESP32 reads its UID.
4. The UID is printed to the Serial Monitor in hexadecimal format.

## Testing
1. Upload the sketch to the ESP32.
2. Open the Serial Monitor at 115200 baud.
3. Place an RFID card or tag near the RC522 antenna.
4. Confirm that a UID appears in the Serial Monitor.
5. Test another tag and confirm that it produces a different UID.

## What I Learned
This project helped me practice SPI wiring, using an external communication module, and reading identification data from RFID tags. It also showed me how RFID systems can be used as the first step toward access-control and authentication projects.

## Future Improvements
- Store an authorized UID and reject unknown tags.
- Add LEDs or a buzzer for accepted/rejected scans.
- Add an OLED display.
- Build a complete RFID access-control system.
