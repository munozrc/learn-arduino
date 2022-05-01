#include "LedControl.h"

struct Pin
{
  static const short JoystickX = A0;
  static const short JoystickY = A1;

  static const short DIN = 11;
  static const short CS = 10;
  static const short CLK = 9;
};

LedControl matrix(Pin::DIN, Pin::CLK, Pin::CS, 1);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Hi!");
}