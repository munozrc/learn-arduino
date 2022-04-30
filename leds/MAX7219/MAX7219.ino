#include <LedControl.h>

#define DIN D5
#define CS D6
#define CLK D7

LedControl matrix = LedControl(DIN, CLK, CS, 0);

byte Cat[8] = {B10001000, B11111000, B10101000, B01110001, B00100001, B01111001, B01111101, B10111110};
byte Apple[8] = {B00011000, B00001000, B01110110, B11111111, B11111111, B11111111, B01111010, B00110100};

void setup()
{
  matrix.shutdown(0, false);
  matrix.setIntensity(0, 0);
  matrix.clearDisplay(0);
}

void loop()
{
  for (int i = 0; i < 8; i++)
  {
    matrix.setRow(0, i, Apple[i]);
  }

  delay(5000);
  matrix.clearDisplay(0);

  for (int i = 0; i < 8; i++)
  {
    matrix.setRow(0, i, Cat[i]);
  }

  delay(5000);
  matrix.clearDisplay(0);
}