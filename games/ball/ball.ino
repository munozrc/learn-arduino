#include "LedControl.h"

struct Pin
{
  static const short JoystickX = A0;
  static const short DIN = D5;
  static const short CS = D6;
  static const short CLK = D7;
};

struct Coordinate
{
  int x = 0, y = 0;
  Coordinate(int x = 0, int y = 0) : x(x), y(y) {}
};

LedControl ledControl(Pin::DIN, Pin::CLK, Pin::CS, 0);

Coordinate joystickOrigin(500, 500);
Coordinate playerPosition(3, 3);

unsigned int speed = 100;
unsigned long timestamp = 0;

bool board[8][8] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}};

void setup()
{
  ledControl.shutdown(0, false);
  ledControl.setIntensity(0, 8);
  ledControl.clearDisplay(0);
}

void loop()
{

  int directionX = getAxisValue(Pin::JoystickX, joystickOrigin.x, 160);

  if (millis() > timestamp + speed)
  {
    timestamp = millis();

    int posX = playerPosition.x + directionX;

    if (posX <= 7 && posX >= 0 && board[posX][playerPosition.y] == false)
    {
      ledControl.setLed(0, playerPosition.x, playerPosition.y, false);
      playerPosition.x += directionX;
      ledControl.setLed(0, playerPosition.x, playerPosition.y, true);
    }
  }

  for (int row = 0; row < 8; row++)
  {
    for (int column = 0; column < 8; column++)
    {
      if (board[row][column] == true)
      {
        ledControl.setLed(0, row, column, true);
      }
    }
  }
}

int getAxisValue(uint8_t pin, int originAxis, int axisThreshold)
{
  int value = 0;
  int raw = analogRead(pin);

  raw < originAxis - axisThreshold ? value = 1 : 0;
  raw > originAxis + axisThreshold ? value = -1 : 0;

  return value;
}