# Reflection – Random LED Generator

For this project, I used an ESP32 and four LEDs to make a random LED generator. The program turned off the previous LED, randomly selected a new one, and turned it on for half a second.

I learned more about arrays and random-number generation in Arduino C++. Storing the pins in an array made it possible to control all four LEDs with loops instead of repeating the same code. I also used an analog reading to seed the random-number generator so the sequence would not always begin the same way.

The Serial Monitor was useful because it showed the number of the LED selected by the program. I could compare that number with the LED that actually turned on and verify that the wiring and code agreed.

Overall, the project worked successfully. It was simple, but it gave me more practice writing reusable functions, working with arrays, and creating behavior that changes automatically instead of following one fixed pattern.
