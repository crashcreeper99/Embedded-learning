const int ledPin = 18;
const int buttonPin = 23;

const int dotTime = 200;
const int dashTime = dotTime * 3;

bool lastButtonState = HIGH;

void signalOn(int duration) {
  digitalWrite(ledPin, HIGH);
  delay(duration);
  digitalWrite(ledPin, LOW);
  delay(dotTime);
}

void dot() {
  signalOn(dotTime);
}

void dash() {
  signalOn(dashTime);
}

void sendS() {
  dot();
  dot();
  dot();
}

void sendO() {
  dash();
  dash();
  dash();
}

void sendSOS() {
  sendS();
  delay(dotTime * 2);

  sendO();
  delay(dotTime * 2);

  sendS();
  delay(dotTime * 6);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    sendSOS();
  }

  lastButtonState = buttonState;
}
