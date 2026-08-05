const int leds[4] = {23, 22, 21, 19};
const int buttons[4] = {13, 14, 27, 26};

const int buzzer = 4;

const int tones[4] = {262, 330, 392, 523};

int sequence[50];
int level = 1;

void beep(int freq, int time)
{
  tone(buzzer, freq, time);
}

void flash(int i)
{
  digitalWrite(leds[i], HIGH);
  beep(tones[i], 300);
  delay(300);
  digitalWrite(leds[i], LOW);
  delay(150);
}

void setup()
{
  Serial.begin(115200);

  for(int i=0;i<4;i++)
  {
    pinMode(leds[i], OUTPUT);
    pinMode(buttons[i], INPUT_PULLUP);
  }

  pinMode(buzzer, OUTPUT);

  randomSeed(micros());

  for(int i=0;i<50;i++)
    sequence[i]=random(0,4);
}

void loop()
{
  Serial.print("Level ");
  Serial.println(level);

  // Show pattern
  for(int i=0;i<level;i++)
  {
    flash(sequence[i]);
  }

  // Read player input
  for(int i=0;i<level;i++)
  {
    bool pressed=false;

    while(!pressed)
    {
      for(int b=0;b<4;b++)
      {
        if(digitalRead(buttons[b])==LOW)
        {
          flash(b);

          while(digitalRead(buttons[b])==LOW);

          if(b!=sequence[i])
          {
            gameOver();
            return;
          }

          pressed=true;
        }
      }
    }
  }

  level++;

  if(level>50)
  {
    winGame();
    return;
  }

  delay(700);
}

void gameOver()
{
  Serial.println("Game Over");

  for(int i=0;i<3;i++)
  {
    for(int j=0;j<4;j++)
      digitalWrite(leds[j],HIGH);

    beep(150,300);

    delay(300);

    for(int j=0;j<4;j++)
      digitalWrite(leds[j],LOW);

    delay(300);
  }

  level=1;
}

void winGame()
{
  while(true)
  {
    for(int i=0;i<4;i++)
    {
      flash(i);
    }
  }
}
