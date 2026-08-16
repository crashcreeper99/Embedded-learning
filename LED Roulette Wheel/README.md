# LED Roulette Wheel

## Overview
This ESP32 project creates a roulette-style LED game. Pressing the button starts a light moving across six LEDs. The movement gradually slows down until it randomly stops on one LED.

## Parts Used
- ESP32 DEVKIT V1
- 6 LEDs
- 6 x 220Ω resistors
- 1 push button
- Breadboard
- Jumper wires

## Wiring
### LEDs
Connect each LED anode (+) to its GPIO through a 220Ω resistor. Connect every LED cathode (-) to GND.

| LED | ESP32 Pin |
|---|---:|
| LED 1 | GPIO 13 |
| LED 2 | GPIO 14 |
| LED 3 | GPIO 27 |
| LED 4 | GPIO 26 |
| LED 5 | GPIO 25 |
| LED 6 | GPIO 33 |

### Button
| Component | Connection |
|---|---|
| Button side 1 | GPIO 32 |
| Button side 2 | GND |

The button uses the ESP32's internal pull-up resistor.

## How It Works
When the button is pressed, the LEDs cycle quickly one at a time. The delay between steps increases gradually, making the roulette wheel appear to slow down. A random stopping point makes each round different.

## Skills Practiced
- Arrays
- Random numbers
- Button input
- Sequential LED control
- Timing with `delay()`
- Game-style embedded logic

## Possible Improvements
- Add a buzzer with different tones
- Assign different scores to LEDs
- Add an OLED score display
- Add two-player scoring
