# Ultrasonic Height Meter

## Overview
This project uses an ESP32 and HC-SR04 ultrasonic sensor to measure distance and convert it into an estimated object/person height when the sensor is mounted at a known reference height. An OLED can display the result in real time.

## Components
- ESP32 DevKit V1
- HC-SR04 ultrasonic sensor
- SSD1306 OLED
- Breadboard
- Jumper wires
- Resistors for an ECHO voltage divider

## How It Works
1. The ESP32 triggers the HC-SR04.
2. The sensor returns the echo travel time.
3. The ESP32 calculates the distance from the sensor to the target.
4. With the sensor mounted at a known height, target height is calculated as reference height minus measured distance.
5. The result is displayed in centimeters on the OLED and/or Serial Monitor.

## Core Concepts
- Ultrasonic ranging
- Pulse timing
- Unit conversion
- Calibration
- Real-world measurement
- OLED data presentation

## Important Note
The HC-SR04 ECHO signal can be approximately 5V. Use a voltage divider before connecting ECHO to an ESP32 GPIO input.

## Testing
- Measure a known distance with a ruler and compare it with the sensor reading.
- Calibrate the reference mounting height.
- Test objects of several known heights.
- Adjust the calibration if necessary.

## What I Learned
This project goes beyond displaying raw distance by using a calibrated reference measurement to calculate a useful physical quantity.

## Future Improvements
- Add inches and centimeters modes.
- Average several readings for stability.
- Store maximum/minimum measurements.
- Add a button for recalibration.

## Status
Planned build for the August 27, 2026 catch-up sprint. Do not mark complete until physically built and tested.
