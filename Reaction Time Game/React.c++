onst int ledPin = 25;
const int buttonPin = 27;

bool waiting = false;
unsigned long startTime;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(115200);
  randomSeed(analogRead(34));
}

void loop() {

  if (!waiting) {

    if (digitalRead(buttonPin) == LOW) {

      delay(300);

      Serial.println("Get Ready...");

      delay(random(2000,6000));

      digitalWrite(ledPin,HIGH);

      startTime = millis();

      waiting = true;
    }

  }

  else {

    if (digitalRead(buttonPin) == LOW) {

      unsigned long reaction = millis() - startTime;

      digitalWrite(ledPin,LOW);

      Serial.print("Reaction Time: ");
      Serial.print(reaction);
      Serial.println(" ms");

      waiting = false;

      delay(1000);

    }

  }

}
