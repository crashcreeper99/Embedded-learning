const int potPin = 34;
const int leds[] = {15, 5, 18, 19, 22  };
const int numberOfLEDs = 5;

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < numberOfLEDs; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int potValue = analogRead(potPin);
  int ledLevel = map(potValue, 0, 4095, 0, numberOfLEDs + 1);

  for (int i = 0; i < numberOfLEDs; i++) {
    digitalWrite(leds[i], i < ledLevel ? HIGH : LOW);
  }

  Serial.println(potValue);
  delay(50);
}
