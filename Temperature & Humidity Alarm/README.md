# DHT22 Temperature & Humidity Alarm

## Overview

This project is an environmental monitoring and alarm system built with an **ESP32 DevKit V1**, **DHT22 temperature and humidity sensor**, **0.96-inch SSD1306 OLED display**, **buzzer**, and **push button**.

The system continuously measures the surrounding temperature and humidity and displays the readings on the OLED. If the temperature or humidity exceeds a programmed limit, the buzzer activates. A push button allows the user to silence the alarm.

## Features

* Measures temperature using a DHT22 sensor
* Measures relative humidity
* Displays temperature in Fahrenheit
* Displays humidity percentage
* Shows system status on an OLED
* Activates a buzzer when environmental limits are exceeded
* Push button silences an active alarm
* Automatically resets the alarm when conditions return to normal
* Uses the ESP32 for sensor processing and control

## Hardware

* ESP32 DevKit V1
* DHT22 temperature and humidity sensor
* 0.96" SSD1306 OLED display
* Active/passive buzzer
* Push button
* Breadboard
* Jumper wires
* USB cable

## Wiring

### DHT22

| DHT22 | ESP32  |
| ----- | ------ |
| VCC   | 3.3V   |
| DATA  | GPIO 4 |
| GND   | GND    |

### OLED

| OLED | ESP32   |
| ---- | ------- |
| VCC  | 3.3V    |
| GND  | GND     |
| SDA  | GPIO 21 |
| SCL  | GPIO 22 |

### Buzzer

| Buzzer       | ESP32   |
| ------------ | ------- |
| Positive (+) | GPIO 25 |
| Negative (-) | GND     |

### Push Button

| Button        | ESP32   |
| ------------- | ------- |
| One side      | GPIO 27 |
| Opposite side | GND     |

The button uses the ESP32's internal pull-up resistor, so an external resistor is not required for the button.

## Alarm Thresholds

The default alarm settings are:

* High temperature: **80°F**
* Low temperature: **40°F**
* High humidity: **70%**

These values can be changed in the Arduino code.

```cpp
float HIGH_TEMP = 80.0;
float LOW_TEMP = 40.0;
float HIGH_HUMIDITY = 70.0;
```

## How It Works

1. The ESP32 starts the OLED and DHT22 sensor.
2. The DHT22 measures the current temperature and humidity.
3. The ESP32 converts the temperature from Celsius to Fahrenheit.
4. The readings are displayed on the OLED.
5. The ESP32 compares the readings against the alarm thresholds.
6. If a threshold is exceeded, the buzzer sounds.
7. Pressing the button silences the buzzer.
8. When the environmental conditions return to normal, the alarm resets.

## Software

The project was programmed using **Arduino IDE**.

### Libraries

* DHT sensor library by Adafruit
* Adafruit Unified Sensor
* Adafruit GFX Library
* Adafruit SSD1306

## Testing

The system was tested by:

* Verifying temperature readings
* Verifying humidity readings
* Confirming OLED output
* Testing the alarm threshold
* Confirming the buzzer activates
* Confirming the push button silences the alarm
* Confirming the alarm resets when conditions return to normal

## Skills Demonstrated

This project demonstrates:

* ESP32 programming
* Digital GPIO control
* I²C communication
* Sensor integration
* OLED display programming
* Environmental monitoring
* Conditional programming
* Alarm and control logic
* Hardware troubleshooting
* Breadboard wiring
* Embedded systems development

## Future Improvements

Possible improvements include:

* Add an RTC for time and date logging
* Add Wi-Fi monitoring
* Create a web dashboard
* Add data logging to an SD card
* Add adjustable alarm thresholds using buttons
* Add a second sensor for comparison
* Add notifications through a phone or web application
* Build the project into a permanent enclosure

## Project Status

**Completed**

The DHT22 Temperature & Humidity Alarm successfully measures environmental conditions, displays the readings, activates an alarm when thresholds are exceeded, and allows the user to silence the alarm with a push button.
