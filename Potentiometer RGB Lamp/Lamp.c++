// Potentiometer RGB Lamp
// ESP32

#define POT_PIN 34

#define RED_PIN   25
#define GREEN_PIN 26
#define BLUE_PIN  27

void setup() {
  Serial.begin(115200);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Start with lamp off
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);
}

void loop() {

  // Read potentiometer
  int potValue = analogRead(POT_PIN);

  // ESP32 ADC = 0 to 4095
  int brightness = map(potValue, 0, 4095, 0, 255);

  // Make a continuously changing RGB color
  int redValue   = brightness;
  int greenValue = 255 - brightness;
  int blueValue  = abs(127 - brightness) * 2;

  // Keep values between 0 and 255
  redValue   = constrain(redValue, 0, 255);
  greenValue = constrain(greenValue, 0, 255);
  blueValue  = constrain(blueValue, 0, 255);

  analogWrite(RED_PIN, redValue);
  analogWrite(GREEN_PIN, greenValue);
  analogWrite(BLUE_PIN, blueValue);

  Serial.print("Pot: ");
  Serial.print(potValue);

  Serial.print(" | R: ");
  Serial.print(redValue);

  Serial.print(" G: ");
  Serial.print(greenValue);

  Serial.print(" B: ");
  Serial.println(blueValue);

  delay(10);
}
