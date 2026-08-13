const int leds[] = {15, 5, 18, 19};
const int numberOfLEDs = 4;

void turnOffLEDs() {
  for (int i = 0; i < numberOfLEDs; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < numberOfLEDs; i++) {
    pinMode(leds[i], OUTPUT);
  }

  randomSeed(analogRead(34));
}

void loop() {
  turnOffLEDs();

  int selectedLED = random(0, numberOfLEDs);
  digitalWrite(leds[selectedLED], HIGH);

  Serial.print("Selected LED: ");
  Serial.println(selectedLED + 1);

  delay(500);
}
