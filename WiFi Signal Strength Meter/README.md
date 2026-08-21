# Wi-Fi Signal Strength Meter

## Overview
This project uses the ESP32's built-in Wi-Fi hardware and an SSD1306 OLED display to show the current Wi-Fi signal strength in both dBm and an approximate percentage. It continuously updates while connected to a wireless network.

## Components
- ESP32 DevKit V1
- 0.96-inch SSD1306 I2C OLED
- Breadboard
- Jumper wires
- USB cable
- Wi-Fi network

## Wiring
| OLED Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## Libraries
- WiFi
- Wire
- Adafruit GFX
- Adafruit SSD1306

## How It Works
1. The ESP32 connects to the configured Wi-Fi network.
2. `WiFi.RSSI()` reads the received signal strength in dBm.
3. The program maps the RSSI value to an approximate percentage.
4. The OLED shows the percentage and raw dBm reading.
5. The display updates repeatedly so changes can be seen while moving farther from or closer to the router.

## Testing
1. Enter the Wi-Fi SSID and password in the sketch.
2. Upload the program to the ESP32.
3. Confirm that the OLED shows a signal percentage and dBm value.
4. Walk farther from the router and watch the signal decrease.
5. Move closer and confirm that the signal improves.

## What I Learned
This project helped me understand RSSI, Wi-Fi signal strength, I2C OLED communication, and how to turn raw network information into a simple real-time user interface.

## Future Improvements
- Draw a graphical signal bar on the OLED.
- Show the connected network name and ESP32 IP address.
- Log signal strength over time.
- Build a Wi-Fi dead-zone finder.
