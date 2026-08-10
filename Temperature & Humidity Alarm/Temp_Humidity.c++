#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// ==========================
// OLED
// ==========================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_SDA 21
#define OLED_SCL 22

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);

// ==========================
// DHT22
// ==========================

#define DHT_PIN 4
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

// ==========================
// BUTTON + BUZZER
// ==========================

#define BUTTON_PIN 27
#define BUZZER_PIN 25

// ==========================
// ALARM LIMITS
// ==========================

float HIGH_TEMP = 80.0;
float LOW_TEMP = 40.0;
float HIGH_HUMIDITY = 70.0;

// ==========================
// VARIABLES
// ==========================

float temperatureF = NAN;
float humidity = NAN;

bool alarmActive = false;
bool alarmSilenced = false;

bool lastButtonState = HIGH;

unsigned long lastSensorRead = 0;
unsigned long lastButtonPress = 0;

const unsigned long SENSOR_INTERVAL = 2500;
const unsigned long DEBOUNCE_TIME = 250;

// ==========================
// SETUP
// ==========================

void setup() {

  Serial.begin(115200);

  // Button
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Buzzer
  pinMode(BUZZER_PIN, OUTPUT);
  noTone(BUZZER_PIN);

  // I2C
  Wire.begin(OLED_SDA, OLED_SCL);

  // OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {

    Serial.println("OLED NOT FOUND!");

    while (true) {
      delay(1000);
    }
  }

  // DHT22
  dht.begin();

  // Startup screen
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(10, 5);
  display.println("DHT22");

  display.setCursor(10, 28);
  display.println("ALARM");

  display.display();

  delay(2000);

  Serial.println("================================");
  Serial.println("DHT22 TEMPERATURE/HUMIDITY ALARM");
  Serial.println("================================");
}

// ==========================
// LOOP
// ==========================

void loop() {

  // Always check button
  checkButton();

  // Read sensor every 2.5 seconds
  if (millis() - lastSensorRead >= SENSOR_INTERVAL) {

    lastSensorRead = millis();

    readSensor();

    if (!isnan(temperatureF) &&
        !isnan(humidity)) {

      checkAlarm();
      updateDisplay();

    } else {

      showSensorError();
    }
  }
}

// ==========================
// BUTTON
// ==========================

void checkButton() {

  bool buttonState = digitalRead(BUTTON_PIN);

  // Detect new button press
  if (lastButtonState == HIGH &&
      buttonState == LOW &&
      millis() - lastButtonPress > DEBOUNCE_TIME) {

    lastButtonPress = millis();

    Serial.println("BUTTON PRESSED");

    // If alarm is sounding, silence it
    if (alarmActive && !alarmSilenced) {

      alarmSilenced = true;

      noTone(BUZZER_PIN);

      Serial.println(">>> ALARM SILENCED <<<");

      updateDisplay();
    }
  }

  lastButtonState = buttonState;
}

// ==========================
// READ DHT22
// ==========================

void readSensor() {

  float newHumidity = dht.readHumidity();

  float temperatureC = dht.readTemperature();

  if (isnan(newHumidity) ||
      isnan(temperatureC)) {

    Serial.println("DHT22 SENSOR ERROR!");

    temperatureF = NAN;
    humidity = NAN;

    return;
  }

  humidity = newHumidity;

  temperatureF =
    (temperatureC * 9.0 / 5.0) + 32.0;

  Serial.println("----------------------------");

  Serial.print("Temperature: ");
  Serial.print(temperatureF, 1);
  Serial.println(" F");

  Serial.print("Humidity: ");
  Serial.print(humidity, 1);
  Serial.println(" %");
}

// ==========================
// ALARM LOGIC
// ==========================

void checkAlarm() {

  // Check environmental limits
  bool tooHot =
    temperatureF >= HIGH_TEMP;

  bool tooCold =
    temperatureF <= LOW_TEMP;

  bool tooHumid =
    humidity >= HIGH_HUMIDITY;

  bool dangerousCondition =
    tooHot ||
    tooCold ||
    tooHumid;


  // ==========================
  // NORMAL CONDITIONS
  // ==========================

  if (!dangerousCondition) {

    alarmActive = false;

    // Reset silence
    alarmSilenced = false;

    noTone(BUZZER_PIN);

    Serial.println("Status: NORMAL");

    return;
  }


  // ==========================
  // DANGEROUS CONDITION
  // ==========================

  alarmActive = true;


  // Only sound if user hasn't
  // pressed the silence button
  if (!alarmSilenced) {

    tone(BUZZER_PIN, 2000);

    Serial.println("!!! ALARM ACTIVE !!!");

  } else {

    noTone(BUZZER_PIN);

    Serial.println("Alarm active - SILENCED");
  }
}

// ==========================
// OLED DISPLAY
// ==========================

void updateDisplay() {

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  // Title
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("TEMP & HUMIDITY");

  // Temperature
  display.setTextSize(2);
  display.setCursor(0, 14);

  display.print(temperatureF, 1);
  display.println(" F");

  // Humidity
  display.setTextSize(1);
  display.setCursor(0, 39);

  display.print("Humidity: ");
  display.print(humidity, 1);
  display.println("%");

  // Status
  display.setCursor(0, 53);

  if (alarmActive && alarmSilenced) {

    display.print("ALARM SILENCED");

  }
  else if (alarmActive) {

    display.print("!!! ALARM !!!");

  }
  else {

    display.print("Status: NORMAL");
  }

  display.display();
}

// ==========================
// SENSOR ERROR
// ==========================

void showSensorError() {

  noTone(BUZZER_PIN);

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(5, 5);
  display.println("DHT22");

  display.setTextSize(1);
  display.setCursor(5, 30);
  display.println("SENSOR ERROR");

  display.setCursor(5, 45);
  display.println("DATA -> GPIO 4");

  display.display();
}
