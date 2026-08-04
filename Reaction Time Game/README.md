# ESP32 Reaction Time Game

## Project Overview

The ESP32 Reaction Time Game is an interactive embedded system that tests how quickly a user can respond to a visual signal. The game uses an LED to indicate when the player should react and a push button to measure the user's response time.

The ESP32 controls the timing, detects button input, and calculates the reaction speed in milliseconds.

## Components Used

* ESP32 DevKit V1
* LED
* Push Button
* 220Ω Resistor (for LED protection)
* Breadboard
* Jumper Wires
* USB Cable for programming and power

## Features

* Random delay before the LED turns on
* Detects button press timing
* Calculates reaction time
* Displays the player's response speed through Serial Monitor
* Provides a simple interactive game experience

## How It Works

1. The ESP32 starts the game and waits for a random amount of time.
2. The LED turns on to signal the player to press the button.
3. The ESP32 records the time when the LED activates.
4. When the player presses the button, the ESP32 calculates the difference between the start time and button press time.
5. The reaction time is displayed in milliseconds.

## Skills Learned

* Digital input and output with ESP32
* Using buttons with pull-up resistors
* Controlling LEDs
* Using millis() for accurate timing
* Creating interactive embedded applications
* Debugging hardware and software connections

## Possible Improvements

* Add an OLED display to show reaction time
* Add multiple rounds and calculate average reaction speed
* Add a high-score system
* Add RGB LEDs for different game states
* Add a buzzer for sound effects
* Create a web dashboard to display scores

## Conclusion

The ESP32 Reaction Time Game demonstrates how microcontrollers can process user input and respond instantly. This project improved my understanding of timing functions, hardware interaction, and creating real-world embedded systems.
