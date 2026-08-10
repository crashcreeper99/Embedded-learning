# Project Reflection — ESP32 DS1307 Alarm Clock

For this project, I built a digital alarm clock using an ESP32 DevKit V1, DS1307 real-time clock module, SSD1306 OLED display, buzzer, and pushbutton. The goal was to create a working clock that could keep track of the current time and activate an alarm at a programmed time.

The most challenging part of the project was getting the DS1307 to display the correct time. I initially had problems because the RTC's stored time did not match the actual time. I learned that the DS1307 can continue keeping time independently from the ESP32, so the RTC should not be reset every time the ESP32 starts. This helped me understand the difference between setting an RTC and reading the time from an RTC.

I also had to troubleshoot communication between the OLED and DS1307. I used separate I²C connections for the two devices, with the DS1307 connected to GPIO 18 and 19 and the OLED connected to GPIO 21 and 22. This gave me more control over the communication between the ESP32 and each device.

Another part I learned from was adding the alarm button. The button uses the ESP32's internal pull-up resistor, which allowed me to connect the button directly between GPIO 27 and ground. When the alarm is active, pressing the button stops the buzzer.

This project improved my understanding of embedded systems because I had to combine several different components into one working system. Instead of only controlling one component at a time, I had to make the RTC, OLED, buzzer, and button work together.

The biggest lesson I learned was that troubleshooting is an important part of engineering. The project did not work perfectly on the first attempt, especially with the RTC time, but testing each part and changing the code helped me identify the problems.

Overall, I consider this project successful because I was able to build a functional alarm clock and gain more experience with I²C communication, real-time clocks, displays, buttons, and embedded programming.
