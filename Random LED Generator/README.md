# Random LED Generator

## Overview

This project uses an ESP32 to select one of four LEDs at random. Every half-second, the previous LED turns off and a new LED is selected and illuminated.

## Components

- ESP32 DevKit V1
- 4 LEDs
- 4 current-limiting resistors (220–330 ohms)
- Breadboard
- Jumper wires
- USB cable

## Wiring

| Component | ESP32 connection |
|---|---|
| LED 1 anode | GPIO 15 through a resistor |
| LED 2 anode | GPIO 5 through a resistor |
| LED 3 anode | GPIO 18 through a resistor |
| LED 4 anode | GPIO 19 through a resistor |
| All LED cathodes | GND |

## How It Works

The program stores the four LED pins in an array. At the beginning of each loop, every LED is turned off. The `random()` function then chooses an array position from 0 through 3, and the selected LED turns on for 500 milliseconds.

The program uses an unused analog reading from GPIO 34 to seed the random-number generator. The Serial Monitor displays which LED was selected.

## Software

- Arduino IDE
- ESP32 board package
- Arduino C/C++

No additional library is required.

## Testing

1. Upload `Random.c++` to the ESP32.
2. Open the Serial Monitor at 115200 baud.
3. Watch the four LEDs for several cycles.
4. Confirm that only one LED is on at a time.
5. Compare the physical LED with the number printed in the Serial Monitor.

## Applications

This programming method could be adapted for:

- Games and electronic dice
- Random test patterns
- LED effects
- Random selections
- Simulation projects

## Result

The circuit successfully selected and illuminated random LEDs while reporting each selection in the Serial Monitor.
