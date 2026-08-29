#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  WiFi.begin(ssid, password);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Connecting...");
  display.display();

  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void loop() {
  long rssi = WiFi.RSSI();

  String quality;
  if (rssi >= -50) quality = "EXCELLENT";
  else if (rssi >= -60) quality = "GOOD";
  else if (rssi >= -70) quality = "FAIR";
  else quality = "WEAK";

  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("WiFi Signal");
  display.setTextSize(2);
  display.print(rssi);
  display.println(" dBm");
  display.setTextSize(1);
  display.println(quality);
  display.display();

  Serial.printf("RSSI: %ld dBm - %s\n", rssi, quality.c_str());
  delay(1000);
}
