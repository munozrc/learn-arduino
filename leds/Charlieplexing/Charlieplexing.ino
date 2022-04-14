#define PIN_A D5
#define PIN_B D6
#define PIN_C D0

void setup()
{
}

void loop()
{
  // Bucle para encender los LEDs de menor a mayor
  for (int i = 1; i <= 6; i++)
  {
    encenderLed(i);
    delay(100);
  }

  // Bucle para encender los LEDs de mayor a menor eliminando lo extremos
  for (int i = 5; i > 1; i--)
  {
    encenderLed(i);
    delay(100);
  }
}

// Función que pondrá en los estados correctos para encender un LED (HIGH, LOW e INPUT)
void ponerEstados(int pinHigh, int pinLow, int pinInput)
{
  pinMode(pinHigh, OUTPUT);
  digitalWrite(pinHigh, HIGH);
  pinMode(pinLow, OUTPUT);
  digitalWrite(pinLow, LOW);
  pinMode(pinInput, INPUT);
}

// Esta función se va a encargar de aplicar la lógica dependiendo del LED que queramos encender
void encenderLed(int led_num)
{
  switch (led_num)
  {
  case 1:
    ponerEstados(PIN_B, PIN_A, PIN_C);
    break;
  case 2:
    ponerEstados(PIN_A, PIN_B, PIN_C);
    break;
  case 3:
    ponerEstados(PIN_C, PIN_B, PIN_A);
    break;
  case 4:
    ponerEstados(PIN_B, PIN_C, PIN_A);
    break;
  case 5:
    ponerEstados(PIN_C, PIN_A, PIN_B);
    break;
  case 6:
    ponerEstados(PIN_A, PIN_C, PIN_B);
    break;
  }
}