const int touchPin = 4;
const int ledPin = 21;

bool lampOn = false;
bool touchLocked = false;

// Adjust after viewing your touch readings.
int touchThreshold = 30;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  int touchValue = touchRead(touchPin);
  Serial.println(touchValue);

  bool touched = touchValue < touchThreshold;

  if (touched && !touchLocked) {
    lampOn = !lampOn;
    digitalWrite(ledPin, lampOn);
    touchLocked = true;

    Serial.println(lampOn ? "Lamp ON" : "Lamp OFF");
  }

  if (!touched) {
    touchLocked = false;
  }

  delay(80);
}
