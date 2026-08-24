#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define DHT_PIN 4
#define DHT_TYPE DHT22
#define PIR_PIN 27
#define LDR_PIN 34

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(DHT_PIN, DHT_TYPE);

const int DARK_THRESHOLD = 1800; // adjust after checking your sensor readings

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  dht.begin();
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialization failed");
    while (true) delay(10);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Smart Room Monitor");
  display.display();
  delay(1000);
}

void loop() {
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();
  bool occupied = digitalRead(PIR_PIN) == HIGH;
  int lightValue = analogRead(LDR_PIN);
  bool dark = lightValue < DARK_THRESHOLD;

  Serial.print("Temp: "); Serial.print(tempC);
  Serial.print(" C  Humidity: "); Serial.print(humidity);
  Serial.print(" %  PIR: "); Serial.print(occupied ? "Occupied" : "Empty");
  Serial.print("  Light: "); Serial.println(lightValue);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("SMART ROOM STATUS");
  display.println("----------------");

  if (isnan(tempC) || isnan(humidity)) {
    display.println("DHT22 read error");
  } else {
    display.print("Temp: "); display.print(tempC, 1); display.println(" C");
    display.print("Humidity: "); display.print(humidity, 0); display.println(" %");
  }

  display.print("Room: "); display.println(occupied ? "OCCUPIED" : "EMPTY");
  display.print("Light: "); display.println(dark ? "DARK" : "BRIGHT");
  display.print("Raw LDR: "); display.println(lightValue);
  display.display();

  delay(1000);
}
