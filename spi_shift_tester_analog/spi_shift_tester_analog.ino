#include <SPI.h>

const byte LATCH = 10;

byte data[] = {
  0b00000000,
  0b00000000
};

unsigned int myDelay = 50;

void setup()
{
  SPI.begin();
  pinMode(LATCH, OUTPUT);
}

void loop()
{
  int j;
  int chip;
  myDelay = map(analogRead(A0), 0, 1023, 0, 50);
  // left to right
  for (int i = 0; i < 16; i++)
  {
    if (i < 8)
    {
      chip = 1;
      j = i;
    }
    else
    {
      chip = 0;
      j = i - 8;
    }
    toggle(chip, j);
    delay(myDelay);
  }
  for (int i = 0; i < 16; i++)
  {
    if (i < 8)
    {
      chip = 1;
      j = i;
    }
    else
    {
      chip = 0;
      j = i - 8;
    }
    toggle(chip, j);
    delay(myDelay);
  }

  // right to left
  for (int i = 15; i > -1; i--)
  {
    if (i < 8)
    {
      chip = 1;
      j = i;
    }
    else
    {
      chip = 0;
      j = i - 8;
    }
    toggle(chip, j);
    delay(myDelay);
  }
  for (int i = 15; i > -1; i--)
  {
    if (i < 8)
    {
      chip = 1;
      j = i;
    }
    else
    {
      chip = 0;
      j = i - 8;
    }
    toggle(chip, j);
    delay(myDelay);
  }
}

void toggle(int chip, int pin)
{
  bitWrite(data[chip], pin, !bitRead(data[chip], pin));
  digitalWrite(LATCH, LOW);
  SPI.transfer(data[0]);
  SPI.transfer(data[1]);
  digitalWrite(LATCH, HIGH);
}
