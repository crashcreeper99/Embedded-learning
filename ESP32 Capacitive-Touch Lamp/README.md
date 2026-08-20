# ESP32 Capacitive-Touch Lamp

## Overview

This project turns the ESP32's built-in capacitive-touch capability into a touch-controlled lamp. Touching a jumper wire or conductive foil connected to a touch-capable GPIO toggles an LED on or off without using a mechanical button.

## Features

- Detects a finger through capacitive touch
- Toggles the lamp between on and off
- Prevents one touch from causing repeated toggles
- Prints touch readings to the Serial Monitor for calibration
- Uses the ESP32's built-in touch hardware

## Parts Used

- ESP32 DevKit V1
- LED
- 220–330 ohm resistor
- Jumper wire or small piece of conductive foil
- Breadboard
- USB cable

## Wiring

| Component | ESP32 connection |
|---|---|
| Touch wire or foil | GPIO 4 |
| LED anode | GPIO 16 through a 220–330 ohm resistor |
| LED cathode | GND |

The loose end of the GPIO 4 jumper wire acts as the touch pad. Conductive foil can be attached to make a larger touch surface.

## How It Works

The ESP32 uses `touchRead()` to measure the capacitive value on GPIO 4. A finger changes that value. When the reading crosses the selected threshold, the program toggles the LED.

A lockout variable makes the program wait until the touch pad is released before accepting another touch. This prevents one long touch from rapidly switching the lamp on and off.

## Calibration

The normal and touched readings should first be observed in the Serial Monitor. The touch threshold must be placed between those two typical values. If the lamp activates by itself, the threshold should be adjusted.

## Core Concepts

- Capacitive sensing
- Threshold calibration
- State toggling
- Software debouncing and lockout
- Digital output control

## Result

The completed project successfully toggled the LED each time the touch wire or foil was touched and released.

## Possible Improvements

- Add PWM brightness adjustment
- Use a larger metal touch pad
- Add multiple touch pads for brightness and color
- Control an RGB LED
- Add an automatic shutoff timer

## Status

Completed and tested on August 20, 2026.
