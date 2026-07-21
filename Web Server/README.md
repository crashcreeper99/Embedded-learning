# ESP32 Web Server

## Overview

This project demonstrates how to create a simple web server using an ESP32. The ESP32 connects to a Wi-Fi network and hosts a webpage that can be accessed from any device on the same network through a web browser. The webpage allows users to interact with the ESP32, making this project a foundation for Internet of Things (IoT) applications.

## Objectives

* Learn how to connect an ESP32 to a Wi-Fi network.
* Understand how embedded web servers work.
* Serve HTML content directly from the ESP32.
* Build a foundation for remote monitoring and control projects.

## Hardware

* ESP32 Development Board
* USB Cable
* Computer with Arduino IDE or PlatformIO
* Wi-Fi Network

## Software

* Arduino IDE or PlatformIO
* ESP32 Board Package
* WiFi Library
* WebServer Library (or ESPAsyncWebServer if used)

## Features

* Connects to a local Wi-Fi network.
* Displays the ESP32's IP address in the Serial Monitor.
* Hosts a webpage accessible through a web browser.
* Responds to HTTP requests from connected devices.
* Provides a starting point for adding sensors, LEDs, relays, or other hardware.

## How It Works

1. The ESP32 powers on.
2. It connects to the configured Wi-Fi network.
3. The assigned IP address is displayed in the Serial Monitor.
4. A web browser connects to the ESP32 using that IP address.
5. The ESP32 serves an HTML webpage to the client.

## Skills Learned

* Embedded networking
* Wi-Fi communication
* HTTP protocol basics
* Web server programming
* Client-server communication
* Debugging network connections

## Challenges

* Configuring Wi-Fi credentials correctly.
* Ensuring the ESP32 successfully connected to the network.
* Finding the correct IP address.
* Testing browser connectivity.
* Understanding how HTTP requests are processed.

## Future Improvements

* Add LED control buttons.
* Display live sensor readings.
* Create a responsive webpage.
* Add password protection.
* Implement OTA (Over-the-Air) firmware updates.
* Control multiple devices from the webpage.

## Technologies Used

* ESP32
* C++
* Arduino Framework
* Wi-Fi
* HTTP
* HTML

## Project Status

**Completed** ✅
