# LED Bar Graph

## Overview

This project creates a five-level LED bar graph controlled by a potentiometer. Turning the potentiometer changes the ESP32's analog reading and controls how many LEDs are illuminated.

## Components

- ESP32 DevKit V1
- Potentiometer
- 5 LEDs
- 5 current-limiting resistors (220–330 ohms)
- Breadboard
- Jumper wires
- USB cable

## Wiring

| Component | ESP32 connection |
|---|---|
| Potentiometer center pin | GPIO 34 |
| Potentiometer outside pin | 3.3V |
| Other potentiometer outside pin | GND |
| LED 1 anode | GPIO 15 through a resistor |
| LED 2 anode | GPIO 5 through a resistor |
| LED 3 anode | GPIO 18 through a resistor |
| LED 4 anode | GPIO 19 through a resistor |
| LED 5 anode | GPIO 22 through a resistor |
| All LED cathodes | GND |

The potentiometer is powered from 3.3V so its output remains safe for the ESP32 analog input.

## How It Works

GPIO 34 reads the potentiometer from approximately 0 to 4095. The `map()` function converts that reading into an LED level. A loop compares each LED position with the selected level and turns on the correct number of LEDs.

As the potentiometer is turned upward, the LEDs illuminate in order. Turning it downward reduces the number of illuminated LEDs.

## Software

- Arduino IDE
- ESP32 board package
- Arduino C/C++

No additional library is required.

## Testing

1. Upload `Bar.c++` to the ESP32.
2. Open the Serial Monitor at 115200 baud.
3. Slowly rotate the potentiometer from one end to the other.
4. Confirm that the analog value changes from low to high.
5. Verify that the LED bar moves through all five levels.

## Applications

The same idea can be used for:

- Battery-level indicators
- Volume meters
- Temperature ranges
- Sensor-strength displays
- Control-panel indicators

## Result

The ESP32 successfully converted the potentiometer's analog value into a five-level LED display.
