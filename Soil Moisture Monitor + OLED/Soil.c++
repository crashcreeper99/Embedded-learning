#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

const int soilPin = 34;
const int dryValue = 3300;
const int wetValue = 1300;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (true);
  }
}

void loop() {
  int rawValue = analogRead(soilPin);
  int moisture = map(rawValue, dryValue, wetValue, 0, 100);
  moisture = constrain(moisture, 0, 100);

  String condition;

  if (moisture < 30) {
    condition = "DRY";
  } else if (moisture < 70) {
    condition = "GOOD";
  } else {
    condition = "VERY WET";
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("SOIL MOISTURE");

  display.setTextSize(3);
  display.setCursor(20, 18);
  display.print(moisture);
  display.print("%");

  display.setTextSize(1);
  display.setCursor(0, 52);
  display.print("Condition: ");
  display.print(condition);

  display.display();

  Serial.printf("Raw: %d | Moisture: %d%%\n", rawValue, moisture);
  delay(1000);
}
