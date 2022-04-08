uint8_t LEDS_PIN[] = {D0, D1, D2, D3, D4, D5};
uint8_t size = sizeof(LEDS_PIN) / sizeof(LEDS_PIN[0]);

int SEQUENCE[2][6][3] = {
    {{HIGH, 0, 500}, {HIGH, 1, 500}, {HIGH, 2, 500}, {HIGH, 3, 500}, {HIGH, 4, 500}, {HIGH, 5, 500}},
    {{LOW, 5, 500}, {LOW, 4, 500}, {LOW, 3, 500}, {LOW, 2, 500}, {LOW, 1, 500}, {LOW, 0, 500}}};

int SEQUENCE_2[2][6][3] = {
    {{HIGH, 0, 0}, {LOW, 1, 0}, {HIGH, 2, 0}, {LOW, 3, 0}, {HIGH, 4, 0}, {LOW, 5, 500}},
    {{LOW, 0, 0}, {HIGH, 1, 0}, {LOW, 2, 0}, {HIGH, 3, 0}, {LOW, 4, 0}, {HIGH, 5, 500}}};

void setup()
{
  for (uint8_t i = 0; i < size; i++)
    pinMode(LEDS_PIN[i], OUTPUT);
}

void loop()
{
  for (uint8_t row = 0; row < 2; row++)
  {
    for (uint8_t column = 0; column < 6; column++)
    {
      uint8_t status = SEQUENCE_2[row][column][0];
      uint8_t ledPosition = SEQUENCE_2[row][column][1];
      int delayValue = SEQUENCE_2[row][column][2];

      digitalWrite(LEDS_PIN[ledPosition], status);
      delay(delayValue);
    }
  }
}