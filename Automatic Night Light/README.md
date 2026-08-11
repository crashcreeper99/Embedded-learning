# Automatic Night Light

## Overview

The Automatic Night Light is an ESP32-based project that automatically turns an LED on when the surrounding environment becomes dark and turns it off when there is enough light.

The project uses an **LDR (Light Dependent Resistor) sensor module** to measure the amount of light around it. The ESP32 reads the sensor value and controls the LED based on a programmed light threshold.

## Components

* ESP32 DevKit V1
* 3-pin LDR sensor module
* LED
* 220Ω resistor
* Breadboard
* Jumper wires

## Wiring

### LDR Module

| LDR Pin     | ESP32   |
| ----------- | ------- |
| VCC / +     | 3.3V    |
| GND / -     | GND     |
| Signal / AO | GPIO 34 |

### LED

| LED           | ESP32                   |
| ------------- | ----------------------- |
| Long leg (+)  | 220Ω resistor → GPIO 25 |
| Short leg (-) | GND                     |

## How It Works

1. The LDR measures the surrounding light level.
2. The ESP32 reads the LDR value through GPIO 34.
3. The program compares the reading to a programmed threshold.
4. When the environment becomes dark, the ESP32 turns the LED on.
5. When the environment becomes bright, the ESP32 turns the LED off.
6. The light level can also be viewed through the Serial Monitor.

## Software

* Arduino IDE
* ESP32 Board Package
* C/C++ Arduino programming

## Main Pins

```text
LDR Signal → GPIO 34
LED → GPIO 25
```

## Features

* Automatic light detection
* Automatic LED control
* Adjustable darkness threshold
* Serial Monitor light-level readings
* Simple and inexpensive circuit

## Applications

This project demonstrates how an automatic lighting system could be used for:

* Bedroom night lights
* Hallway lighting
* Outdoor lighting
* Security lighting
* Smart-home systems

## What I Learned

This project helped me practice using an analog sensor with the ESP32. I learned how to read changing sensor values, use a threshold to make decisions, and control an output based on environmental conditions.
