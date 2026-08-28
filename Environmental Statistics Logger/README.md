# Environmental Statistics Logger

## Overview
This project turns the ESP32, DHT22, DS1307 RTC, and OLED into a small environmental data-acquisition system. Instead of only showing the latest temperature and humidity values, the program periodically samples the environment and calculates useful statistics.

## Build Goal
Collect timestamped temperature and humidity measurements and maintain minimum, maximum, and average readings during the session.

## Hardware
- ESP32 DEVKIT V1
- DHT22 temperature/humidity sensor
- DS1307 RTC
- SSD1306 OLED display
- Breadboard
- Jumper wires

## Core Concepts
- Environmental sensing
- I2C communication
- RTC timestamps
- Non-blocking scheduling with millis()
- Data acquisition
- Running minimum, maximum, and average calculations
- Structured embedded-system design

## System Flow
DHT22 -> sample -> RTC timestamp -> process data -> update statistics -> OLED

## Example Display
Temp: 75.6 F
Humidity: 49%
AVG: 74.9 F
HIGH: 77.2 F
LOW: 72.8 F

## What I Learned
This project helped me move from simple sensor displays toward data acquisition and analysis. I practiced collecting measurements over time and maintaining statistics while keeping the program responsive instead of relying on long delays.

## Stretch Challenge
Keep a rolling history of the latest 10 readings and display a trend indicator showing whether temperature is rising, falling, or remaining stable.
