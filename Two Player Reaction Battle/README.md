# Two Player Reaction Battle

## Overview
This ESP32 project is a two-player reaction game. After a random waiting period, a start LED turns on. The first player to press their button after the LED lights wins. Pressing too early counts as a false start.

## Parts Used
- ESP32 DEVKIT V1
- 3 LEDs
- 3 x 220Ω resistors
- 2 push buttons
- Breadboard
- Jumper wires

## Wiring
### Buttons
Both buttons use `INPUT_PULLUP`, so connect one side of each button to its GPIO pin and the other side to GND.

| Component | ESP32 Pin |
|---|---:|
| Player 1 button | GPIO 18 |
| Player 2 button | GPIO 19 |
| Other side of both buttons | GND |

### LEDs
| Component | ESP32 Pin |
|---|---:|
| Start LED anode (+) | GPIO 23 through 220Ω resistor |
| Player 1 win LED anode (+) | GPIO 22 through 220Ω resistor |
| Player 2 win LED anode (+) | GPIO 21 through 220Ω resistor |
| All LED cathodes (-) | GND |

## How It Works
The ESP32 waits for a random amount of time before turning on the start LED. Players must wait until the LED is on before pressing their buttons. The ESP32 checks both buttons rapidly and records the first valid press. Pressing before the start LED turns on gives the other player the win.

## Skills Practiced
- Digital input and output
- Random timing
- Reaction-time logic
- False-start detection
- State control
- Two-player game logic

## Possible Improvements
- Measure reaction time in milliseconds
- Display the winner on an OLED
- Keep a running score
- Add a best-of-five game mode
