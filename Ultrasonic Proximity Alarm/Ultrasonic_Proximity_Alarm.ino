#define TRIG_PIN 5
#define ECHO_PIN 18
#define BUZZER_PIN 25

const float WARNING_DISTANCE_CM = 15.0;

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;
  return duration * 0.0343 / 2.0;
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  float distance = readDistanceCm();

  if (distance > 0) {
    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");

    if (distance <= WARNING_DISTANCE_CM) {
      tone(BUZZER_PIN, 1200);
    } else {
      noTone(BUZZER_PIN);
    }
  } else {
    Serial.println("No echo detected");
    noTone(BUZZER_PIN);
  }

  delay(100);
}
