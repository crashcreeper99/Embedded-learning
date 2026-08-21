# PIR Intruder Alarm

## Overview
This ESP32 project uses a PIR motion sensor to detect movement and activate an audible buzzer and LED alarm. It focuses on event-driven sensing and alarm-state logic rather than simply displaying sensor readings.

## Components
- ESP32 DevKit V1
- HC-SR501 PIR motion sensor
- Active buzzer
- LED
- 220 ohm resistor
- Breadboard and jumper wires

## Wiring
### PIR sensor
| PIR | ESP32 |
|---|---|
| VCC | 5V |
| OUT | GPIO 27 |
| GND | GND |

### Buzzer
| Buzzer | ESP32 |
|---|---|
| + | GPIO 25 |
| - | GND |

### LED
| LED | ESP32 |
|---|---|
| Anode (+) through 220 ohm resistor | GPIO 26 |
| Cathode (-) | GND |

## How It Works
The ESP32 continuously monitors the PIR sensor. When motion is detected, the controller turns on the LED and buzzer. When no motion is detected, both outputs remain off.

## Example Code
```cpp
#define PIR_PIN 27
#define BUZZER_PIN 25
#define LED_PIN 26

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  Serial.println("PIR Intruder Alarm ready");
}

void loop() {
  bool motion = digitalRead(PIR_PIN);

  if (motion) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("ALERT: Motion detected!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}
```

## Testing
1. Power the ESP32 and allow the PIR sensor a short warm-up period.
2. Stay still and verify that the alarm is off.
3. Move a hand or walk in front of the sensor.
4. Confirm that the LED and buzzer activate.
5. Verify the motion message in Serial Monitor.

## What I Learned
- Reading a digital motion sensor
- Using sensor input to control multiple outputs
- Implementing basic alarm-state logic
- Combining sensing, indication, and sound in one embedded system

## Future Improvements
- Add an arm/disarm push button
- Add an OLED status screen
- Add a delay before triggering the alarm
- Send a Wi-Fi notification when movement is detected
