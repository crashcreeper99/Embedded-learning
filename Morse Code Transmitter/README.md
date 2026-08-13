# Morse Code Transmitter

## Overview

This project uses an ESP32, a push button, and an LED to transmit the Morse code distress signal SOS. Pressing the button starts the sequence of three dots, three dashes, and three dots:

`... --- ...`

## Components

- ESP32 DevKit V1
- Push button
- LED
- Current-limiting resistor (220–330 ohms)
- Breadboard
- Jumper wires
- USB cable

## Wiring

| Component | ESP32 connection |
|---|---|
| LED anode | GPIO 18 through a resistor |
| LED cathode | GND |
| Button leg 1 | GPIO 23 |
| Button leg 2 | GND |

The button uses the ESP32's internal pull-up resistor.

## Morse Timing

The project uses a dot duration of 200 milliseconds.

| Signal | Duration |
|---|---:|
| Dot | 200 ms |
| Dash | 600 ms |
| Gap inside a letter | 200 ms |
| Additional gap between letters | 400 ms |
| Pause after SOS | 1200 ms |

## How It Works

The code separates the transmitter into reusable functions:

- `signalOn()` controls one flash.
- `dot()` sends a short flash.
- `dash()` sends a long flash.
- `sendS()` sends three dots.
- `sendO()` sends three dashes.
- `sendSOS()` combines the letters into the complete message.

The sequence starts once when the button changes from HIGH to LOW.

## Software

- Arduino IDE
- ESP32 board package
- Arduino C/C++

No additional library is required.

## Testing

1. Upload `SOS.c++` to the ESP32.
2. Press and release the button.
3. Watch for three short flashes, three long flashes, and three short flashes.
4. Confirm that the sequence does not restart continuously while the button remains held.

## Applications

The same structure could be expanded to transmit:

- Names and short messages
- Emergency signals
- Training patterns
- Optical communication signals

## Result

The ESP32 successfully transmitted SOS through the LED using recognizable Morse code timing.
