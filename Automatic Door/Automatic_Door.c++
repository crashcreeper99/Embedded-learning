#include <ESP32Servo.h>

Servo doorServo;

const int SERVO_PIN = 13;
const int PIR_PIN = 27;

const int CLOSED_POSITION = 20;
const int OPEN_POSITION = 100;

bool motionHandled = false;

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);

  doorServo.setPeriodHertz(50);
  doorServo.attach(SERVO_PIN, 500, 2400);

  doorServo.write(CLOSED_POSITION);

  Serial.println("PIR warming up...");
  delay(30000);   // give PIR time to stabilize

  Serial.println("Automatic Door Ready!");
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH && !motionHandled) {
    motionHandled = true;

    Serial.println("Motion detected - opening door");

    doorServo.write(OPEN_POSITION);
    delay(3000);

    doorServo.write(CLOSED_POSITION);

    Serial.println("Door closed");
  }

  // Only allow another trigger after PIR returns LOW
  if (motion == LOW) {
    motionHandled = false;
  }

  delay(100);
}
