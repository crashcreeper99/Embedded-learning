# Reflection – Button Counter

For this project, I built a button counter using an ESP32, a push button, and an LED. Each time I pressed the button, the count increased by one in the Serial Monitor and the LED flashed to confirm that the press was detected.

The main thing I learned was how to detect a change in a button's state. Instead of increasing the counter during every loop while the button was held down, the code compared the current and previous states. It only counted the transition from HIGH to LOW.

I also practiced using `INPUT_PULLUP`, which let me connect the button directly between GPIO 23 and ground without adding a separate pull-up resistor. The LED feedback made the project easier to test because I could immediately see when the ESP32 accepted a press.

The project worked successfully and gave me a better understanding of reliable digital input. This type of logic can be reused in scoreboards, menus, item counters, and many other embedded-system projects.
