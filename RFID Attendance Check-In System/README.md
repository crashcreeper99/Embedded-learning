# RFID Attendance / Check-In System

## Overview

This project uses an ESP32, an MFRC522 RFID reader, and a DS1307 real-time clock to create a basic attendance system. A registered RFID tag can check a person in or out, while the system records the event time and tracks how many registered people are currently inside. An SSD1306 OLED can be used as an optional local display, but all results are also available through the Serial Monitor.

## Features

- Reads 13.56 MHz RFID cards and key fobs
- Matches scanned UIDs against registered users
- Registers Lamar's tag with UID `F9 63 5D 20`
- Alternates between check-in and check-out
- Records the scan time with a DS1307 RTC
- Tracks the number of people currently inside
- Rejects and prints unknown card UIDs
- Prevents one scan from registering repeatedly
- Continues operating through the Serial Monitor if the optional OLED is disconnected

## Parts Used

- ESP32 DevKit V1
- MFRC522 RFID reader
- 13.56 MHz RFID card or key fob
- DS1307 real-time clock module
- Optional 0.96-inch SSD1306 I2C OLED
- Breadboard
- Jumper wires
- USB cable

## Wiring

### MFRC522 RFID reader

| RC522 pin | ESP32 connection |
|---|---|
| SDA / SS | GPIO 5 |
| SCK | GPIO 18 |
| MOSI | GPIO 23 |
| MISO | GPIO 19 |
| RST | GPIO 27 |
| 3.3V | 3V3 |
| GND | GND |
| IRQ | Not connected |

The MFRC522 must be powered from 3.3V, not 5V.

### DS1307 RTC

| RTC pin | ESP32 connection |
|---|---|
| SDA | GPIO 21 |
| SCL | GPIO 22 |
| GND | GND |
| VCC | Module supply |

### Optional SSD1306 OLED

| OLED pin | ESP32 connection |
|---|---|
| SDA | GPIO 21 |
| SCL | GPIO 22 |
| GND | GND |
| VCC | 3.3V |

The RTC and OLED share the ESP32 I2C bus on GPIO 21 and GPIO 22.

## How It Works

The ESP32 communicates with the MFRC522 over SPI. When a tag is presented, the program converts its UID into an uppercase hexadecimal string and compares it with the registered UID list. Lamar's registered tag is `F9 63 5D 20`.

A recognized scan changes the user's stored state. If the user was outside, the scan checks them in. If they were already inside, the next scan checks them out. The DS1307 supplies the event time, and a cooldown prevents the same physical scan from being counted more than once.

The Serial Monitor prints the name, UID, status, date, time, and current number of people inside. If the optional OLED is connected, it provides ready, approved, and denied messages without requiring the Serial Monitor.

## Libraries

- SPI
- MFRC522
- Wire
- RTClib
- Adafruit GFX — only needed with the OLED
- Adafruit SSD1306 — only needed with the OLED

## Core Concepts

- SPI communication
- I2C communication
- RFID identification
- UID registration and comparison
- Real-time clock operation
- State tracking
- Scan debouncing and cooldowns
- Embedded user-interface design

## RTC Setup

The RTC can be synchronized once with the computer's compilation time:

```cpp
rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
```

After setting the clock, this line should be commented out and the program uploaded again so restarting the ESP32 does not reset the time. A working RTC battery maintains time when the ESP32 loses power.

## Result

The completed system successfully recognizes Lamar's RFID tag, changes between check-in and check-out, rejects unregistered tags, and reports attendance information with the scan time.

## Possible Improvements

- Save attendance records to a microSD card
- Send records to a web dashboard or database
- Add separate administrator and user tags
- Replace the DS1307 with a DS3231 for better long-term clock accuracy
- Add Wi-Fi time synchronization
- Add a buzzer or status LEDs
- Create an enrollment mode for adding users without editing the code

## Status

Completed and tested on August 25, 2026.
