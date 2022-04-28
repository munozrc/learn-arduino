struct Pin
{
  static const short joystrickX = A0;
};

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int value = analogRead(Pin::joystrickX);

  Serial.print("value = ");
  Serial.println(value);
}