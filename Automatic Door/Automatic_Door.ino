#include <ESP32Servo.h>

Servo doorServo;

const int SERVO_PIN = 13;
const int PIR_PIN = 27;

const int CLOSED_POSITION = 20;
const int OPEN_POSITION = 100;

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);

  doorServo.setPeriodHertz(50);
  doorServo.attach(SERVO_PIN, 500, 2400);

  doorServo.write(CLOSED_POSITION);

  Serial.println("PIR warming up...");
  delay(10000);

  Serial.println("Automatic Door Ready!");
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    Serial.println("Motion detected!");

    // Open the door
    doorServo.write(OPEN_POSITION);
    delay(3000);

    // Close the door
    doorServo.write(CLOSED_POSITION);
    delay(2000);
  }
}
