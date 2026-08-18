# Two-Player Reaction Battle Reflection

This project taught me how to create a complete two-player game with an ESP32. The Start button begins the round, the ready LED gives both players time to prepare, and the blue channel of an RGB LED acts as the GO signal. I used the RGB LED because I did not use a separate white LED, and the blue light was clear enough for both players to see.

At first, the game was not starting correctly. I improved the code by checking the Start button directly, debouncing it, and waiting for it to be released before beginning the round. I also had to make sure every button was wired between its GPIO pin and GND because the program uses `INPUT_PULLUP`.

I learned how to detect false starts, compare two inputs quickly, and measure reaction time in milliseconds. The final game can identify Player 1, Player 2, or a tie. A future improvement would be adding a scoreboard or a best-of-five mode.
