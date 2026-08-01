// Define pins for ultrasonic sensor and buzzer
const int trigPin = 5;
const int echoPin = 18;
const int buzzerPin = 12;

// Variables for distance calculation
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600); // Initialize serial communication for debugging
}


void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  // Trigger the sensor by setting trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters (speed of sound = 343 m/s)
  distance = duration * 0.034 / 2;

  // Print the distance for debugging purposes
  Serial.print("Distance: ");
  Serial.println(distance);

  // Control the buzzer based on distance
  if (distance <= 10) {
    // Very close, fast beeping
    tone(buzzerPin, 1000);
    delay(100);
    noTone(buzzerPin);
    delay(100);
  } else if (distance <= 30) {
    // Medium distance, slower beeping
    tone(buzzerPin, 1000);
    delay(300);
    noTone(buzzerPin);
    delay(300);
  } else if (distance <= 50) {
    // Farther away, even slower beeping
    tone(buzzerPin, 1000);
    delay(500);
    noTone(buzzerPin);
    delay(500);
  } else {
    // No obstacle nearby, no beeping
    noTone(buzzerPin);
  }

  delay(100); // Short delay before the next reading
}
