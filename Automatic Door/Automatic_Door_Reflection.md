# Automatic Door Project Reflection

This project was one of the more frustrating ESP32 projects I have worked on because the servo originally would not move. At first I thought the problem might have been the code or even the ESP32 board. I tried an external breadboard power supply module, tested different wiring, and even tried another servo, but I was still having problems.

Instead of giving up on the project, I started testing everything separately. I disconnected the other components and tested the ESP32 by itself. The board uploaded code and worked correctly, which showed me that I did not need to replace it. I then tested the servo separately and eventually got it working using GPIO 13.

The biggest thing I learned from this project was how important troubleshooting is in electronics. A project can have correct code and still not work because of power, wiring, GPIO selection, or another hardware problem. Testing one component at a time made it much easier to figure out what was actually happening.

Once the servo worked, I could combine it with the PIR motion sensor so motion could trigger the servo to open and close the door. This project gave me more experience using sensors and actuators together instead of just controlling one component by itself.

I also learned not to immediately assume that a board or component is broken. I need to isolate the problem, test the simplest circuit possible, and then add components back one at a time. That troubleshooting process is something I can use on much more complicated embedded systems in the future.
