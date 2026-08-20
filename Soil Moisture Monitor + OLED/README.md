# Soil Moisture Monitor + OLED

## Overview

This project uses an ESP32, an analog soil-moisture sensor, and a 0.96-inch SSD1306 OLED to measure soil moisture and display a live percentage and condition. It turns a raw analog sensor reading into a simple plant-monitoring tool.

## Features

- Reads the sensor through the ESP32 ADC
- Converts the raw reading into a 0–100% moisture estimate
- Displays the percentage on the OLED
- Labels the soil as dry, good, or very wet
- Prints raw and converted readings to the Serial Monitor for calibration

## Parts Used

- ESP32 DevKit V1
- Soil-moisture sensor module
- 0.96-inch SSD1306 I2C OLED
- Breadboard
- Jumper wires
- USB cable

## Wiring

### Soil-moisture sensor

| Sensor pin | ESP32 connection |
|---|---|
| VCC | 3.3V |
| GND | GND |
| AO | GPIO 34 |

### OLED

| OLED pin | ESP32 connection |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## How It Works

The ESP32 reads the sensor's analog output on GPIO 34. The program maps the calibrated dry and wet readings to a percentage between 0 and 100. It then uses thresholds to classify the soil and updates the OLED once per second.

The dry and wet calibration values may need to be changed because moisture probes do not all produce identical readings.

## Core Concepts

- Analog-to-digital conversion
- Sensor calibration
- Value mapping and constraints
- I2C communication
- OLED output
- Threshold-based decisions

## Libraries

- Adafruit GFX
- Adafruit SSD1306
- Wire

## Result

The completed system successfully showed live moisture information on the OLED and changed its displayed condition based on the sensor reading.

## Possible Improvements

- Add an LED or buzzer for dry-soil warnings
- Save readings to a microSD card
- Add a web dashboard
- Control a small water pump through a relay
- Average several readings for a steadier percentage

## Status

Completed and tested on August 20, 2026.
