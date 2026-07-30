# Potentiometer RGB Lamp (ESP32)

## Overview

This project uses an ESP32, an RGB LED, and a potentiometer to create a color-changing lamp. As the potentiometer is turned, the ESP32 reads the analog voltage and adjusts the brightness of the red, green, and blue LED channels using PWM (Pulse Width Modulation). The result is a smooth transition through different colors.

## Features

* Reads analog input from a potentiometer
* Controls RGB LED brightness using PWM
* Smooth color transitions
* Real-time serial monitor output
* Demonstrates analog-to-digital conversion and PWM control

## Components Used

* ESP32 DOIT DEVKIT V1
* Breadboard
* RGB LED
* 3 × 220 Ω resistors
* 10 kΩ potentiometer
* Jumper wires
* USB cable

## Wiring

* Potentiometer

  * Left pin → 3.3V
  * Middle pin → GPIO34
  * Right pin → GND
* RGB LED

  * Red → GPIO25 (through 220 Ω resistor)
  * Green → GPIO26 (through 220 Ω resistor)
  * Blue → GPIO27 (through 220 Ω resistor)
  * Common cathode → GND

## How It Works

1. The ESP32 continuously reads the potentiometer using GPIO34.
2. The analog value (0–4095) is mapped to a PWM brightness value (0–255).
3. PWM signals are sent to the red, green, and blue channels.
4. The RGB LED changes color smoothly as the potentiometer is rotated.
5. Current values are displayed in the Serial Monitor for debugging.

## Skills Learned

* Reading analog inputs on the ESP32
* Using PWM to control LED brightness
* Mapping sensor values
* Working with RGB LEDs
* Using the Serial Monitor for testing and debugging
* Designing simple interactive embedded systems

## Future Improvements

* Add preset color modes with a push button
* Save the last selected color in EEPROM or Preferences
* Control the lamp over Wi-Fi using a web interface
* Add fade animations and lighting effects
* Integrate additional sensors for automatic color changes

## License

This project is for educational purposes and is part of my embedded systems learning portfolio.

