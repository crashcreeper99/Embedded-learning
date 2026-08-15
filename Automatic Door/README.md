# ESP32 Automatic Door

## Project Overview

This project uses an ESP32, HC-SR501 PIR motion sensor, and SG90 servo motor to create a simple automatic door system. When the PIR sensor detects motion, the ESP32 commands the servo to rotate and open the door. After a short delay, the servo returns to the closed position.

This project helped me practice combining a sensor and an actuator in one embedded system and troubleshooting power and GPIO issues with a servo motor.

## Components

- ESP32 DEVKIT V1
- HC-SR501 PIR motion sensor
- SG90 servo motor
- Breadboard
- Jumper wires
- USB cable
- Cardboard or another lightweight material for a prototype door (optional)

## Wiring

### SG90 Servo

| Servo Wire | ESP32 Connection |
|---|---|
| Orange/Yellow (Signal) | GPIO 13 |
| Red (Power) | VIN / 5V |
| Brown/Black (Ground) | GND |

### PIR Sensor

| PIR Pin | ESP32 Connection |
|---|---|
| VCC | VIN / 5V |
| OUT | GPIO 27 |
| GND | GND |

## How It Works

1. The PIR sensor monitors the area for motion.
2. When motion is detected, the PIR OUT pin goes HIGH.
3. The ESP32 reads the signal on GPIO 27.
4. The ESP32 commands the SG90 servo on GPIO 13 to rotate to the open position.
5. The door remains open for about three seconds.
6. The servo moves back to the closed position.

## Arduino Library

This project uses the `ESP32Servo` library.

Install it in the Arduino IDE through:

`Sketch -> Include Library -> Manage Libraries -> ESP32Servo`

## What I Learned

- How to control a servo motor with an ESP32
- How to use a PIR sensor as an input device
- How to combine sensor input with actuator output
- How servo power requirements can affect an ESP32 project
- How to isolate hardware problems by testing components separately
- How changing GPIO pins can help diagnose a hardware setup

## Troubleshooting

The biggest challenge was getting the servo to move reliably. I originally had problems while trying to use an external breadboard power supply module. I tested the ESP32 separately, tested multiple servos, and simplified the circuit until I confirmed the servo worked correctly on GPIO 13.

This showed me that troubleshooting should be done one component at a time instead of changing the code and hardware at the same time.

## Result

The final system successfully detects motion and controls the servo to simulate an automatic door opening and closing.
