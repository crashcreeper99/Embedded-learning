# LED Combination Lock

## Overview
This ESP32 project uses four push buttons as a simple combination keypad. The user must enter the correct button sequence to unlock the system. A green LED indicates a correct combination and a red LED indicates an incorrect attempt.

## Parts Used
- ESP32 DEVKIT V1
- 4 push buttons
- 1 green LED
- 1 red LED
- 2 x 220Ω resistors
- Breadboard
- Jumper wires

## Wiring
### Buttons
Each button uses `INPUT_PULLUP`, so one side connects to the ESP32 pin and the other side connects to GND.

| Component | ESP32 Pin |
|---|---:|
| Button 1 | GPIO 13 |
| Button 2 | GPIO 14 |
| Button 3 | GPIO 27 |
| Button 4 | GPIO 26 |
| Other side of all buttons | GND |

### LEDs
| Component | ESP32 Pin |
|---|---:|
| Green LED anode (+) | GPIO 23 through 220Ω resistor |
| Red LED anode (+) | GPIO 22 through 220Ω resistor |
| LED cathodes (-) | GND |

## How It Works
The correct combination is Button 1 → Button 3 → Button 2 → Button 4. Each press is stored. After four presses, the ESP32 compares the entered sequence with the programmed combination. A correct sequence turns on the green LED. A wrong sequence flashes the red LED and resets the input.

## Skills Practiced
- Digital inputs and outputs
- `INPUT_PULLUP`
- Arrays
- Button debouncing
- Sequence comparison
- State-based logic

## Possible Improvements
- Add an OLED screen
- Add a servo lock
- Allow the combination to be changed
- Add a buzzer for feedback
