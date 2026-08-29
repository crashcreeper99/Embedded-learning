# ESP32 Sensor JSON API

## Overview
This project turns the ESP32 into a small HTTP API server. A DHT22 sensor provides temperature and humidity data, which the ESP32 returns as structured JSON at an API endpoint.

## Hardware
- ESP32 DEVKIT V1
- DHT22 sensor
- Jumper wires
- Wi-Fi network

## Wiring
- DHT22 VCC -> 3.3V
- DHT22 DATA -> GPIO 4
- DHT22 GND -> GND
- Add a pull-up resistor on DATA if using a bare DHT22 sensor

## Core Concepts
- Wi-Fi networking
- HTTP servers
- REST-style endpoints
- JSON data formatting
- Sensor-to-network integration
- Basic backend/API architecture

## Expected Result
Opening `/api/sensor` on the ESP32's IP address returns JSON containing temperature, humidity, and uptime data.

Example:
```json
{
  "temperature_f": 74.8,
  "humidity": 51.2,
  "uptime_ms": 32842
}
```

## Stretch Goal
Add multiple endpoints, error/status fields, additional sensors, or a separate frontend that consumes the API.

## Portfolio Value
Demonstrates embedded networking and API design rather than only serving a static web page.