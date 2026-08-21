# Smart Room Status Monitor

## Overview
This project combines multiple sensors with an ESP32 to create a simple room-monitoring system. A DHT22 measures temperature and humidity, a PIR sensor detects occupancy, an LDR measures light level, and an SSD1306 OLED displays the room status in real time.

## Components
- ESP32 DevKit V1
- DHT22 temperature and humidity sensor
- PIR motion sensor
- 3-pin LDR/light sensor module
- 0.96-inch SSD1306 I2C OLED
- Breadboard
- Jumper wires

## Wiring
### OLED
| OLED Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### DHT22
| DHT22 Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| DATA | GPIO 4 |
| GND | GND |

### PIR Sensor
| PIR Pin | ESP32 Pin |
|---|---|
| VCC | 5V |
| OUT | GPIO 27 |
| GND | GND |

### LDR Module
| LDR Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| AO | GPIO 34 |

## Libraries
- Wire
- Adafruit GFX
- Adafruit SSD1306
- DHT sensor library

## How It Works
1. The DHT22 measures room temperature and humidity.
2. The PIR sensor reports whether motion is detected.
3. The LDR provides an analog light-level reading.
4. The ESP32 classifies the room as occupied or empty and dark or bright.
5. The OLED displays all of the current room information.

## Calibration
The exact LDR threshold depends on the sensor and room lighting. If covering the light sensor makes its reading increase instead of decrease, reverse the comparison used to classify the room as dark or bright.

## Testing
1. Upload the sketch and verify that the OLED starts.
2. Confirm that temperature and humidity values appear.
3. Move in front of the PIR sensor and verify that the status changes to occupied.
4. Cover and uncover the LDR and verify that the light status changes.
5. Compare the Serial Monitor readings with the OLED display.

## What I Learned
This project helped me combine several sensors in one embedded system instead of testing one component at a time. I practiced digital and analog inputs, I2C communication, environmental sensing, sensor calibration, and presenting multiple readings on a small display.

## Future Improvements
- Add a buzzer or warning LED.
- Log environmental data over time.
- Add a web dashboard.
- Automatically control lights based on occupancy and brightness.
- Add Wi-Fi notifications for unusual room conditions.
