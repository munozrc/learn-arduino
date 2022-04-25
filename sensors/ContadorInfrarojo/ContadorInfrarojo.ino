int contador = 0;
int sensor = 2;
int indicador = 13;
int ledContadorUno = 3;
int ledContadorDos = 4;
int ledContadorTres = 5;

int lectura = LOW;
int lecturaAnterior = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(indicador, OUTPUT);
  pinMode(ledContadorUno, OUTPUT);
  pinMode(ledContadorDos, OUTPUT);
  pinMode(ledContadorTres, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop()
{
  lectura = !digitalRead(sensor);
  digitalWrite(indicador, lectura);

  if (lectura == HIGH && lecturaAnterior == LOW)
  {
    contador++;
    lecturaAnterior = HIGH;
    if (contador >= 20)
    {
      contador = 0;
    }
  }

  if (lectura == LOW && lecturaAnterior == HIGH)
  {
    lecturaAnterior = LOW;
  }

  if (contador >= 10)
  {
    digitalWrite(ledContadorUno, HIGH);
  }
  else if (contador >= 15)
  {
    digitalWrite(ledContadorDos, HIGH);
  }
  else if (contador >= 20)
  {
    digitalWrite(ledContadorTres, HIGH);
  }
  else if (contador < 10)
  {
    digitalWrite(ledContadorUno, LOW);
    digitalWrite(ledContadorDos, LOW);
    digitalWrite(ledContadorTres, LOW);
  }

  Serial.print("botellas = ");
  Serial.println(contador);
}