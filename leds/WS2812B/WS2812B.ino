#include <FastLED.h>

#define NUM_LEDS 60
#define DATA_PIN D6

CRGB LEDs[NUM_LEDS];

void setup()
{
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(LEDs, NUM_LEDS);
  FastLED.setBrightness(30);
}

void loop()
{
  for (int pos = 0; pos < NUM_LEDS; pos++)
  {
    LEDs[pos] = CRGB::Red;
    FastLED.show();
    delay(10);

    LEDs[pos] = CRGB::Black;
    delay(10);
  }

  delay(500);

  for (int pos = 0; pos < NUM_LEDS; pos++)
  {
    LEDs[pos] = CRGB::Green;
    FastLED.show();
    delay(10);

    LEDs[pos] = CRGB::Black;
    delay(10);
  }

  delay(500);

  for (int pos = 0; pos < NUM_LEDS; pos++)
  {
    LEDs[pos] = CRGB::Blue;
    FastLED.show();
    delay(10);

    LEDs[pos] = CRGB::Black;
    delay(10);
  }

  delay(500);

  for (int pos = 0; pos < NUM_LEDS; pos++)
  {
    LEDs[pos] = CRGB::White;
    FastLED.show();
    delay(10);

    LEDs[pos] = CRGB::Black;
    delay(10);
  }

  delay(500);
}