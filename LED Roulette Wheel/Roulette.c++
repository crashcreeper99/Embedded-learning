// ESP32 LED Roulette Wheel

const int ledPins[] = {13, 14, 18, 19, 25, 26};
const int ledCount = 6;
const int spinButton = 27;

bool lastButtonState = HIGH;
bool spinning = false;

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  pinMode(spinButton, INPUT_PULLUP);

  // Floating analog input helps create a different random sequence
  randomSeed(analogRead(34));

  Serial.println("Press the button to spin");
}

void loop() {
  bool currentButtonState = digitalRead(spinButton);

  if (lastButtonState == HIGH &&
      currentButtonState == LOW &&
      !spinning) {
    spinRoulette();
  }

  lastButtonState = currentButtonState;
  delay(10);
}

void showLED(int selectedLED) {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], i == selectedLED ? HIGH : LOW);
  }
}

void spinRoulette() {
  spinning = true;

  int currentLED = random(0, ledCount);
  int totalSteps = random(35, 56);

  for (int step = 0; step < totalSteps; step++) {
    showLED(currentLED);

    currentLED++;
    if (currentLED >= ledCount) {
      currentLED = 0;
    }

    // Starts fast and gradually slows down
    int spinDelay = 35 + (step * step) / 7;
    delay(spinDelay);
  }

  // Move back to the LED shown during the final step
  int winningLED = currentLED - 1;
  if (winningLED < 0) {
    winningLED = ledCount - 1;
  }

  showLED(winningLED);

  Serial.print("Winning LED: ");
  Serial.println(winningLED + 1);

  delay(500);

  // Wait until the player releases the button
  while (digitalRead(spinButton) == LOW) {
    delay(10);
  }

  spinning = false;
}
