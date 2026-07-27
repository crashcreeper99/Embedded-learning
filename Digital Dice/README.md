# ESP32 OLED Digital Dice 🎲

## Project Overview
The ESP32 OLED Digital Dice is an embedded systems project that simulates a physical dice using an ESP32 microcontroller, an OLED display, and a push button. When the button is pressed, the ESP32 randomly generates a number between 1 and 6 and displays the result on the OLED screen.

This project demonstrates input handling, random number generation, OLED display communication, and basic embedded programming concepts.

## Features
- 🎲 Digital dice roll simulation
- 🖥️ OLED display output
- 🔘 Push button input control
- ⚡ ESP32 microcontroller processing
- 🔢 Random number generation from 1-6
- 🔄 Real-time updates after each roll

## Hardware Used
- ESP32 DOIT DEVKIT V1
- OLED Display (SSD1306 I2C)
- Push Button
- Breadboard
- Jumper Wires
- 10kΩ Resistor (pull-down resistor)
- USB Cable

## Software Used
- Arduino IDE
- ESP32 Board Package
- Adafruit SSD1306 Library
- Adafruit GFX Library

## Circuit Connections

### OLED Display (I2C)
| OLED Pin | ESP32 Pin |
|----------|-----------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### Push Button
| Button Pin | ESP32 Pin |
|------------|-----------|
| One side | GPIO 4 |
| Other side | GND |

## How It Works
1. The ESP32 initializes the OLED display.
2. The system waits for the user to press the button.
3. When pressed, the ESP32 generates a random number between 1 and 6.
4. The OLED screen clears and displays the dice result.
5. The user can press the button again to roll a new number.

## Skills Learned
- Interfacing an OLED display with ESP32
- Using I2C communication
- Reading digital inputs
- Implementing button controls
- Generating random values in embedded systems
- Debugging hardware connections

## Future Improvements
- Add dice rolling animation
- Add sound effects using a buzzer
- Create multiple dice modes
- Add a score tracking system
- Build a physical 3D printed dice enclosure

## Project Status
✅ Completed
