# LED Binary Counter

## Overview

This project uses an ESP32, four LEDs, and a push button to display decimal numbers from 0 to 15 in four-bit binary. Each press increases the counter by one. After reaching 15, the counter returns to 0.

## Components

- ESP32 DevKit V1
- 4 LEDs
- 4 current-limiting resistors (220–330 ohms)
- Push button
- Breadboard
- Jumper wires
- USB cable

## Wiring

| Component | ESP32 connection |
|---|---|
| 1s LED anode | GPIO 15 through a resistor |
| 2s LED anode | GPIO 5 through a resistor |
| 4s LED anode | GPIO 18 through a resistor |
| 8s LED anode | GPIO 19 through a resistor |
| All LED cathodes | GND |
| Button leg 1 | GPIO 23 |
| Button leg 2 | GND |

The button uses the ESP32's internal pull-up resistor, so no external button resistor is required.

## How It Works

The variable `number` stores the current value. When the button changes from HIGH to LOW, the program adds one to the value. The `bitRead()` function checks each binary bit and turns the corresponding LED on or off. A short delay helps prevent one press from being counted multiple times.

| Decimal | 8 | 4 | 2 | 1 |
|---:|---:|---:|---:|---:|
| 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 0 | 1 |
| 5 | 0 | 1 | 0 | 1 |
| 10 | 1 | 0 | 1 | 0 |
| 15 | 1 | 1 | 1 | 1 |

## Software

- Arduino IDE
- ESP32 board package
- Arduino C/C++

No additional library is required.

## Testing

1. Upload `Binary.c++` to the ESP32.
2. Open the Serial Monitor at 115200 baud.
3. Press the button once at a time.
4. Confirm that the LEDs display the binary value and the Serial Monitor shows the decimal value.
5. Continue through 15 and verify that the next press resets the display to 0.

## Result

The project successfully counted from 0 through 15 and displayed each number as a four-bit LED pattern.
