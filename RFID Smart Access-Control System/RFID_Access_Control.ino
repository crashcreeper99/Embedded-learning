#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 22
#define RED_PIN 25
#define GREEN_PIN 26
#define BLUE_PIN 27
#define BUZZER_PIN 14

MFRC522 rfid(SS_PIN, RST_PIN);

// Replace these bytes with the UID from your authorized card.
byte authorizedUID[] = {0xDE, 0xAD, 0xBE, 0xEF};
const byte authorizedUIDSize = sizeof(authorizedUID);

void setColor(bool red, bool green, bool blue) {
  digitalWrite(RED_PIN, red ? HIGH : LOW);
  digitalWrite(GREEN_PIN, green ? HIGH : LOW);
  digitalWrite(BLUE_PIN, blue ? HIGH : LOW);
}

bool isAuthorized() {
  if (rfid.uid.size != authorizedUIDSize) return false;
  for (byte i = 0; i < authorizedUIDSize; i++) {
    if (rfid.uid.uidByte[i] != authorizedUID[i]) return false;
  }
  return true;
}

void setup() {
  Serial.begin(115200);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  setColor(false, false, true);

  SPI.begin(18, 19, 23, SS_PIN);
  rfid.PCD_Init();
  Serial.println("RFID Access-Control System ready");
  Serial.println("Replace authorizedUID with your real card UID before final testing.");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  Serial.print("Scanned UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) Serial.print("0");
    Serial.print(rfid.uid.uidByte[i], HEX);
    if (i < rfid.uid.size - 1) Serial.print(" ");
  }
  Serial.println();

  if (isAuthorized()) {
    Serial.println("ACCESS GRANTED");
    setColor(false, true, false);
    tone(BUZZER_PIN, 1800, 150);
  } else {
    Serial.println("ACCESS DENIED");
    setColor(true, false, false);
    tone(BUZZER_PIN, 500, 500);
  }

  delay(1500);
  setColor(false, false, true);
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
