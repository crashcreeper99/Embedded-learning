
// the setup function runs once when you press reset or power the board
const int LED_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  slowBlink();
  delay(1000);

  fastBlink();
  delay(1000);

  doubleBlink();
  delay(1000);

  sosPattern();
  delay(1500);

  heartbeat();
  delay(1500);
}

// ----------------------------

void slowBlink() {
  for(int i = 0; i < 5; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }
}

void fastBlink() {
  for(int i = 0; i < 10; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
}

void doubleBlink() {
  for(int i = 0; i < 5; i++) {

    digitalWrite(LED_PIN, HIGH);
    delay(150);

    digitalWrite(LED_PIN, LOW);
    delay(150);

    digitalWrite(LED_PIN, HIGH);
    delay(150);

    digitalWrite(LED_PIN, LOW);
    delay(700);
  }
}

void sosPattern() {

  // S = ...
  for(int i = 0; i < 3; i++) {
    blink(150);
  }

  delay(250);

  // O = ---
  for(int i = 0; i < 3; i++) {
    blink(500);
  }

  delay(250);

  // S = ...
  for(int i = 0; i < 3; i++) {
    blink(150);
  }
}

void heartbeat() {

  digitalWrite(LED_PIN, HIGH);
  delay(120);
  digitalWrite(LED_PIN, LOW);
  delay(120);

  digitalWrite(LED_PIN, HIGH);
  delay(300);
  digitalWrite(LED_PIN, LOW);
  delay(800);
}

void blink(int timeOn) {
  digitalWrite(LED_PIN, HIGH);
  delay(timeOn);
  digitalWrite(LED_PIN, LOW);
  delay(timeOn);
}
