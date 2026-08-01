# ESP32 OLED Temperature & Humidity Monitor

## Project Overview

This project uses an ESP32, a DHT temperature and humidity sensor, and a 0.96-inch SSD1306 OLED display to create a real-time environmental monitoring system. The ESP32 reads temperature and humidity data every five seconds and displays the information on the OLED screen.

## Features

* Reads temperature from a DHT sensor
* Reads relative humidity
* Displays data on a 128×64 OLED display
* Updates automatically every five seconds
* Uses I2C communication for the OLED display
* Serial Monitor output for debugging

## Components Used

* ESP32 DOIT DevKit V1
* SSD1306 128×64 I2C OLED Display
* DHT22 (or DHT11 with code modification)
* Breadboard
* Jumper wires
* USB cable

## Wiring

### OLED Display

* VCC → 3.3V
* GND → GND
* SDA → GPIO 21
* SCL → GPIO 22

### DHT Sensor

* VCC → 3.3V
* GND → GND
* DATA → GPIO 14

## Software

* Arduino IDE
* ESP32 Board Package
* Adafruit GFX Library
* Adafruit SSD1306 Library
* Adafruit Unified Sensor Library
* DHT Sensor Library

## What I Learned

Through this project I learned how to:

* Interface multiple sensors with the ESP32.
* Use I2C communication with an OLED display.
* Read temperature and humidity data from a DHT sensor.
* Display formatted sensor data on a graphical screen.
* Troubleshoot wiring, libraries, and sensor communication.
* Build a simple embedded monitoring system.

## Possible Improvements

* Display temperature in both Celsius and Fahrenheit.
* Add Wi-Fi connectivity to send data to a web dashboard.
* Log measurements to a microSD card.
* Add warning icons for high temperature or humidity.
* Display maximum and minimum recorded values.
* Create a web server to monitor data remotely.

## Skills Demonstrated

* Embedded Systems
* ESP32 Programming
* Arduino C++
* Sensor Integration
* I2C Communication
* OLED Graphics
* Hardware Debugging
* Environmental Monitoring
