// ESP32 Automatic Night Light
// 3-pin LDR module
// LDR signal -> GPIO 34
// LED -> GPIO 25

const int LDR_PIN = 34;
const int LED_PIN = 25;

// Change this if needed
const int DARK_THRESHOLD = 1800;

void setup() {
  Serial.begin(115200);

  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);

  Serial.println("Automatic Night Light");
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);

  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  // Dark = LED ON
  if (lightLevel < DARK_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
  }
  // Bright = LED OFF
  else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(300);
}
