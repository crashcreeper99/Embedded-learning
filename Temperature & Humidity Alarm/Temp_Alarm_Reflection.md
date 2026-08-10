# Project Reflection — DHT22 Temperature & Humidity Alarm

Building the DHT22 Temperature & Humidity Alarm was a useful step in developing my embedded systems and electronics skills. The project combined several components I had already worked with, including the ESP32, OLED display, buzzer, and push button, while adding the DHT22 sensor.

One of the biggest challenges was getting the temperature and humidity sensor working correctly. I initially received sensor errors and had to troubleshoot the wiring and code. I also had an issue where the OLED was not displaying information correctly. Working through these problems helped me understand that troubleshooting an embedded system requires checking both the software and the physical connections.

Another challenge was getting the push button to properly silence the alarm. The button itself worked when tested separately, which helped me determine that the problem was with the alarm logic rather than the hardware. I modified the program so that pressing the button silences the buzzer while the alarm condition remains active. The alarm then resets after the environmental conditions return to normal.

This project taught me more about how sensors communicate with a microcontroller and how software can respond to real-world measurements. I also gained more experience with GPIO pins, I²C communication, sensor libraries, OLED displays, and conditional logic.

The most important lesson I learned was the importance of testing individual components when troubleshooting. Instead of assuming the entire project was broken, I tested the button separately and was able to identify where the problem actually existed.

Overall, I consider this project successful because I was able to build a working environmental monitoring system rather than simply displaying sensor readings. The project demonstrates practical embedded programming, hardware integration, troubleshooting, and control-system logic. It also gives me a foundation for future projects involving Wi-Fi monitoring, data logging, and automated environmental control.
