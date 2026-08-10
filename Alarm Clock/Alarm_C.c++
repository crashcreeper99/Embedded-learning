#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// =====================================================
// OLED
// =====================================================

#define OLED_SDA 21
#define OLED_SCL 22

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire1,
  OLED_RESET
);

// =====================================================
// DS1307
// =====================================================

#define RTC_SDA 18
#define RTC_SCL 19

RTC_DS1307 rtc;

// =====================================================
// BUZZER
// =====================================================

#define BUZZER_PIN 25

// =====================================================
// BUTTON
// =====================================================

#define BUTTON_PIN 27

// =====================================================
// ALARM
// 4:33 PM = 16:33
// =====================================================

const int ALARM_HOUR = 16;
const int ALARM_MINUTE = 33;

bool alarmRinging = false;
bool alarmTriggered = false;

// =====================================================
// SETUP
// =====================================================

void setup() {

  Serial.begin(115200);

  // ---------------------------------------------------
  // OLED
  // ---------------------------------------------------

  Wire1.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {

    Serial.println("OLED NOT FOUND!");

    while (true) {
      delay(1000);
    }
  }

  // ---------------------------------------------------
  // DS1307
  // ---------------------------------------------------

  Wire.begin(RTC_SDA, RTC_SCL);

  if (!rtc.begin(&Wire)) {

    Serial.println("DS1307 NOT FOUND!");

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    display.setCursor(0, 20);
    display.println("DS1307 NOT FOUND!");

    display.display();

    while (true) {
      delay(1000);
    }
  }

  // ---------------------------------------------------
  // ONLY SET RTC IF IT LOST POWER
  // ---------------------------------------------------

  if (!rtc.isrunning()) {

    Serial.println("RTC was not running.");
    Serial.println("Setting RTC to computer time...");

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // ---------------------------------------------------
  // BUZZER
  // ---------------------------------------------------

  pinMode(BUZZER_PIN, OUTPUT);
  noTone(BUZZER_PIN);

  // ---------------------------------------------------
  // BUTTON
  // ---------------------------------------------------

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // ---------------------------------------------------
  // STARTUP SCREEN
  // ---------------------------------------------------

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);

  display.setCursor(5, 5);
  display.println("ALARM");

  display.setCursor(5, 30);
  display.println("4:33 PM");

  display.display();

  delay(2000);

  Serial.println("==============================");
  Serial.println("ALARM CLOCK STARTED");
  Serial.println("Alarm: 4:33 PM");
  Serial.println("==============================");
}

// =====================================================
// LOOP
// =====================================================

void loop() {

  DateTime now = rtc.now();

  // ===================================================
  // PRINT TIME TO SERIAL
  // ===================================================

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

  // ===================================================
  // RESET ALARM AFTER MIDNIGHT
  // ===================================================

  if (now.hour() == 0 && now.minute() == 0) {
    alarmTriggered = false;
  }

  // ===================================================
  // CHECK ALARM
  // ===================================================

  if (!alarmTriggered &&
      now.hour() == ALARM_HOUR &&
      now.minute() == ALARM_MINUTE) {

    alarmRinging = true;
    alarmTriggered = true;

    Serial.println("************************");
    Serial.println("ALARM RINGING!");
    Serial.println("************************");
  }

  // ===================================================
  // BUTTON
  // ===================================================

  if (digitalRead(BUTTON_PIN) == LOW) {

    if (alarmRinging) {

      alarmRinging = false;

      noTone(BUZZER_PIN);

      Serial.println("ALARM STOPPED");

      delay(500);
    }
  }

  // ===================================================
  // BUZZER
  // ===================================================

  if (alarmRinging) {

    tone(BUZZER_PIN, 1000);

  } else {

    noTone(BUZZER_PIN);
  }

  // ===================================================
  // OLED
  // =====================================================

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  // ---------------------------------------------------
  // TIME
  // ---------------------------------------------------

  display.setTextSize(2);

  display.setCursor(5, 2);

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

  // ---------------------------------------------------
  // DATE
  // ---------------------------------------------------

  display.setTextSize(1);

  display.setCursor(25, 25);

  if (now.month() < 10)
    display.print("0");

  display.print(now.month());

  display.print("/");

  if (now.day() < 10)
    display.print("0");

  display.print(now.day());

  display.print("/");

  display.print(now.year());

  // ---------------------------------------------------
  // ALARM
  // ---------------------------------------------------

  display.setCursor(10, 38);

  display.print("Alarm: 04:33 PM");

  // ---------------------------------------------------
  // STATUS
  // ---------------------------------------------------

  display.setCursor(10, 52);

  if (alarmRinging) {

    display.print("RING! PRESS BUTTON");

  } else {

    display.print("Alarm: ON");
  }

  display.display();

  delay(500);
}

  
