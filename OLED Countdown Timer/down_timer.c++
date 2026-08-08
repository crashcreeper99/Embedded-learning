#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Buttons
const int START_BUTTON = 19;
const int RESET_BUTTON = 18;

// Starting time: 1 minute
int totalSeconds = 60;

bool running = false;

unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);

  pinMode(START_BUTTON, INPUT_PULLUP);
  pinMode(RESET_BUTTON, INPUT_PULLUP);

  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found!");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  showTimer();
}

void loop() {

  // START / PAUSE button
  if (digitalRead(START_BUTTON) == LOW) {
    delay(200);

    running = !running;

    while (digitalRead(START_BUTTON) == LOW) {
      delay(10);
    }
  }

  // RESET button
  if (digitalRead(RESET_BUTTON) == LOW) {
    delay(200);

    running = false;
    totalSeconds = 60;

    while (digitalRead(RESET_BUTTON) == LOW) {
      delay(10);
    }
  }

  // Countdown
  if (running) {

    if (millis() - previousMillis >= 1000) {
      previousMillis = millis();

      if (totalSeconds > 0) {
        totalSeconds--;
      }

      if (totalSeconds == 0) {
        running = false;
      }
    }
  }

  showTimer();

  delay(50);
}

void showTimer() {

  int minutes = totalSeconds / 60;
  int seconds = totalSeconds % 60;

  display.clearDisplay();

  // Title
  display.setTextSize(1);
  display.setCursor(35, 5);
  display.println("COUNTDOWN");

  // Timer
  display.setTextSize(3);
  display.setCursor(25, 25);

  if (minutes < 10) {
    display.print("0");
  }

  display.print(minutes);
  display.print(":");

  if (seconds < 10) {
    display.print("0");
  }

  display.print(seconds);

  // Status
  display.setTextSize(1);
  display.setCursor(35, 55);

  if (totalSeconds == 0) {
    display.print("TIME'S UP!");
  }
  else if (running) {
    display.print("RUNNING");
  }
  else {
    display.print("PAUSED");
  }

  display.display();
}
