#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int buttonPin = 4;

int lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT_PULLUP);

  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed");
    while (true);
  }

  randomSeed(micros());

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(12, 10);
  display.println("Digital");
  display.setCursor(30, 35);
  display.println("Dice");
  display.display();
}

void loop() {

  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {

    for (int i = 0; i < 12; i++) {
      int roll = random(1, 7);

      display.clearDisplay();
      display.setTextSize(6);
      display.setCursor(45, 8);
      display.println(roll);
      display.display();

      delay(80);
    }

    int finalRoll = random(1, 7);

    display.clearDisplay();
    display.setTextSize(6);
    display.setCursor(45, 8);
    display.println(finalRoll);
    display.display();
  }

  lastButtonState = buttonState;
}
