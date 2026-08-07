# Reflection

The Digital Stopwatch project helped me better understand how to build interactive embedded systems using the ESP32. Unlike previous projects that mainly controlled LEDs or buzzers, this project required keeping accurate time while responding to button presses without stopping the rest of the program. Using the `millis()` function instead of `delay()` showed me how professional embedded applications perform multiple tasks at the same time.

I connected the OLED display using the I2C interface and used GPIO 19 for the Start/Pause button and GPIO 18 for the Reset button. Configuring the buttons with the ESP32's internal pull-up resistors simplified the wiring and made the button inputs reliable.

One challenge was making sure the stopwatch continued counting accurately while allowing the buttons to respond immediately. I learned how to keep track of elapsed time, update the display continuously, and switch between running, paused, and reset states.

This project strengthened my understanding of embedded programming concepts such as state machines, timing, button handling, and display communication. It also improved my troubleshooting skills when testing the hardware and verifying that the OLED updated correctly.

Completing this project brings me another step closer to my goal of building more advanced embedded systems. The techniques I learned here will be useful in future projects such as countdown timers, digital clocks, data loggers, menu-based interfaces, and IoT devices.
