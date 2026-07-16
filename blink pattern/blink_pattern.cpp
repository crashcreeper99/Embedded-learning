


// Define GPIO pins for LEDs
const int redLED = 23;
const int yellowLED = 22;
const int greenLED = 21;

void setup() {
  // Set LED pins as output
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // Red light on, others off
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  delay(5000); // Red light for 5 seconds
  
  // Yellow light on, others off
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  delay(2000); // Yellow light for 2 seconds
  
  // Green light on, others off
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(5000); // Green light for 5 seconds

  // Repeat the cycle
}
