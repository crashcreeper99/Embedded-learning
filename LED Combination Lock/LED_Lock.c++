// ESP32 LED Combination Lock
// Correct combination: Button 1, Button 3, Button 2, Button 4

const int buttonPins[4] = {13, 14, 25, 26};
const int greenLED = 18;
const int redLED = 19;

const int combination[4] = {0, 2, 1, 3};
int entered[4];
int enteredCount = 0;

bool lastButtonState[4] = {HIGH, HIGH, HIGH, HIGH};
bool locked = true;

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);

  Serial.println("Combination: 1, 3, 2, 4");
}

void loop() {
  if (!locked) {
    // Press all four buttons together to relock
    bool allPressed = true;

    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttonPins[i]) == HIGH) {
        allPressed = false;
      }
    }

    if (allPressed) {
      delay(500);
      locked = true;
      enteredCount = 0;
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
      Serial.println("Lock reset");
    }

    return;
  }

  for (int i = 0; i < 4; i++) {
    bool currentState = digitalRead(buttonPins[i]);

    if (lastButtonState[i] == HIGH && currentState == LOW) {
      entered[enteredCount] = i;
      enteredCount++;

      Serial.print("Button ");
      Serial.print(i + 1);
      Serial.println(" entered");

      delay(40);

      if (enteredCount == 4) {
        checkCombination();
      }
    }

    lastButtonState[i] = currentState;
  }
}

void checkCombination() {
  bool correct = true;

  for (int i = 0; i < 4; i++) {
    if (entered[i] != combination[i]) {
      correct = false;
    }
  }

  if (correct) {
    locked = false;
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    Serial.println("ACCESS GRANTED");

    for (int i = 0; i < 3; i++) {
      digitalWrite(greenLED, LOW);
      delay(150);
      digitalWrite(greenLED, HIGH);
      delay(150);
    }
  } else {
    Serial.println("ACCESS DENIED");

    for (int i = 0; i < 3; i++) {
      digitalWrite(redLED, LOW);
      delay(150);
      digitalWrite(redLED, HIGH);
      delay(150);
    }
  }

  enteredCount = 0;
}
