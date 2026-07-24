# ESP32 Relay Web Server

## Overview
The ESP32 Relay Web Server is an IoT project that allows a user to control a relay module through a web browser over a Wi-Fi network. The ESP32 hosts a simple web server that provides ON and OFF buttons for remotely switching electrical devices connected to the relay.

This project demonstrates the fundamentals of embedded systems, IoT networking, web server development, and hardware interfacing.

---

## Features

- Wi-Fi connectivity
- Built-in web server
- Control relay from any device on the same network
- Responsive web interface
- Real-time relay switching
- Simple and expandable design

---

## Hardware

- ESP32 Development Board
- 1-Channel Relay Module (5V)
- Breadboard
- Jumper Wires
- USB Cable
- Computer with Arduino IDE

---

## Software

- Arduino IDE
- ESP32 Board Package
- WiFi Library
- WebServer Library

---

## Wiring

| ESP32 | Relay Module |
|--------|--------------|
| GPIO 26 (or chosen pin) | IN |
| 5V | VCC |
| GND | GND |

---

## How It Works

1. ESP32 connects to Wi-Fi.
2. It starts an HTTP web server.
3. The IP address is displayed in the Serial Monitor.
4. Open the IP address in a browser.
5. Click ON or OFF.
6. The relay changes state instantly.

---

## Skills Demonstrated

- Embedded Systems
- Internet of Things (IoT)
- ESP32 Programming
- GPIO Control
- Relay Modules
- Wi-Fi Networking
- HTTP Web Servers
- HTML
- C++
- Arduino Framework
- Hardware Integration

---

## Challenges

- Understanding relay wiring
- Connecting ESP32 to Wi-Fi
- Handling HTTP requests
- Testing relay logic
- Debugging wiring issues

---

## Future Improvements

- Password-protected login
- Mobile-friendly dashboard
- Multiple relay control
- Scheduling
- MQTT support
- Firebase integration
- Alexa or Google Home compatibility
- Sensor monitoring
- HTTPS support

---

## Learning Outcomes

After completing this project I learned how to:

- Host a web server on an ESP32
- Connect embedded hardware to Wi-Fi
- Control hardware remotely
- Handle HTTP requests
- Integrate hardware and software
- Debug IoT systems
- Design embedded applications

---

## Repository Structure

```
Relay-Web-Server/
│
├── Relay_Web_Server.ino
├── README.md
├── images/
│   ├── wiring.jpg
│   ├── relay-on.jpg
│   └── relay-off.jpg
└── demo-video.mp4
```

---

## Author

Lamar Holloway

Computer & Electrical Engineering Student

Loyola University Maryland
