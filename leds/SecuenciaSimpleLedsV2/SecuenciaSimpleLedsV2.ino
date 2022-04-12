int secuenciaBasica[2][6][3] = {
    {{HIGH, 0, 500}, {HIGH, 1, 500}, {HIGH, 2, 500}, {HIGH, 3, 500}, {HIGH, 4, 500}, {HIGH, 5, 500}},
    {{LOW, 5, 500}, {LOW, 4, 500}, {LOW, 3, 500}, {LOW, 2, 500}, {LOW, 1, 500}, {LOW, 0, 500}}};

int secuenciaIntercalada[2][6][3] = {
    {{HIGH, 0, 0}, {LOW, 1, 0}, {HIGH, 2, 0}, {LOW, 3, 0}, {HIGH, 4, 0}, {LOW, 5, 500}},
    {{LOW, 0, 0}, {HIGH, 1, 0}, {LOW, 2, 0}, {HIGH, 3, 0}, {LOW, 4, 0}, {HIGH, 5, 500}}};

int secuenciaUnicoLed[7][6][3] = {
    {{HIGH, 0, 200}, {LOW, 1, 0}, {LOW, 2, 0}, {LOW, 3, 0}, {LOW, 4, 0}, {LOW, 5, 0}},
    {{LOW, 0, 0}, {HIGH, 1, 200}, {LOW, 2, 0}, {LOW, 3, 0}, {LOW, 4, 0}, {LOW, 5, 0}},
    {{LOW, 0, 0}, {LOW, 1, 0}, {HIGH, 2, 200}, {LOW, 3, 0}, {LOW, 4, 0}, {LOW, 5, 0}},
    {{LOW, 0, 0}, {LOW, 1, 0}, {LOW, 2, 0}, {HIGH, 3, 200}, {LOW, 4, 0}, {LOW, 5, 0}},
    {{LOW, 0, 0}, {LOW, 1, 0}, {LOW, 2, 0}, {LOW, 3, 0}, {HIGH, 4, 200}, {LOW, 5, 0}},
    {{LOW, 0, 0}, {LOW, 1, 0}, {LOW, 2, 0}, {LOW, 3, 0}, {LOW, 4, 0}, {HIGH, 5, 200}},
    {{LOW, 0, 0}, {LOW, 1, 0}, {LOW, 2, 0}, {LOW, 3, 0}, {LOW, 4, 0}, {LOW, 5, 0}}};

int arregloDePines[] = {D0, D1, D2, D3, D4, D5};
int tamaño = sizeof(arregloDePines) / sizeof(arregloDePines[0]);
int totalFilas = sizeof(secuenciaUnicoLed) / sizeof(secuenciaUnicoLed[0]);
int totalColumnas = sizeof(secuenciaUnicoLed[0]) / sizeof(secuenciaUnicoLed[0][0]);

void setup()
{
  for (int posicion = 0; posicion < tamaño; posicion++)
  {
    pinMode(arregloDePines[posicion], OUTPUT);
    digitalWrite(arregloDePines[posicion], LOW);
  }
}

void loop()
{
  for (int posFila = 0; posFila < totalFilas; posFila++)
  {
    for (int posColumna = 0; posColumna < totalColumnas; posColumna++)
    {
      // Estado puede ser "encendio" = HIGH ó "apagado" = LOW
      int estado = secuenciaUnicoLed[posFila][posColumna][0];
      int posicionLed = secuenciaUnicoLed[posFila][posColumna][1];
      int tiempoEntreCambio = secuenciaUnicoLed[posFila][posColumna][2];

      digitalWrite(arregloDePines[posicionLed], estado);
      delay(tiempoEntreCambio);
    }
  }
}