#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// =========================
// OLED PINS
// =========================
#define OLED_SDA 21
#define OLED_SCL 22

// =========================
// DS1307 PINS
// =========================
#define RTC_SDA 18
#define RTC_SCL 19

// =========================
// OLED SETTINGS
// =========================
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

// OLED I2C bus
Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// Second I2C bus for DS1307
TwoWire RTCWire = TwoWire(1);

RTC_DS1307 rtc;

void setup() {

  Serial.begin(115200);
  delay(1000);

  // Start OLED on GPIO 21/22
  Wire.begin(OLED_SDA, OLED_SCL);

  // Start DS1307 on GPIO 18/19
  RTCWire.begin(RTC_SDA, RTC_SCL);

  // =========================
  // START OLED
  // =========================

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {

    Serial.println("OLED NOT FOUND!");

    while (true);
  }

  Serial.println("OLED FOUND!");

  // =========================
  // START DS1307
  // =========================

  if (!rtc.begin(&RTCWire)) {

    Serial.println("DS1307 NOT FOUND!");

    display.clearDisplay();

    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    display.setCursor(10, 15);
    display.println("RTC NOT FOUND");

    display.setCursor(10, 35);
    display.println("Check DS1307");

    display.display();

    while (true);
  }

  Serial.println("DS1307 FOUND!");

  // =========================
  // SET RTC TIME
  // =========================

  if (!rtc.isrunning()) {

    Serial.println("RTC is not running.");
    Serial.println("Setting time from computer...");

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Startup message
  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);

  display.setCursor(15, 20);
  display.println("RTC CLOCK");

  display.display();

  delay(1500);
}

void loop() {

  // Get time from DS1307
  DateTime now = rtc.now();

  // =========================
  // SERIAL MONITOR
  // =========================

  Serial.print("Time: ");

  if (now.hour() < 10)
    Serial.print("0");

  Serial.print(now.hour());
  Serial.print(":");

  if (now.minute() < 10)
    Serial.print("0");

  Serial.print(now.minute());
  Serial.print(":");

  if (now.second() < 10)
    Serial.print("0");

  Serial.println(now.second());

  // =========================
  // OLED
  // =========================

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  // TIME
  display.setTextSize(2);
  display.setCursor(8, 5);

  if (now.hour() < 10)
    display.print("0");

  display.print(now.hour());
  display.print(":");

  if (now.minute() < 10)
    display.print("0");

  display.print(now.minute());
  display.print(":");

  if (now.second() < 10)
    display.print("0");

  display.print(now.second());

  // DATE
  display.setTextSize(1);
  display.setCursor(28, 32);

  if (now.month() < 10)
    display.print("0");

  display.print(now.month());
  display.print("/");

  if (now.day() < 10)
    display.print("0");

  display.print(now.day());
  display.print("/");

  display.print(now.year());

  // STATUS
  display.setCursor(40, 50);
  display.print("DS1307");

  display.display();

  delay(1000);
}
