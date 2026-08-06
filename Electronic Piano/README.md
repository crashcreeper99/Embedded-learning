# Electronic Piano

## Overview

The Electronic Piano is an ESP32 project that allows different musical notes to be played using four push buttons and a passive buzzer. Each button represents a different note, creating a simple electronic musical instrument while demonstrating digital input handling and sound generation with the ESP32.

## Objectives

* Learn how to read multiple button inputs.
* Generate different sound frequencies using an ESP32.
* Practice using arrays and conditional statements.
* Understand how digital inputs control hardware outputs.
* Build a simple interactive electronic device.

## Components Used

* ESP32 DevKit V1
* Breadboard
* 4 Push Buttons
* Passive Buzzer
* Jumper Wires
* USB Cable

## Wiring Summary

* Passive Buzzer (+) → GPIO 25
* Passive Buzzer (−) → GND
* Button 1 → GPIO 27
* Button 2 → GPIO 26
* Button 3 → GPIO 14
* Button 4 → GPIO 12
* Other side of every button → GND

## Features

* Four playable musical notes
* Instant sound when a button is pressed
* Sound stops when the button is released
* Uses the ESP32's PWM hardware for audio generation
* Simple and expandable design

## Skills Learned

* Configuring GPIO pins as digital inputs
* Using INPUT_PULLUP
* Reading push button states
* Generating audio frequencies with PWM
* Organizing code with arrays
* Writing efficient control logic
* Hardware wiring and troubleshooting

## Challenges

During development, I encountered compilation issues related to different versions of the ESP32 Arduino core. I also learned the difference between active and passive buzzers and discovered that a passive buzzer is required to play multiple musical notes. After correcting the code and verifying the wiring, the electronic piano worked successfully.

## Future Improvements

* Add more buttons for a full octave.
* Display the current note on an OLED screen.
* Record and replay melodies.
* Add volume control with a potentiometer.
* Include song playback mode.
* Add LEDs that light up with each note.

## Conclusion

This project strengthened my understanding of digital inputs, PWM sound generation, and hardware troubleshooting on the ESP32 platform. It also demonstrated how software and electronics work together to create an interactive musical device and provided a strong foundation for more advanced embedded systems projects.
