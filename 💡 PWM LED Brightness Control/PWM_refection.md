# Project Reflection – PWM LED Brightness Control

In this project, I learned how to use Pulse Width Modulation (PWM) on the ESP32 to control the brightness of an LED. Unlike simply turning an LED on or off, PWM allowed me to smoothly adjust the brightness by changing the duty cycle of the signal. This helped me understand how microcontrollers can simulate analog output using digital pins.

One challenge I encountered was that the original PWM functions (`ledcSetup` and `ledcAttachPin`) did not compile because my ESP32 board package uses the newer Arduino Core API. After updating the code to use the correct functions, I successfully uploaded the program and verified that the LED smoothly faded from off to full brightness and back again.

This project strengthened my understanding of PWM, loops, variables, timing, and debugging. 
It also showed me the importance of checking software versions and adapting code to match the development environment. The skills I gained from this project will be useful in future embedded systems projects involving motor speed control, servo motors, LED lighting, and other hardware applications.
