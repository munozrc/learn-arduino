// Este es un arreglo de los pines a los cuales estan conectados los leds
int arregloDePines[] = {D0, D1, D2, D3, D4, D5};

// Esta variables nos permite saber el número total de elementos del arreglo
int tamaño = sizeof(arregloDePines) / sizeof(arregloDePines[0]);

void setup()
{
  // Configuramos todos los pines del arreglo como pines de salida
  for (int posicion = 0; posicion < tamaño; posicion++)
  {
    pinMode(arregloDePines[posicion], OUTPUT);
  }
}

void loop()
{
  // Ciclo para encender todos los leds con un delay de 500 milisegundos
  for (int posicion = 0; posicion < tamaño; posicion++)
  {
    // Encedemos el led enviando una seña de HIGH al pin actual
    digitalWrite(arregloDePines[posicion], HIGH);
    // Establecemos un tiempo de esperan antes que pase a la siguiente instrucción
    delay(500);
  }

  // Ciclo para apagar todos los leds en orden desendente con un delay de 500 milisegundos
  for (int posicion = tamaño; posicion > 0; posicion--)
  {
    // Apagamos el led enviado una señal de LOW al pin
    digitalWrite(arregloDePines[posicion - 1], LOW);
    // Establecemos un tiempo de esperan antes que pase a la siguiente instrucción
    delay(500);
  }
}