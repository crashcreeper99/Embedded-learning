# Project Reflection — ESP32 Capacitive-Touch Lamp

This project taught me that the ESP32 can detect touch without needing a normal push button. I used a jumper wire or conductive surface as the touch pad and watched how the sensor value changed when I touched it.

The main challenge was choosing the correct threshold. The untouched value and touched value were not exactly the same every time, so I had to use the Serial Monitor and pick a value that separated them reliably. This showed me that capacitive sensors are affected by the environment and need calibration.

I also learned why the program needed a lockout after detecting a touch. Without it, holding the wire could make the LED switch on and off many times. Waiting for the touch pad to be released made each touch count as one clean command.

I liked this project because it created a simple user interface with almost no extra hardware. In the future, I could add brightness control, an RGB LED, or several touch pads. This project gave me more experience with sensor thresholds, state control, and designing an interaction that feels responsive to the user.
