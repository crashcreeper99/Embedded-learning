Project Reflection

Building this Traffic Light Simulator helped me move beyond controlling a single LED and introduced me to coordinating multiple outputs to model a real-world system. I wired and programmed an ESP32 DevKit V1 to control red, yellow, and green LEDs in the correct sequence, gaining experience with GPIO configuration, circuit assembly, and timing using the Arduino framework.

One of the biggest lessons from this project was learning how embedded systems execute tasks in a predictable sequence. I saw how changing timing values directly affects system behavior and why careful planning is important when designing firmware. Debugging the circuit also reinforced the importance of checking wiring, verifying GPIO pin assignments, and testing each component methodically.

This project strengthened my understanding of digital electronics, firmware development, and structured programming. It also showed me how simple hardware and software concepts combine to create systems that are used in everyday life.

As I continue my embedded systems journey, I plan to expand this project by replacing delay() with non-blocking timing using millis(), adding a pedestrian crossing button, implementing a finite state machine, and eventually building a smart traffic intersection with sensors. Each improvement will help me develop the skills needed for more advanced embedded, robotics, and IoT projects.
