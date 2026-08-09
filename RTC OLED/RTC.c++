#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// =========================
// OLED I2C PINS
// =========================
#define OLED_SDA 21
#define OLED_SCL 22

// =========================
// DS1307 I2C PINS
// =========================
#define RTC_SDA 18
#define RTC_SCL 19

// =========================
// OLED
// =========================
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// Separate I2C bus for RTC
TwoWire RTCWire = TwoWire(1);

RTC_DS1307 rtc;

// =========================
// SETUP
// =========================

void setup() {

  Serial.begin(115200);
  delay(1000);

  // Start OLED I2C
  Wire.begin(OLED_SDA, OLED_SCL);

  // Start RTC I2C on separate pins
  RTCWire.begin(RTC_SDA, RTC_SCL);

  // Start OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {

    Serial.println("OLED NOT FOUND!");

    while (true);
  }

  Serial.println("OLED FOUND!");

  // Start DS1307 using separate I2C bus
  if (!rtc.begin(&RTCWire)) {

    Serial.println("DS1307 NOT FOUND!");

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(10, 25);
    display.println("DS1307 NOT FOUND");
    display.display();

    while (true);
  }

  Serial.println("DS1307 FOUND!");

  // Set RTC if it isn't running
  if (!rtc.isrunning()) {

    Serial.println("RTC was not running.");
    Serial.println("Setting time...");

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Startup screen
  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);

  display.setCursor(15, 20);
  display.println("RTC CLOCK");

  display.display();

  delay(1500);
}

// =========================
// LOOP
// =========================

void loop() {

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
  // OLED DISPLAY
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
  display.setCursor(25, 32);

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
  display.setCursor(35, 50);
  display.print("DS1307 OK");

  display.display();

  delay(1000);
}
