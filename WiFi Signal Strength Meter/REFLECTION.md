# Reflection

For this project I built a Wi-Fi signal strength meter using the ESP32 and an OLED display. The ESP32 connected to my Wi-Fi network and measured the RSSI value in dBm so I could see how strong or weak the connection was.

The main thing I learned was how Wi-Fi signal strength is represented. Before this project I mostly thought of Wi-Fi as either connected or disconnected, but this showed me that the ESP32 can measure how strong the connection actually is. I also learned that values closer to 0 dBm mean a stronger connection while more negative values mean a weaker signal.

I practiced using the ESP32 Wi-Fi library, reading RSSI values, creating thresholds for different signal-quality levels, and displaying the results on the OLED. I also tested the project by changing my distance from the Wi-Fi source and watching the reading change.

If I improve this project later, I would add a way to save the strongest and weakest readings and possibly turn it into a portable Wi-Fi dead-zone finder.