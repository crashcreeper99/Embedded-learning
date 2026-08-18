// ESP32 Two-Player Reaction Battle
// Buttons connect between their GPIO pins and GND.

const int P1_BUTTON = 13;
const int P2_BUTTON = 14;
const int START_BUTTON = 27;

const int READY_LED = 18;
const int GO_LED = 19;
const int P1_LED = 25;
const int P2_LED = 26;

void setup() {
  Serial.begin(115200);

  pinMode(P1_BUTTON, INPUT_PULLUP);
  pinMode(P2_BUTTON, INPUT_PULLUP);
  pinMode(START_BUTTON, INPUT_PULLUP);

  pinMode(READY_LED, OUTPUT);
  pinMode(GO_LED, OUTPUT);
  pinMode(P1_LED, OUTPUT);
  pinMode(P2_LED, OUTPUT);

  randomSeed(micros());

  turnOffLEDs();

  Serial.println();
  Serial.println("TWO-PLAYER REACTION BATTLE");
  Serial.println("Press the START button.");
}

void loop() {
  // Start button reads LOW when pressed
  if (digitalRead(START_BUTTON) == LOW) {
    delay(30); // debounce

    if (digitalRead(START_BUTTON) == LOW) {
      Serial.println("Start button detected!");

      // Wait for the start button to be released
      while (digitalRead(START_BUTTON) == LOW) {
        delay(10);
      }

      delay(200);
      runGame();
    }
  }
}

void runGame() {
  turnOffLEDs();

  // Make sure player buttons are released
  Serial.println("Release both player buttons.");

  while (digitalRead(P1_BUTTON) == LOW ||
         digitalRead(P2_BUTTON) == LOW) {
    delay(10);
  }

  // Ready countdown
  Serial.println("Get ready...");

  for (int i = 0; i < 3; i++) {
    digitalWrite(READY_LED, HIGH);
    delay(300);
    digitalWrite(READY_LED, LOW);
    delay(300);
  }

  digitalWrite(READY_LED, HIGH);

  // Random wait between 2 and 5 seconds
  unsigned long randomWait = random(2000, 5001);
  unsigned long waitStart = millis();

  while (millis() - waitStart < randomWait) {
    // Player 1 pressed too early
    if (digitalRead(P1_BUTTON) == LOW) {
      digitalWrite(READY_LED, LOW);

      Serial.println("Player 1 pressed early!");
      Serial.println("Player 2 wins!");

      showWinner(P2_LED);
      endGame();
      return;
    }

    // Player 2 pressed too early
    if (digitalRead(P2_BUTTON) == LOW) {
      digitalWrite(READY_LED, LOW);

      Serial.println("Player 2 pressed early!");
      Serial.println("Player 1 wins!");

      showWinner(P1_LED);
      endGame();
      return;
    }

    delay(1);
  }

  // GO signal
  digitalWrite(READY_LED, LOW);
  digitalWrite(GO_LED, HIGH);

  unsigned long goTime = millis();

  Serial.println("GO!");

  while (true) {
    bool player1Pressed = digitalRead(P1_BUTTON) == LOW;
    bool player2Pressed = digitalRead(P2_BUTTON) == LOW;

    if (player1Pressed && player2Pressed) {
      digitalWrite(GO_LED, LOW);
      digitalWrite(P1_LED, HIGH);
      digitalWrite(P2_LED, HIGH);

      Serial.println("Tie!");

      delay(3000);
      endGame();
      return;
    }

    if (player1Pressed) {
      unsigned long reactionTime = millis() - goTime;

      digitalWrite(GO_LED, LOW);

      Serial.print("Player 1 wins! Time: ");
      Serial.print(reactionTime);
      Serial.println(" ms");

      showWinner(P1_LED);
      endGame();
      return;
    }

    if (player2Pressed) {
      unsigned long reactionTime = millis() - goTime;

      digitalWrite(GO_LED, LOW);

      Serial.print("Player 2 wins! Time: ");
      Serial.print(reactionTime);
      Serial.println(" ms");

      showWinner(P2_LED);
      endGame();
      return;
    }

    delay(1);
  }
}

void showWinner(int winnerLED) {
  digitalWrite(GO_LED, LOW);

  for (int i = 0; i < 6; i++) {
    digitalWrite(winnerLED, HIGH);
    delay(200);

    digitalWrite(winnerLED, LOW);
    delay(150);
  }

  digitalWrite(winnerLED, HIGH);
  delay(2000);
}

void endGame() {
  turnOffLEDs();

  // Wait for player buttons to be released
  while (digitalRead(P1_BUTTON) == LOW ||
         digitalRead(P2_BUTTON) == LOW) {
    delay(10);
  }

  Serial.println();
  Serial.println("Round finished.");
  Serial.println("Press START for another round.");
  delay(300);
}

void turnOffLEDs() {
  digitalWrite(READY_LED, LOW);
  digitalWrite(GO_LED, LOW);
  digitalWrite(P1_LED, LOW);
  digitalWrite(P2_LED, LOW);
}
