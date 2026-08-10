# ESP32 RTC Digital Clock

## Overview

This project is a real-time digital clock built using an ESP32 DevKit V1, a DS1307 Real-Time Clock (RTC) module, and a 0.96" SSD1306 OLED display.

The DS1307 keeps track of the current time while the ESP32 reads the time and displays it on the OLED.

The project uses two separate I²C buses:
- OLED: GPIO 21 (SDA) and GPIO 22 (SCL)
- DS1307: GPIO 18 (SDA) and GPIO 19 (SCL)

## Features

- Displays hours, minutes, and seconds
- Displays the current date
- Uses a DS1307 RTC for timekeeping
- Updates the OLED every second
- Uses separate I²C buses for the RTC and OLED
- Displays RTC connection status
- Prints the current time to the Serial Monitor

## Components

- ESP32 DevKit V1
- ELEGOO DS1307 RTC Module V03
- 0.96" SSD1306 128x64 OLED I²C display
- Breadboard
- Jumper wires
- RTC battery

## Wiring

### OLED

| OLED | ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### DS1307

| DS1307 | ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 18 |
| SCL | GPIO 19 |
| SQW | Not connected |

## Required Libraries

Install the following libraries through the Arduino IDE Library Manager:

- RTClib by Adafruit
- Adafruit SSD1306
- Adafruit GFX Library

## How It Works

The ESP32 communicates with the DS1307 through I²C.

The DS1307 provides the current:
- Hour
- Minute
- Second
- Month
- Day
- Year

The ESP32 then sends this information to the SSD1306 OLED.

The OLED updates once per second, creating a real-time digital clock.

The project uses two I²C buses so that the OLED and RTC can communicate independently.

## Example Display

```text
    21:30:01

    08/09/2026

      DS1307
