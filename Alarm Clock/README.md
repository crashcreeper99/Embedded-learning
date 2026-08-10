# ESP32 DS1307 Alarm Clock

## Project Overview

This project is a digital alarm clock built using an **ESP32 DevKit V1**, **DS1307 Real-Time Clock (RTC)**, and **0.96-inch SSD1306 OLED display**. The clock displays the current time and date while allowing an alarm to sound at a programmed time.

A pushbutton is used to stop the alarm when it is ringing.

## Features

* Real-time clock using the DS1307 RTC
* Displays hours, minutes, and seconds
* Displays the current date
* Programmable alarm
* Buzzer alarm
* Pushbutton to stop the alarm
* OLED graphical display
* Uses separate I²C connections for the RTC and OLED

## Hardware

* ESP32 DevKit V1
* DS1307 RTC module
* 0.96-inch SSD1306 OLED
* Buzzer
* Pushbutton
* Breadboard
* Jumper wires

## Wiring

### DS1307 RTC

| DS1307 | ESP32   |
| ------ | ------- |
| SDA    | GPIO 18 |
| SCL    | GPIO 19 |
| VCC    | 5V      |
| GND    | GND     |

### SSD1306 OLED

| OLED | ESP32   |
| ---- | ------- |
| SDA  | GPIO 21 |
| SCL  | GPIO 22 |
| VCC  | 3.3V    |
| GND  | GND     |

### Buzzer

| Buzzer       | ESP32   |
| ------------ | ------- |
| Positive (+) | GPIO 25 |
| Negative (-) | GND     |

### Pushbutton

| Button     | ESP32   |
| ---------- | ------- |
| One side   | GPIO 27 |
| Other side | GND     |

The button uses the ESP32's internal `INPUT_PULLUP` resistor.

## Software

The project was programmed using the Arduino IDE.

### Libraries

* RTClib
* Adafruit GFX Library
* Adafruit SSD1306

## How It Works

The DS1307 keeps track of the current date and time. The ESP32 reads the RTC and sends the information to the SSD1306 OLED.

The programmed alarm time is compared with the current RTC time. When the current time reaches the alarm time, the ESP32 activates the buzzer.

Pressing the pushbutton stops the alarm.

## Alarm Configuration

The alarm can be changed in the code:

```cpp
const int ALARM_HOUR = 16;
const int ALARM_MINUTE = 33;
```

The current configuration is:

**4:33 PM**

The DS1307 stores the time independently of the ESP32 so that the clock can continue keeping time when the ESP32 is restarted, provided the RTC has a working backup battery.

## I²C Configuration

This project uses two separate I²C buses:

```text
DS1307:
SDA → GPIO 18
SCL → GPIO 19

OLED:
SDA → GPIO 21
SCL → GPIO 22
```

Using separate buses helped prevent communication conflicts between the RTC and OLED.

## Challenges

One of the main challenges was getting the clock to display the correct time. The DS1307 can retain a stored time, so repeatedly setting the RTC during startup caused the displayed time to be incorrect.

Another challenge was getting the alarm button and buzzer to respond correctly.

## What I Learned

Through this project I learned:

* How a DS1307 RTC keeps track of time
* How to communicate with an RTC using I²C
* How to use an OLED display with an ESP32
* How to use multiple I²C buses
* How to program an alarm using conditional logic
* How to use a pushbutton with `INPUT_PULLUP`
* How to control a buzzer with the ESP32
* How to troubleshoot hardware and software communication problems

## Future Improvements

Possible improvements include:

* Add buttons to set the alarm directly
* Add an alarm on/off button
* Add snooze functionality
* Add a temperature and humidity display
* Add 12-hour AM/PM formatting
* Add a menu system
* Add a rechargeable battery
* Add Wi-Fi time synchronization using NTP
* Build a custom enclosure

## Project Status

**Completed**

This project demonstrates practical embedded systems skills involving an ESP32, sensors/modules, displays, user input, and output devices.
