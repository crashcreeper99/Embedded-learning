# Two Player Reaction Battle

## Overview
This ESP32 project is a two-player reaction game. A Start button begins each round. After the ready sequence and a random waiting period, the blue channel of an RGB LED turns on as the GO signal. The first player to press their button wins, while pressing too early counts as a false start.

## Parts Used
- ESP32 DEVKIT V1
- 1 ready LED
- 2 player winner LEDs
- 1 common-cathode RGB LED (blue channel used for GO)
- 4 x 220Ω resistors
- 3 push buttons
- Breadboard
- Jumper wires

## Wiring
### Buttons
All three buttons use `INPUT_PULLUP`, so connect one side of each button to its GPIO pin and the other side to GND.

| Component | ESP32 Pin |
|---|---:|
| Player 1 button | GPIO 13 |
| Player 2 button | GPIO 14 |
| Start button | GPIO 27 |
| Other side of all buttons | GND |

### LEDs
| Component | ESP32 Pin |
|---|---:|
| Ready LED anode (+) | GPIO 18 through 220Ω resistor |
| RGB LED blue leg | GPIO 19 through 220Ω resistor |
| RGB LED common cathode | GND |
| RGB LED red and green legs | Not connected |
| Player 1 win LED anode (+) | GPIO 25 through 220Ω resistor |
| Player 2 win LED anode (+) | GPIO 26 through 220Ω resistor |
| Single-color LED cathodes (-) | GND |

## How It Works
The Start button begins the round. The ready LED flashes three times, then the ESP32 waits between two and five seconds. When the RGB LED's blue channel turns on, both players race to press their buttons. The ESP32 measures the winner's reaction time in milliseconds. Pressing before the blue GO signal gives the other player the win.

## Skills Practiced
- Digital input and output
- `INPUT_PULLUP` button wiring
- Button debouncing
- Random timing
- Reaction-time measurement
- Reaction-time logic
- False-start detection
- Tie detection
- RGB LED control
- State control
- Two-player game logic

## Possible Improvements
- Display the winner on an OLED
- Keep a running score
- Add a best-of-five game mode
