# ESP32 RGB LED Web Server

## Overview

This project demonstrates how to control an RGB LED wirelessly using an ESP32 microcontroller. The ESP32 hosts a web server that users can access from any device connected to the same Wi-Fi network. Through a browser-based color picker, users can change the RGB LED color in real time.

This project combines embedded systems, networking, and web technologies to create an interactive Internet of Things (IoT) application.

---

## Features

* ESP32 hosts a local web server
* Connects to Wi-Fi
* Browser-based color picker interface
* Real-time RGB LED color control
* PWM brightness control for smooth color transitions
* No additional mobile app required

---

## Hardware Used

* ESP32 DOIT DevKit V1
* RGB LED (Common Cathode)
* 3 × 220Ω resistors
* Breadboard
* Jumper wires
* USB cable

---

## Software Used

* Arduino IDE
* ESP32 Arduino Core
* WiFi library
* HTML
* JavaScript Color Picker (jscolor)

---

## Wiring

| ESP32 Pin      | RGB LED               |
| -------------- | --------------------- |
| GPIO13         | Red                   |
| GPIO12         | Green                 |
| GPIO14         | Blue                  |
| GND            | Common Cathode        |
| 220Ω Resistors | One per color channel |

---

## How It Works

1. The ESP32 connects to the local Wi-Fi network.
2. It starts a web server.
3. A browser opens the ESP32's IP address.
4. A web page displays a color picker.
5. Selecting a color sends RGB values to the ESP32.
6. The ESP32 adjusts PWM outputs to produce the selected color on the RGB LED.

---

## Skills Demonstrated

* Embedded Systems Programming
* ESP32 Development
* PWM LED Control
* GPIO Configuration
* Wi-Fi Networking
* HTTP Web Server
* HTML Integration
* JavaScript
* Internet of Things (IoT)
* Hardware Debugging

---

## Challenges

* Learning how an ESP32 hosts a web server.
* Configuring PWM outputs for RGB LEDs.
* Troubleshooting compatibility issues with newer ESP32 board packages.
* Understanding how browser requests communicate with embedded hardware.

---

## What I Learned

This project helped me understand how embedded devices communicate over Wi-Fi and serve web pages. I learned how HTTP requests can control physical hardware in real time and how PWM creates different colors by adjusting the brightness of each LED channel. It also introduced me to combining embedded C++, HTML, and JavaScript in a single IoT application.

---

## Future Improvements

* Add a brightness slider.
* Save the last selected color.
* Add preset color buttons.
* Control multiple RGB LEDs.
* Create a responsive mobile-friendly interface.
* Integrate with a smartphone app.
* Add MQTT or cloud connectivity for remote access.

---

## Project Status

✅ Complete
