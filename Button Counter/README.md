# Button Counter with LED Feedback

## Overview

This project uses a push button to increase a counter stored by the ESP32. Every valid press flashes an LED and prints the updated count in the Serial Monitor.

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
| Button leg 1 | GPIO 23 |
| Button leg 2 | GND |
| LED anode | GPIO 18 through a resistor |
| LED cathode | GND |

The button uses `INPUT_PULLUP`, so the unpressed state is HIGH and the pressed state is LOW. No external pull-up resistor is required.

## How It Works

The program compares the current button state with its previous state. A count is added only when the input changes from HIGH to LOW. This edge-detection method prevents the program from counting continuously while the button is held.

After a press is detected:

1. The count increases by one.
2. The LED flashes for 100 milliseconds.
3. The updated count appears in the Serial Monitor.
4. A short delay provides basic button debouncing.

## Software

- Arduino IDE
- ESP32 board package
- Arduino C/C++

No additional library is required.

## Testing

1. Upload `Counter.c++` to the ESP32.
2. Open the Serial Monitor at 115200 baud.
3. Press and release the button several times.
4. Confirm that the count increases once per press.
5. Confirm that the LED flashes for every registered press.

## Applications

This counter method can be used for:

- Attendance or item counters
- Scorekeeping
- Production counters
- Menu navigation
- User-input tracking

## Result

The project successfully counted individual button presses, displayed the total in the Serial Monitor, and provided LED feedback.
