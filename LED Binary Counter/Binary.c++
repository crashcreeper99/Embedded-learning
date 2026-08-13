const int leds[] = {16, 17, 18, 19};
const int buttonPin = 23;

int counter = 0;
bool lastButtonState = HIGH;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT_PULLUP);

  displayBinary(counter);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    counter++;

    if (counter > 15) {
      counter = 0;
    }

    displayBinary(counter);
    delay(200);
  }

  lastButtonState = buttonState;
}

void displayBinary(int number) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], (number >> i) & 1);
  }
}
