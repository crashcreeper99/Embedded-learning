# 🎲 Digital Dice (ESP32)

## Overview

This project uses an ESP32 and a push button to simulate rolling a six-sided die. Each time the button is pressed, the ESP32 generates a random number between 1 and 6 and displays the result using the Serial Monitor or LEDs. This project introduces random number generation, button input, and event-driven programming in embedded systems.

---

## Features

* 🎲 Simulates a six-sided die
* 🔘 Push button input
* 🔢 Random number generation (1–6)
* 💡 Displays the result through the Serial Monitor or LEDs
* 🔄 Generates a new result with every button press

---

## Components Used

* ESP32 Development Board
* Breadboard
* Push Button
* LEDs (optional)
* 220Ω Resistors
* Jumper Wires
* USB Cable

---

## Skills Learned

* GPIO Input Programming
* Random Number Generation
* Conditional Statements
* Button Handling
* Embedded C++
* Circuit Wiring
* Debugging Embedded Systems

---

## How It Works

1. The ESP32 waits for the push button to be pressed.
2. When the button is pressed, it generates a random number from 1 to 6.
3. The number is displayed through the Serial Monitor or LEDs.
4. The system waits for the next button press and repeats the process.

---

## Project Structure

```text
Digital-Dice/
│
├── DigitalDice.ino
├── README.md
├── images/
├── videos/
└── reflections/
```

---

## Future Improvements

* Add a seven-segment display
* Display results on an OLED screen
* Add a buzzer for sound effects
* Animate the dice roll before showing the final result
* Record roll statistics
* Build a multiplayer electronic dice game

---

## Technologies Used

* ESP32
* Arduino IDE
* Embedded C++
* Breadboard Electronics

---

## Lessons Learned

This project strengthened my understanding of user input and random number generation in embedded systems. I learned how to detect button presses, generate random values, and create interactive programs using the ESP32. These concepts provide a solid foundation for more advanced embedded systems projects involving sensors, displays, and real-world applications.
