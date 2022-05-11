#include <FastLED.h>

#define NUMERO_DE_FILAS 10
#define NUMERO_DE_COLUMNAS 10
#define DATA_PIN D6

CRGB LEDs[NUMERO_DE_FILAS * NUMERO_DE_COLUMNAS];

void setup()
{
  Serial.begin(115200);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(LEDs, NUMERO_DE_FILAS * NUMERO_DE_COLUMNAS);
  FastLED.setBrightness(30);
}

void loop()
{
  for (int i = 0; i < NUMERO_DE_FILAS; i++)
  {
    for (int j = 0; j < NUMERO_DE_COLUMNAS; j++)
    {
      int ledPosition = getLedPosition(i, j);

      Serial.println("pos = " + String(ledPosition, DEC) + " x = " + String(i, DEC) + " y = " + String(j, DEC));

      LEDs[ledPosition] = CRGB::Red;
      FastLED.show();
      delay(10);

      LEDs[ledPosition] = CRGB::Black;
      delay(10);
    }
  }

  delay(500);
}

int getLedPosition(int x, int y)
{
  if (x & 1)
  {
    return x * NUMERO_DE_COLUMNAS + (NUMERO_DE_COLUMNAS - y - 1);
  }
  else
  {
    return x * NUMERO_DE_COLUMNAS + y;
  }
}