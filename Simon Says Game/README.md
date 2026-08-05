# Simon Says Memory Game (ESP32)

## Overview

This project is an ESP32 implementation of the classic **Simon Says** memory game. The ESP32 generates an increasingly longer sequence of colored lights and sounds. The player must repeat the sequence correctly by pressing the matching buttons. Each successful round increases the difficulty by adding another step to the sequence. If the player presses an incorrect button, the game ends and restarts from Level 1.

---

## Features

* Four-button memory game
* Four LED color indicators
* Audio feedback using a buzzer
* Randomly generated sequences
* Increasing difficulty each level
* Game over indication
* Win condition after completing all levels

---

## Components Used

* ESP32 DOIT DevKit V1
* Breadboard
* 4 Push Buttons
* Red LED
* Green LED
* Yellow LED
* RGB LED (used only for the blue color channel in place of a separate blue LED)
* 4 × 220Ω resistors
* Active/Passive Buzzer
* Jumper Wires
* USB Cable

---

## Wiring

### LEDs

* Red LED → GPIO 23 → 220Ω resistor → GND
* Green LED → GPIO 22 → 220Ω resistor → GND
* Blue channel of the RGB LED → GPIO 21 → 220Ω resistor → GND
* Yellow LED → GPIO 19 → 220Ω resistor → GND

### Buttons

* Button 1 → GPIO 13 → GND
* Button 2 → GPIO 14 → GND
* Button 3 → GPIO 27 → GND
* Button 4 → GPIO 26 → GND

### Buzzer

* Positive (+) → GPIO 4
* Negative (–) → GND

All components share the ESP32's common ground.

---

## How It Works

1. The ESP32 generates a random sequence.
2. LEDs illuminate one at a time while the buzzer plays a matching tone.
3. The player repeats the sequence using the four buttons.
4. If the input is correct, another step is added.
5. If the player makes a mistake, the game displays a game-over pattern and restarts.
6. Completing every level wins the game.

---

## Skills Learned

* Digital input using push buttons
* Digital output using LEDs
* ESP32 GPIO programming
* Arrays and loops
* Random number generation
* Game logic implementation
* Memory sequence algorithms
* Embedded systems debugging
* Circuit wiring and troubleshooting

---

## Future Improvements

* OLED display showing the current level
* Difficulty selection
* High score saved in flash memory
* Improved sound effects
* RGB animations
* Start menu
* Adjustable game speed

---

## Project Outcome

This project demonstrates how an ESP32 can combine multiple hardware components into an interactive embedded game. It reinforces programming logic, hardware integration, and user interaction while providing a solid foundation for more advanced embedded systems projects.
