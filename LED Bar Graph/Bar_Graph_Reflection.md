# Reflection – LED Bar Graph

For this project, I built an LED bar graph using an ESP32, a potentiometer, and five LEDs. When I turned the potentiometer, the ESP32 read the changing analog value and turned on a different number of LEDs.

This project helped me understand how an analog input can be converted into clear output levels. The potentiometer gave the ESP32 a value between about 0 and 4095, and the program mapped that large range to six possible bar levels, including all LEDs off.

I gained more practice using arrays, `analogRead()`, `map()`, loops, and conditional logic. I also learned that one sensor value can control several outputs at the same time. Testing the circuit with the Serial Monitor helped me compare the potentiometer reading with what the LEDs were displaying.

The project worked successfully. The LED bar increased and decreased as I rotated the potentiometer. This was a useful project because similar displays are used for battery levels, volume, temperature, and other measurements in real electronic systems.
