# Embedded Learning Portfolio

Hands-on embedded systems, electronics, and firmware projects built while developing my skills in computer and electrical engineering.

This repository documents my progression from basic GPIO and sensor exercises to more integrated ESP32 systems involving displays, networking, timing, automation, RFID, sensors, and actuators.

## Featured completed builds

These are the projects I would show first because they combine multiple skills and include working code plus documentation.

### [RFID Attendance Check-In System](./RFID%20Attendance%20Check-In%20System)
RFID-based check-in system using an RC522 reader, RTC timekeeping, OLED feedback, and stored user state. Includes source code, README, reflection, photo, and demo video.

### [Automatic Door](./Automatic%20Door)
Motion-triggered door prototype combining a PIR sensor and servo actuator. This project also documents the troubleshooting process behind servo power and GPIO issues.

### [Alarm Clock](./Alarm%20Clock)
ESP32 alarm-clock build using a DS1307 real-time clock and display, with documented code, hardware setup, reflection, and demo media.

### [Automatic Night Light](./Automatic%20Night%20Light)
Light-responsive embedded system that reads ambient light and automatically controls an output based on the environment.

## Planned builds

These are intentionally kept separate from completed work and should not be counted as finished projects until they are physically built and tested.

- [Smart Room Automation System](./Smart%20Room%20Automation%20System) — planned multi-sensor integration build
- [ESP32 Sensor JSON API](./ESP32%20Sensor%20JSON%20API) — planned networking/API build

## What this repository demonstrates

- Embedded C/C++ development
- ESP32 hardware and firmware integration
- Digital and analog I/O
- PWM, ADC, timers, and interrupts
- I2C, SPI, and Wi-Fi
- Sensors, servos, relays, RFID, RTCs, and OLED displays
- Debugging and hardware troubleshooting
- Project documentation and technical reflection

## Repository structure

The repository contains **learning exercises**, **completed portfolio builds**, and a small number of clearly labeled **planned builds**.

Learning exercises are intentionally small and show specific concepts such as GPIO, PWM, buttons, analog input, displays, or individual sensors. They are kept to show progression rather than presented as major standalone engineering projects.

Featured builds combine multiple components or concepts and are the projects I would discuss first in an internship, engineering, or technical interview.

## Documentation standard

A completed portfolio project should include as many of the following as practical:

1. Working source code
2. README explaining the purpose and operation
3. Parts and wiring information
4. Reflection covering problems, debugging, and lessons learned
5. Photo or short demo when it adds useful proof of the build

Folders that contain only planning documentation are labeled as planned work, not completed projects.

## Hardware and tools

- ESP32 development boards
- Arduino IDE / Visual Studio Code
- C/C++
- Git and GitHub
- OLED displays
- DHT temperature/humidity sensors
- Ultrasonic and PIR sensors
- Servos and relays
- DS1307 RTC
- RC522 RFID
- Breadboards and common electronic components

## Learning progression

**Foundations:** GPIO, LEDs, buttons, serial communication, analog inputs, PWM, and basic electronics.

**Sensors and control:** environmental sensors, displays, servos, timing, interrupts, and user input.

**Connected systems:** Wi-Fi, web servers, IoT-style control, RFID, logging, and multi-component integration.

**Next level:** larger custom builds, robotics, PCB design, power management, FreeRTOS, and deeper hardware/software system design.

## Portfolio direction

The goal of this repository is no longer to maximize the number of small ESP32 projects. The focus is increasingly on stronger engineering ownership: understanding each subsystem, documenting the troubleshooting process, modifying designs, and combining learned skills into larger original builds.

---

This is an active learning portfolio. Older projects remain as evidence of progression, while the strongest completed systems are highlighted above.