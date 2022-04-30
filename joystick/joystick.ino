#define PinJoystickX A0
#define PinJoystickY A1

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int x = analogRead(PinJoystickX);
  int y = analogRead(PinJoystickY);

  Serial.print("x = ");
  Serial.print(x);

  Serial.print(" y = ");
  Serial.println(y);
}