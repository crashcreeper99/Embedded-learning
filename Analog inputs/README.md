# ESP32 Analog Inputs

## Overview

This project demonstrates how to read analog sensor values using the ESP32's built-in Analog-to-Digital Converter (ADC). A potentiometer is connected to an analog input pin, allowing the ESP32 to measure varying voltage levels and display the corresponding digital values through the Serial Monitor.

## Objectives

* Learn how the ESP32 reads analog signals.
* Understand Analog-to-Digital Conversion (ADC).
* Practice wiring a potentiometer to an ESP32.
* Display real-time sensor values using the Serial Monitor.

## Components Used

* ESP32 Development Board
* Breadboard
* Potentiometer (10kΩ)
* Jumper Wires
* USB Cable

## Wiring

| ESP32 Pin | Component            |
| --------- | -------------------- |
| 3.3V      | Potentiometer VCC    |
| GND       | Potentiometer GND    |
| GPIO34    | Potentiometer Signal |

## Features

* Reads analog values continuously.
* Displays values from approximately 0–4095.
* Demonstrates real-time sensor input.
* Forms the foundation for future sensor-based projects.

## What I Learned

* How analog sensors differ from digital sensors.
* How the ESP32 converts voltage into digital values.
* How potentiometer position affects ADC readings.
* How to monitor live sensor data using the Serial Monitor.

## Future Improvements

* Control LED brightness using analog input.
* Display readings on an OLED display.
* Smooth noisy readings using averaging.
* Use analog values to control motors or servos.

## Reflection

This project helped me understand how the ESP32 reads analog signals from sensors. Watching the ADC values change in real time made it easier to understand how voltage is converted into digital data. This knowledge will be important for future embedded systems projects involving sensors, robotics, automation, and Internet of Things (IoT) applications.
