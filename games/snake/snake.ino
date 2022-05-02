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

LedControl ledControl(Pin::DIN, Pin::CLK, Pin::CS, 0);
Coordinate joystickOrigin(500, 500);
Coordinate playerPosition(0, 0);

unsigned int speed = 100;
unsigned long timestamp = 0;

void setup()
{
  Serial.begin(9600);

  joystickOrigin = calibrateAxis(Pin::JoystickX, Pin::JoystickY);
  Serial.println("Nueva calibracion --> x = " + String(joystickOrigin.x, DEC) + " y = " + String(joystickOrigin.y, DEC));

  ledControl.shutdown(0, false);
  ledControl.setIntensity(0, 8);
  ledControl.clearDisplay(0);
}

void loop()
{
  ledControl.clearDisplay(0);

  int directionX = getAxisValue(Pin::JoystickX, joystickOrigin.x, 160);
  int directionY = getAxisValue(Pin::JoystickY, joystickOrigin.y, 160);

  Serial.println("x = " + String(directionX, DEC) + " y = " + String(directionY, DEC));

  if (millis() > timestamp + speed)
  {
    timestamp = millis();

    int posX = playerPosition.x + directionX;
    int posY = playerPosition.y + directionY;

    if (posX <= 7 && posX >= 0)
    {
      playerPosition.x += directionX;
    }

    if (posY <= 7 && posY >= 0)
    {
      playerPosition.y += directionY;
    }
  }

  ledControl.setLed(0, playerPosition.x, playerPosition.y, 1);
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