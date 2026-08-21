# OLED Sensor Menu

## Overview
This project creates a button-controlled menu interface on the ESP32 and SSD1306 OLED. Instead of showing one fixed screen, the user presses a button to switch between different information pages. This introduces user-interface state management, menu navigation, and display programming.

## Components
- ESP32 DevKit V1
- 0.96-inch SSD1306 I2C OLED
- Push button
- Breadboard and jumper wires

## Wiring
### OLED
| OLED | ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### Button
| Button | ESP32 |
|---|---|
| Side 1 | GPIO 27 |
| Side 2 | GND |

The program uses `INPUT_PULLUP`, so an external pull-up resistor is not required.

## Required Libraries
- Adafruit GFX Library
- Adafruit SSD1306

## How It Works
The ESP32 keeps track of the current menu page. Each valid button press advances to the next page. After the final page, the interface returns to the first page. The example has Status, System, and About pages and can later be expanded to show real sensor data.

## Example Code
```cpp
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define BUTTON_PIN 27

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int page = 0;
bool lastButton = HIGH;
unsigned long lastPress = 0;

void drawPage() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ESP32 SENSOR MENU");
  display.drawLine(0, 10, 127, 10, SSD1306_WHITE);

  display.setCursor(0, 20);

  if (page == 0) {
    display.println("> Status");
    display.println("  System");
    display.println("  About");
  } else if (page == 1) {
    display.println("SYSTEM");
    display.println("Board: ESP32");
    display.println("State: Running");
  } else {
    display.println("ABOUT");
    display.println("OLED Menu UI");
    display.println("Button: Next page");
  }

  display.display();
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true) {}
  }

  drawPage();
}

void loop() {
  bool button = digitalRead(BUTTON_PIN);

  if (lastButton == HIGH && button == LOW && millis() - lastPress > 200) {
    page = (page + 1) % 3;
    lastPress = millis();
    drawPage();
  }

  lastButton = button;
}
```

## Testing
1. Power the ESP32 and confirm that the first menu appears.
2. Press the button once and verify that the System page appears.
3. Press again to show the About page.
4. Press again and confirm that the menu returns to the first page.
5. Make sure one physical press causes only one page change.

## What I Learned
- Building a simple embedded user interface
- Managing application states with a variable
- Button edge detection and debouncing
- Updating an OLED only when the interface state changes
- Designing firmware that can be expanded into a larger device menu

## Future Improvements
- Add a second button for Back/Select controls
- Display DHT22 readings on a sensor page
- Add Wi-Fi status and IP address pages
- Build a settings menu
