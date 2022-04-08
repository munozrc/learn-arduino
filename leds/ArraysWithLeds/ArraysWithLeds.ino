
uint8_t LEDS_PIN[6] = {D0, D1, D2, D3, D4, D5};
uint8_t size = sizeof(LEDS_PIN) / sizeof(LEDS_PIN[0]);

void setup()
{
  for (uint8_t i = 0; i < size; i++)
    pinMode(LEDS_PIN[i], OUTPUT);
}

void loop()
{
  for (uint8_t i = 0; i < size; i++)
  {
    digitalWrite(LEDS_PIN[i], HIGH);
    delay(500);
  }

  for (uint8_t i = size; i > 0; i--)
  {
    digitalWrite(LEDS_PIN[i - 1], LOW);
    delay(500);
  }
}