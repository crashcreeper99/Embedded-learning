# LED Combination Lock Reflection

This project taught me how to turn several button inputs into a working combination system. I used an array to store the order of the buttons and compared it with the correct sequence. The green LED showed when the combination was right, while the red LED showed that the lock was still locked or that the sequence was wrong.

The main thing I had to pay attention to was the button wiring and the order of the GPIO pins. Since the buttons used `INPUT_PULLUP`, they read LOW when pressed. I also learned why debouncing matters, because one physical press can sometimes be read more than once.

I am proud that I made a basic digital lock using only buttons, LEDs, and code. A future improvement would be adding a servo so the correct combination could open a real lock or small door.
