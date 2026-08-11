# Reflection – Automatic Night Light

For this project, I built an automatic night light using an ESP32, an LDR sensor, and an LED. The goal was to create a system that could detect when the environment became dark and automatically turn on the LED.

One of the main things I learned was how an LDR can be used as a light sensor. The ESP32 reads the changing light level from the sensor and compares it to a threshold in the program. This allowed me to create a simple automatic decision-making system.

I also gained more experience wiring sensors and outputs to the ESP32. I used GPIO 34 to read the LDR signal and GPIO 25 to control the LED. Testing the project helped me understand how sensor readings change depending on the amount of light around the sensor.

The project worked successfully. When I covered the LDR and made the environment darker, the LED turned on. When I exposed the LDR to more light, the LED turned off.

Overall, this was a useful project because it combined **sensors, programming, analog input, and automatic output control**. It also gave me more experience building systems that respond to their environment, which is an important concept in embedded systems and smart-home technology.
