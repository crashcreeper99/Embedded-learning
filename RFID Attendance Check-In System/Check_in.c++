#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------- RC522 pins ----------
#define RFID_SS_PIN    5
#define RFID_RST_PIN  27
#define RFID_SCK_PIN  18
#define RFID_MISO_PIN 19
#define RFID_MOSI_PIN 23

// ---------- I2C pins ----------
#define I2C_SDA_PIN 21
#define I2C_SCL_PIN 22

// ---------- OLED settings ----------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

MFRC522 rfid(RFID_SS_PIN, RFID_RST_PIN);
RTC_DS1307 rtc;
Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

bool oledWorking = false;
bool rtcWorking = false;

struct Person {
  const char* name;
  const char* uid;
  bool checkedIn;
  String lastScan;
};

// Replace these example UIDs with the UIDs from your scanner.
// Use uppercase letters and spaces exactly as printed.
Person people[] = {
  {"Lamar tag", "F9 63 5D 20", false, "--:--:--"},
  {"Lamar card", "9A 7E 4A 35", false, "--:--:--"}
};

const int numberOfPeople =
  sizeof(people) / sizeof(people[0]);

String lastUID = "";
unsigned long lastScanTime = 0;
const unsigned long scanCooldown = 2500;

// Create a UID string such as "83 4A 21 16".
String getScannedUID() {
  String uid = "";

  for (byte i = 0; i < rfid.uid.size; i++) {
    if (i > 0) {
      uid += " ";
    }

    if (rfid.uid.uidByte[i] < 0x10) {
      uid += "0";
    }

    uid += String(rfid.uid.uidByte[i], HEX);
  }

  uid.toUpperCase();
  return uid;
}

String getCurrentTime() {
  if (!rtcWorking) {
    return "NO RTC";
  }

  DateTime now = rtc.now();
  char timeBuffer[9];

  snprintf(
    timeBuffer,
    sizeof(timeBuffer),
    "%02d:%02d:%02d",
    now.hour(),
    now.minute(),
    now.second()
  );

  return String(timeBuffer);
}

String getCurrentDate() {
  if (!rtcWorking) {
    return "NO DATE";
  }

  DateTime now = rtc.now();
  char dateBuffer[11];

  snprintf(
    dateBuffer,
    sizeof(dateBuffer),
    "%02d/%02d/%04d",
    now.month(),
    now.day(),
    now.year()
  );

  return String(dateBuffer);
}

int getInsideCount() {
  int total = 0;

  for (int i = 0; i < numberOfPeople; i++) {
    if (people[i].checkedIn) {
      total++;
    }
  }

  return total;
}

void showMessage(
  String heading,
  String mainMessage,
  String line3 = "",
  String line4 = ""
) {
  if (!oledWorking) {
    return;
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(heading);

  display.setTextSize(2);
  display.setCursor(0, 16);
  display.println(mainMessage);

  display.setTextSize(1);
  display.setCursor(0, 45);
  display.println(line3);
  display.println(line4);

  display.display();
}

void showReadyScreen() {
  showMessage(
    "RFID ATTENDANCE",
    "READY",
    "Scan your tag",
    "Inside: " + String(getInsideCount())
  );
}

int findPerson(String scannedUID) {
  for (int i = 0; i < numberOfPeople; i++) {
    if (scannedUID.equalsIgnoreCase(people[i].uid)) {
      return i;
    }
  }

  return -1;
}

void printAttendanceRecord(
  Person& person,
  String status
) {
  Serial.println();
  Serial.println("================================");
  Serial.println("ATTENDANCE RECORD");
  Serial.println("================================");

  Serial.print("Name: ");
  Serial.println(person.name);

  Serial.print("Status: ");
  Serial.println(status);

  Serial.print("Date: ");
  Serial.println(getCurrentDate());

  Serial.print("Time: ");
  Serial.println(person.lastScan);

  Serial.print("People currently inside: ");
  Serial.println(getInsideCount());

  Serial.println("================================");
}

void processAuthorizedPerson(int personIndex) {
  people[personIndex].checkedIn =
    !people[personIndex].checkedIn;

  people[personIndex].lastScan =
    getCurrentTime();

  String status;

  if (people[personIndex].checkedIn) {
    status = "CHECKED IN";
  } else {
    status = "CHECKED OUT";
  }

  printAttendanceRecord(
    people[personIndex],
    status
  );

  String displayStatus;

  if (people[personIndex].checkedIn) {
    displayStatus = "CHECK IN";
  } else {
    displayStatus = "CHECK OUT";
  }

  showMessage(
    people[personIndex].name,
    displayStatus,
    "Time: " + people[personIndex].lastScan,
    "Inside: " + String(getInsideCount())
  );

  delay(2500);
  showReadyScreen();
}

void processUnknownCard(String scannedUID) {
  Serial.println();
  Serial.println("UNKNOWN CARD");
  Serial.print("UID: ");
  Serial.println(scannedUID);
  Serial.println("Add this UID to the people[] list.");

  showMessage(
    "UNKNOWN CARD",
    "DENIED",
    scannedUID,
    "Not registered"
  );

  delay(2500);
  showReadyScreen();
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("Starting RFID Attendance System");

  // Start I2C for OLED and RTC.
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

  // Start OLED without stopping the entire program on failure.
  oledWorking = display.begin(
    SSD1306_SWITCHCAPVCC,
    OLED_ADDRESS
  );

  if (oledWorking) {
    Serial.println("OLED detected.");
  } else {
    Serial.println("OLED not detected.");
    Serial.println("RFID will continue without OLED.");
  }

  // Start RTC without stopping RFID on failure.
  rtcWorking = rtc.begin();

if (rtcWorking) {
  Serial.println("RTC detected.");

  // Use this line for ONE upload to correct the clock.
  // Then comment it out and upload again.
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

} else {
  Serial.println("RTC not detected.");
  Serial.println("RFID will continue without RTC.");
}

  // Start RC522 SPI communication.
  pinMode(RFID_SS_PIN, OUTPUT);
  digitalWrite(RFID_SS_PIN, HIGH);

  SPI.begin(
    RFID_SCK_PIN,
    RFID_MISO_PIN,
    RFID_MOSI_PIN,
    RFID_SS_PIN
  );

  rfid.PCD_Init();
  delay(100);

  // Increase antenna sensitivity.
  rfid.PCD_SetAntennaGain(
    MFRC522::RxGain_max
  );

  byte version =
    rfid.PCD_ReadRegister(rfid.VersionReg);

  Serial.print("RC522 firmware: 0x");
  Serial.println(version, HEX);

  if (version == 0x00 || version == 0xFF) {
    Serial.println("ERROR: RC522 not detected.");
    showMessage(
      "RFID ERROR",
      "RC522",
      "Check wiring"
    );
  } else {
    Serial.println("RC522 detected.");
    Serial.println("Attendance system ready.");
    showReadyScreen();
  }
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  if (!rfid.PICC_ReadCardSerial()) {
    Serial.println("Card detected, but UID read failed.");
    return;
  }

  String scannedUID = getScannedUID();

  // Prevent one scan from being counted repeatedly.
  if (
    scannedUID == lastUID &&
    millis() - lastScanTime < scanCooldown
  ) {
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
    return;
  }

  lastUID = scannedUID;
  lastScanTime = millis();

  Serial.println();
  Serial.print("Scanned UID: ");
  Serial.println(scannedUID);

  int personIndex = findPerson(scannedUID);

  if (personIndex >= 0) {
    processAuthorizedPerson(personIndex);
  } else {
    processUnknownCard(scannedUID);
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
