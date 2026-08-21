# Automatic Relay Timer

## Overview
This project uses an ESP32, a push button, and a relay module to create a timed control system. Pressing the button turns the relay on, keeps it active for a fixed period, and then turns it off automatically.

## Components
- ESP32 DevKit V1
- Relay module
- Push button
- Breadboard
- Jumper wires
- USB cable

## Wiring
### Relay
| Relay Pin | ESP32 Pin |
|---|---|
| IN | GPIO 26 |
| GND | GND |
| VCC | Supply required by the relay module |

### Button
| Button Connection | ESP32 Pin |
|---|---|
| Side 1 | GPIO 27 |
| Side 2 | GND |

The button uses the ESP32's internal pull-up resistor with `INPUT_PULLUP`, so an external pull-up resistor is not required.

## How It Works
1. The ESP32 waits for the push button to be pressed.
2. When the button is pressed, the relay activates.
3. The program records the start time using `millis()`.
4. The relay stays on for approximately 10 seconds.
5. After the timer expires, the ESP32 switches the relay off automatically.

## Relay Note
Some relay modules are active LOW. If the relay behaves backwards, reverse the HIGH and LOW values used for the relay output in the sketch.

## Testing
1. Upload the sketch to the ESP32.
2. Open the Serial Monitor at 115200 baud.
3. Press the button once.
4. Confirm that the relay activates and the Serial Monitor prints `Relay ON`.
5. Wait about 10 seconds and confirm that the relay turns off automatically.
6. Repeat the test to make sure the timer can be restarted.

## What I Learned
This project helped me practice event-driven control, push-button input, relay output, and non-blocking timing with `millis()`. It also showed me how embedded systems can control a device for a fixed amount of time without requiring constant user input.

## Future Improvements
- Add an OLED countdown display.
- Let the user change the timer duration with buttons or a potentiometer.
- Add Wi-Fi control.
- Store multiple timer presets.
- Use the relay to automate a safe low-voltage load.
