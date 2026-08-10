# Reflection

```markdown
# Reflection — RTC Digital Clock

This project was more challenging than some of my previous ESP32 projects because I had to work with two different I²C devices. Initially, the OLED worked, but the DS1307 was not being detected. I had to troubleshoot the wiring, check the I²C connections, and separate the communication between the OLED and RTC.

One of the biggest things I learned was that an I²C device can receive power and still not communicate correctly with the microcontroller. The DS1307 lighting up did not necessarily mean that the ESP32 could communicate with it.

I eventually configured the OLED and DS1307 to use separate I²C pins. The OLED uses GPIO 21 and GPIO 22, while the DS1307 uses GPIO 18 and GPIO 19. This helped separate the two devices and allowed the ESP32 to communicate with both successfully.

I also learned more about the RTClib library and how the DS1307 maintains time independently from the main program. Instead of calculating the time using delays or millis(), the ESP32 can request the actual time from the RTC.

The most important lesson from this project was troubleshooting. The first version of the project did not work immediately, but instead of abandoning it, I tested the OLED separately, checked the RTC, changed the I²C configuration, and eventually got the complete system working.

This project improved my understanding of embedded systems, I²C communication, hardware debugging, and interfacing multiple peripherals with an ESP32.

## Final Takeaway

I successfully built and tested an RTC Digital Clock using an ESP32, DS1307 RTC, and SSD1306 OLED. This project gave me more experience debugging real hardware problems and showed me how different components can communicate with a microcontroller as part of a complete embedded system.
