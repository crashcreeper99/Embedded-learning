#include <ESP32Servo.h>

Servo myServo;

const int servoPin = 18;
const int potPin = 34;

void setup() {
  Serial.begin(115200);

  myServo.setPeriodHertz(50);      // Standard servo frequency
  myServo.attach(servoPin, 500, 2400);
}

void loop() {

  int potValue = analogRead(potPin);

  // Convert 0-4095 to 0-180 degrees
  int angle = map(potValue, 0, 4095, 0, 180);

  myServo.write(angle);

  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print("   Angle: ");
  Serial.println(angle);

  delay(20);
}
