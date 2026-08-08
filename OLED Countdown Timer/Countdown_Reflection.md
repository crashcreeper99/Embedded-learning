# Countdown Timer Reflection

For this project, I built a countdown timer using an ESP32, an OLED display, and two push buttons. The timer starts at one minute and counts down to zero. I used one button to start and pause the timer and another button to reset it.

One of the main things I learned was how to use `millis()` to keep track of time without completely stopping the program. This helped me understand how embedded systems can perform timing tasks while still checking inputs from buttons. I also practiced controlling an OLED display and organizing the program into different states such as running, paused, and finished.

The project was also useful because it built directly on my previous Digital Stopwatch OLED project. Instead of simply measuring elapsed time, I had to make the program count downward and stop when it reached zero.

Overall, this project improved my understanding of timing, user input, OLED displays, and program state management. A future version could include adjustable countdown times and a buzzer that sounds when the timer reaches zero.
