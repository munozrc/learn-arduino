#include "LedControl.h"

#define PinJoystickX A0
#define PinJoystickY A1

#define PinDIN 11
#define PinCS 10
#define PinCLK 9

int xMap, yMap, xValue, yValue;
LedControl matriz = LedControl(PinDIN, PinCLK, PinCS, 1);

void setup()
{
  Serial.begin(9600);

  // Configuracion para la matriz de LEDs
  matriz.shutdown(0, false);
  matriz.setIntensity(0, 8);
  matriz.clearDisplay(0);
}

void loop()
{
  xValue = analogRead(PinJoystickX);
  yValue = analogRead(PinJoystickY);
  xMap = map(xValue, 0, 1023, 0, 7);
  yMap = map(yValue, 0, 1023, 7, 0);

  Serial.print("x = ");
  Serial.print(xMap);

  Serial.print(" y = ");
  Serial.println(yMap);

  matriz.setLed(0, xMap, yMap, true);
  matriz.clearDisplay(0);
}