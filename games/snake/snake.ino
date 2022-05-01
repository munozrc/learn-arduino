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
  int x = getAxisValue(Pin::JoystickX, 500, 160);
  int y = getAxisValue(Pin::JoystickY, 500, 160);

  Serial.println("x = " + String(x, DEC) + " y = " + String(y, DEC));
}

int getAxisValue(uint8_t pin, int joystickHome, int joystickThreshold)
{
  int value = 0;
  int raw = analogRead(pin);

  raw < joystickHome - joystickThreshold ? value = 1 : 0;
  raw > joystickHome + joystickThreshold ? value = -1 : 0;

  return value;
}