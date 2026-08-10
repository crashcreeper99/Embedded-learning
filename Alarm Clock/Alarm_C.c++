#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --------------------
// OLED
// --------------------
#define OLED_SDA 21
#define OLED_SCL 22

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire1, OLED_RESET);

// --------------------
// DS1307
// --------------------
#define RTC_SDA 18
#define RTC_SCL 19

RTC_DS1307 rtc;

// --------------------
// Buzzer
// --------------------
#define BUZZER_PIN 25

// Alarm time
int alarmHour = 7;
int alarmMinute = 0;

bool alarmEnabled = true;
bool alarmRinging = false;

// Prevent alarm from repeatedly triggering during same minute
int lastAlarmMinute = -1;

void setup() {

  Serial.begin(115200);

  // --------------------
  // OLED I2C
  // --------------------
  Wire1.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found!");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // --------------------
  // RTC I2C
  // --------------------
  Wire.begin(RTC_SDA, RTC_SCL);

  if (!rtc.begin(&Wire)) {
    Serial.println("DS1307 not found!");
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 20);
    display.println("DS1307 NOT FOUND!");
    display.display();

    while (true);
  }

  // If RTC lost power, set it to the compile time
  if (!rtc.isrunning()) {
    Serial.println("RTC not running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Alarm Clock Started!");
}

void loop() {

  DateTime now = rtc.now();

  // --------------------
  // Check alarm
  // --------------------
  if (alarmEnabled &&
      now.hour() == alarmHour &&
      now.minute() == alarmMinute &&
      lastAlarmMinute != now.minute()) {

    alarmRinging = true;
    lastAlarmMinute = now.minute();
  }

  // --------------------
  // Sound alarm
  // --------------------
  if (alarmRinging) {

    tone(BUZZER_PIN, 1000);

    // Stop alarm after 30 seconds
    if (now.second() >= 30) {
      noTone(BUZZER_PIN);
      alarmRinging = false;
    }

  } else {
    noTone(BUZZER_PIN);
  }

  // --------------------
  // Display
  // --------------------
  display.clearDisplay();

  // Time
  display.setTextSize(2);
  display.setCursor(10, 5);

  if (now.hour() < 10) display.print("0");
  display.print(now.hour());

  display.print(":");

  if (now.minute() < 10) display.print("0");
  display.print(now.minute());

  display.print(":");

  if (now.second() < 10) display.print("0");
  display.print(now.second());

  // Date
  display.setTextSize(1);
  display.setCursor(20, 30);

  if (now.month() < 10) display.print("0");
  display.print(now.month());
  display.print("/");

  if (now.day() < 10) display.print("0");
  display.print(now.day());
  display.print("/");
  display.print(now.year());

  // Alarm
  display.setCursor(10, 45);
  display.print("Alarm: ");

  if (alarmHour < 10) display.print("0");
  display.print(alarmHour);

  display.print(":");

  if (alarmMinute < 10) display.print("0");
  display.print(alarmMinute);

  display.setCursor(10, 56);

  if (alarmEnabled) {
    display.print("Alarm ON");
  } else {
    display.print("Alarm OFF");
  }

  if (alarmRinging) {
    display.setCursor(75, 56);
    display.print("RING!");
  }

  display.display();

  delay(250);
}
