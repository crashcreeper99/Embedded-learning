#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  delay(1000);
  Serial.println("\nESP32 I2C Diagnostic Tool");
}

void loop() {
  int devices = 0;

  Serial.println("\nScanning I2C bus...");

  for (byte address = 1; address < 127; address++) {

    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Device found: 0x");

      if (address < 16)
        Serial.print("0");

      Serial.println(address, HEX);
      devices++;
    }
  }

  Serial.print("Total devices: ");
  Serial.println(devices);

  delay(5000);
}
