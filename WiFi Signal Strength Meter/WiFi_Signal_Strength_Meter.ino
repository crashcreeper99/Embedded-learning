#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

int rssiToPercent(long rssi) {
  if (rssi <= -100) return 0;
  if (rssi >= -50) return 100;
  return 2 * (rssi + 100);
}

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialization failed");
    while (true) delay(10);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Connecting WiFi...");
  display.display();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.reconnect();
    delay(1000);
    return;
  }

  long rssi = WiFi.RSSI();
  int percent = rssiToPercent(rssi);

  Serial.print("RSSI: ");
  Serial.print(rssi);
  Serial.print(" dBm  Signal: ");
  Serial.print(percent);
  Serial.println("%");

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("WiFi Signal Meter");
  display.print("Network: ");
  display.println(WiFi.SSID());
  display.print("RSSI: ");
  display.print(rssi);
  display.println(" dBm");
  display.print("Signal: ");
  display.print(percent);
  display.println(" %");

  int barWidth = map(percent, 0, 100, 0, 120);
  display.drawRect(4, 52, 120, 10, SSD1306_WHITE);
  display.fillRect(4, 52, barWidth, 10, SSD1306_WHITE);
  display.display();

  delay(1000);
}
