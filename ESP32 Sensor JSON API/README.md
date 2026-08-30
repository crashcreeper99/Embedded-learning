# ESP32 Sensor JSON API — Planned Build

> **Status:** Planned / not yet completed.

## Goal
Turn the ESP32 into a small HTTP API server that reads a DHT22 sensor and returns temperature, humidity, and uptime as structured JSON.

## Planned Hardware
- ESP32 DEVKIT V1
- DHT22 sensor
- Jumper wires
- Wi-Fi network

## Planned Wiring
- DHT22 VCC -> 3.3V
- DHT22 DATA -> GPIO 4
- DHT22 GND -> GND
- Add a pull-up resistor on DATA if using a bare DHT22 sensor

## Skills This Build Should Practice
- Wi-Fi networking
- HTTP servers
- REST-style endpoints
- JSON formatting
- Sensor-to-network integration
- Basic API design

## Target Result
Opening `/api/sensor` on the ESP32 should return valid JSON such as:

```json
{
  "temperature_f": 74.8,
  "humidity": 51.2,
  "uptime_ms": 32842
}
```

## Completion Criteria
This project should not be treated as complete until the folder includes working source code, tested endpoint output, a short reflection, and proof of the running build.

## Stretch Goals
Add multiple endpoints, error/status fields, more sensors, or a separate frontend that consumes the API.