const int buttonPin = 23;
const int ledPin = 18;

int count = 0;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.println("Button Counter Ready");
  Serial.println("Count: 0");
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    count++;

    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);

    Serial.print("Count: ");
    Serial.println(count);

    delay(100);
  }

  lastButtonState = buttonState;
}
