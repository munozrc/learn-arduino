#include "LedControl.h"

struct Pin
{
  static const short JoystickX = A0;
  static const short JoystickY = A1;
  static const short DIN = 11;
  static const short CS = 10;
  static const short CLK = 9;
};

struct Coordinate
{
  int x = 0, y = 0;
  Coordinate(int x = 0, int y = 0) : x(x), y(y) {}
};

Coordinate joystickOrigin(500, 500);
LedControl matrix(Pin::DIN, Pin::CLK, Pin::CS, 1);

void setup()
{
  Serial.begin(9600);
  joystickOrigin = calibrateAxis(Pin::JoystickX, Pin::JoystickY);
  Serial.println("Nueva calibracion --> x = " + String(joystickOrigin.x, DEC) + " y = " + String(joystickOrigin.y, DEC));
}

void loop()
{
  int x = getAxisValue(Pin::JoystickX, joystickOrigin.x, 160);
  int y = getAxisValue(Pin::JoystickY, joystickOrigin.y, 160);

  Serial.println("x = " + String(x, DEC) + " y = " + String(y, DEC));
}

int getAxisValue(uint8_t pin, int originAxis, int axisThreshold)
{
  int value = 0;
  int raw = analogRead(pin);

  raw < originAxis - axisThreshold ? value = 1 : 0;
  raw > originAxis + axisThreshold ? value = -1 : 0;

  return value;
}

Coordinate calibrateAxis(uint8_t pinAxisX, uint8_t pinAxisY)
{
  Coordinate values;

  for (int i = 0; i < 10; i++)
  {
    values.x += analogRead(pinAxisX);
    values.y += analogRead(pinAxisY);
  }

  values.x = values.x / 10;
  values.y = values.y / 10;

  return values;
}