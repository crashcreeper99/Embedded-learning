#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int startButton = 19;
const int resetButton = 18;

bool running = false;

unsigned long startTime = 0;
unsigned long elapsedTime = 0;

bool lastStartState = HIGH;
bool lastResetState = HIGH;

void setup() {

  pinMode(startButton, INPUT_PULLUP);
  pinMode(resetButton, INPUT_PULLUP);

  Wire.begin(21,22);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    while(true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  bool startState = digitalRead(startButton);
  bool resetState = digitalRead(resetButton);

  if(lastStartState == HIGH && startState == LOW){

    if(running){
      elapsedTime += millis() - startTime;
      running = false;
    }
    else{
      startTime = millis();
      running = true;
    }

    delay(200);
  }

  if(lastResetState == HIGH && resetState == LOW){

    running = false;
    elapsedTime = 0;

    delay(200);
  }

  lastStartState = startState;
  lastResetState = resetState;

  unsigned long currentTime = elapsedTime;

  if(running){
    currentTime += millis() - startTime;
  }

  unsigned long ms = currentTime % 1000;
  unsigned long sec = (currentTime / 1000) % 60;
  unsigned long min = currentTime / 60000;

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(10,10);

  if(min < 10) display.print("0");
  display.print(min);
  display.print(":");

  if(sec < 10) display.print("0");
  display.print(sec);
  display.print(":");

  if(ms < 100) display.print("0");
  if(ms < 10) display.print("0");
  display.print(ms);

  display.setTextSize(1);
  display.setCursor(18,50);

  if(running)
    display.print("Running");
  else
    display.print("Paused");

  display.display();

}
