#define TRIG_PIN 5
#define ECHO_PIN 18
#define LED_PIN 26
#define BUZZER_PIN 25

const float SECURITY_DISTANCE_CM = 25.0;
bool alarmActive = false;

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
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  float distance = readDistanceCm();

  if (distance > 0) {
    Serial.print("Protected-zone distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");

    if (distance <= SECURITY_DISTANCE_CM) {
      if (!alarmActive) Serial.println("INTRUSION DETECTED");
      alarmActive = true;
      digitalWrite(LED_PIN, HIGH);
      tone(BUZZER_PIN, 1700);
    } else {
      if (alarmActive) Serial.println("Zone clear");
      alarmActive = false;
      digitalWrite(LED_PIN, LOW);
      noTone(BUZZER_PIN);
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }

  delay(100);
}
