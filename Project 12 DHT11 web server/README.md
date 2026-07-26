# ESP32 DHT11 Web Server

## Overview
This project creates an ESP32-based web server that reads temperature and humidity data from a DHT11 sensor and displays the information on a web page.

The ESP32 connects to Wi-Fi and hosts a local webpage where users can view real-time environmental data collected from the DHT11 sensor.

## Features
- ESP32 Wi-Fi connectivity
- Real-time temperature readings
- Real-time humidity readings
- Web-based monitoring interface
- Automatic data updates through HTTP requests
- Low-cost environmental monitoring system

## Hardware Required
- ESP32 DevKit V1
- DHT11 Temperature and Humidity Sensor
- Breadboard
- Jumper wires
- USB cable
- 10kΩ resistor (if using a bare DHT11 sensor instead of a module)

## Wiring

| DHT11 Pin | ESP32 Pin |
|-----------|-----------|
| VCC       | 3.3V      |
| DATA      | GPIO 4    |
| GND       | GND       |

## Software Requirements
- Arduino IDE or PlatformIO
- ESP32 Board Package installed
- Wi-Fi network

## Required Libraries

Install the following libraries through Arduino IDE:

### 1. DHT Sensor Library
**Library Name:**
