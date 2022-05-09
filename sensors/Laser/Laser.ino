#define PinFotoResistencia A0
#define PinLaser 4
#define PinLedContadorUno 7
#define PinLedContadorDos 6
#define PinLedContadorTres 5
#define PinLedIndicador 13

int LDR = 200;
int lectura = 0;
int lecturaAnterior = 0;
int contador = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Inicializando...");

  pinMode(PinLedContadorUno, OUTPUT);
  pinMode(PinLedContadorDos, OUTPUT);
  pinMode(PinLedContadorTres, OUTPUT);

  pinMode(PinLaser, OUTPUT);
  digitalWrite(PinLaser, HIGH);

  Serial.println("Inicializacion completada");
}

void loop()
{
  lectura = digitalRead(PinFotoResistencia);
  Serial.println("valor = " + String(lectura, DEC));
  // digitalWrite(PinLedIndicador, lectura);

  if (lectura > LDR && lecturaAnterior < LDR)
  {
    contador++;
    lecturaAnterior = 0;
    if (contador >= 20)
    {
      contador = 0;
    }
  }

  if (lectura < LDR && lecturaAnterior > LDR)
  {
    lecturaAnterior = lectura;
  }

  if (contador >= 10)
  {
    digitalWrite(PinLedContadorUno, HIGH);
  }
  else if (contador >= 15)
  {
    digitalWrite(PinLedContadorDos, HIGH);
  }
  else if (contador >= 20)
  {
    digitalWrite(PinLedContadorTres, HIGH);
  }
  else if (contador < 10)
  {
    digitalWrite(PinLedContadorUno, LOW);
    digitalWrite(PinLedContadorDos, LOW);
    digitalWrite(PinLedContadorTres, LOW);
  }

  Serial.print("pasajeros = ");
  Serial.println(contador);
}