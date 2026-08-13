const int leds[] = {15, 5, 18, 19};
const int buttonPin = 23;

int number = 0;
bool lastButtonState = HIGH;

void displayBinary(int value) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], bitRead(value, i));
  }
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT_PULLUP);
  displayBinary(number);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    number++;

    if (number > 15) {
      number = 0;
    }

    displayBinary(number);
    Serial.println(number);
    delay(200);
  }

  lastButtonState = buttonState;
}
