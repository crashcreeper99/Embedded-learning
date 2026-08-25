# Project Reflection — RFID Attendance / Check-In System

This project gave me my first working experience with RFID identification on the ESP32. At first, the attendance program was not showing anything when I scanned the tag. I learned that the best way to solve that problem was to simplify the build and test the MFRC522 by itself before combining it with the RTC and display. That helped me confirm the reader, wiring, and tag were working.

One of the biggest wiring problems was the reset pin. GPIO 22 was already being used as the I2C clock line for the RTC and optional OLED, so I needed to connect the RFID reader's RST pin to GPIO 27 and make the code match. I also learned that the MFRC522 uses 3.3V and reads compatible 13.56 MHz tags.

After the reader worked, I scanned my tag to find its real UID, `F9 63 5D 20`, and registered it under my name instead of using a placeholder UID. The system could then recognize me and change my status between checked in and checked out. Adding a cooldown was important because the ESP32 loops very quickly and could otherwise register the same tag multiple times.

The real-time clock also taught me that detecting an RTC is different from setting it correctly. The DS1307 can keep an old time even while it is running, so I needed to synchronize it once and then stop resetting it on every restart. I also learned that the OLED is optional: the attendance logic can work through the Serial Monitor, while a display makes the project feel more like a standalone product.

This project brought together SPI, I2C, stored user data, timekeeping, state changes, and troubleshooting multiple modules in one system. If I improve it later, I would save attendance history to a microSD card or online database, use Wi-Fi to synchronize time, add an enrollment mode, and build a case that makes it look like a finished check-in terminal.
