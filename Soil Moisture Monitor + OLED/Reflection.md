# Project Reflection — Soil Moisture Monitor + OLED

This project helped me understand how an analog sensor can be turned into information that is actually useful. The soil-moisture probe did not directly give me a percentage. It gave the ESP32 a raw analog value, so I had to map that value and limit the result between 0 and 100.

The biggest thing I learned was the importance of calibration. The raw value can change depending on the sensor, the soil, and how wet the probe is. Testing the sensor in dry and wet conditions made the display more accurate and showed me why real sensor systems cannot always rely on one set of fixed numbers.

I also got more practice using I2C and presenting sensor data on an OLED instead of only looking at the Serial Monitor. Displaying the percentage and a simple status such as dry, good, or very wet made the project feel more like a finished product.

If I improve this project later, I would smooth the readings by averaging multiple samples, log the moisture over time, and add an automatic watering feature using a relay and pump. This project gave me more experience connecting sensing, calibration, decision logic, and a user display in one embedded system.
