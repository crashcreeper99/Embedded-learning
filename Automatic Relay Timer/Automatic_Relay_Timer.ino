const int RELAY_PIN = 26;
const int BUTTON_PIN = 27;

const unsigned long RELAY_DURATION = 10000; // 10 seconds

bool relayOn = false;
bool lastButtonState = HIGH;
unsigned long relayStartTime = 0;

// Many relay modules are active LOW. Change these if yours is active HIGH.
const int RELAY_ON = LOW;
const int RELAY_OFF = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(RELAY_PIN, RELAY_OFF);
  Serial.println("Automatic Relay Timer ready");
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  // Detect a new button press
  if (lastButtonState == HIGH && buttonState == LOW) {
    relayOn = true;
    relayStartTime = millis();
    digitalWrite(RELAY_PIN, RELAY_ON);
    Serial.println("Relay ON");
    delay(25); // simple debounce
  }

  lastButtonState = buttonState;

  if (relayOn && millis() - relayStartTime >= RELAY_DURATION) {
    relayOn = false;
    digitalWrite(RELAY_PIN, RELAY_OFF);
    Serial.println("Relay OFF");
  }
}
