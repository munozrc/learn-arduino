#include "LedControl.h"

#define PinJoystickX A0
#define PinJoystickY A1
#define PinDIN 11
#define PinCS 10
#define PinCLK 9
#define PinVcc 12

int xMap, yMap, xValue, yValue;
LedControl matrix = LedControl(PinDIN, PinCLK, PinCS, 1);

void setup()
{
  Serial.begin(9600);

  pinMode(PinVcc, OUTPUT);
  digitalWrite(PinVcc, HIGH);

  matrix.shutdown(0, false);
  /* Set the brightness to a medium values */
  matrix.setIntensity(0, 8);
  /* and clear the display */
  matrix.clearDisplay(0);
}

void loop()
{
  // put your main code here, to run repeatedly:
  xValue = analogRead(PinJoystickX);
  yValue = analogRead(PinJoystickY);
  xMap = map(xValue, 0, 1023, 0, 7);
  yMap = map(yValue, 0, 1023, 7, 0);

  Serial.print("x = ");
  Serial.print(xMap);

  Serial.print(" y = ");
  Serial.println(yMap);

  matrix.setLed(0, xMap, yMap, true);
  matrix.clearDisplay(0);
}