// ESP32 Electronic Piano
// Passive buzzer on GPIO 25
// Buttons on GPIO 27, 26, 14, 12

const int buzzerPin = 25;

const int buttonPins[4] = {27, 26, 14, 12};

// Notes that are easy to distinguish
const int notes[4] = {
  262,  // C4
  392,  // G4
  523,  // C5
  784   // G5
};

const int channel = 0;

void setup() {

  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  ledcSetup(channel, 2000, 8);
  ledcAttachPin(buzzerPin, channel);
}

void loop() {

  int note = 0;

  if (digitalRead(buttonPins[0]) == LOW) {
    note = notes[0];
  }
  else if (digitalRead(buttonPins[1]) == LOW) {
    note = notes[1];
  }
  else if (digitalRead(buttonPins[2]) == LOW) {
    note = notes[2];
  }
  else if (digitalRead(buttonPins[3]) == LOW) {
    note = notes[3];
  }

  ledcWriteTone(channel, note);

  delay(5);
}
