# Ultrasonic Proximity Alarm

## Overview
This project turns an ESP32 and HC-SR04 ultrasonic sensor into a simple proximity alarm. The ESP32 continuously measures distance and activates a buzzer when an object comes within the selected warning range.

## Components
- ESP32 DevKit V1
- HC-SR04 ultrasonic sensor
- Buzzer
- Breadboard
- Jumper wires
- Resistors for an ECHO voltage divider when available

## Wiring
### HC-SR04
| HC-SR04 Pin | ESP32 Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | GPIO 5 |
| ECHO | GPIO 18 through a voltage divider |

### Buzzer
| Buzzer Pin | ESP32 Pin |
|---|---|
| + | GPIO 25 |
| - | GND |

> The HC-SR04 ECHO output can reach about 5V, so reducing it before it reaches the ESP32 input is safer.

## How It Works
1. The ESP32 sends a short pulse from the TRIG pin.
2. The HC-SR04 sends an ultrasonic pulse and returns an ECHO pulse.
3. The ESP32 converts the pulse duration into distance in centimeters.
4. If the measured distance is less than about 15 cm, the buzzer turns on.
5. When the object moves away, the buzzer turns off.

## Testing
1. Upload the sketch and open the Serial Monitor at 115200 baud.
2. Verify that distance measurements appear.
3. Move your hand toward the sensor.
4. Confirm that the buzzer activates inside the warning distance.
5. Move your hand away and confirm that the buzzer stops.

## What I Learned
This project helped me practice ultrasonic distance measurement, timing pulses, converting sensor readings into physical units, and using sensor data to trigger an output automatically.

## Future Improvements
- Make the buzzer beep faster as an object gets closer.
- Add an OLED distance display.
- Add LEDs for safe, warning, and danger zones.
- Turn it into a parking or obstacle-detection system.
