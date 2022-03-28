#include <SimpleDHT.h>

#define SENSOR_PIN 2
#define LED_TEMPERATURA 3
#define LED_HUMEDAD 5

SimpleDHT11 SENSOR_DHT11;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_TEMPERATURA, OUTPUT);
  pinMode(LED_HUMEDAD, OUTPUT);
}

void loop()
{
  byte temperatura = 0;
  byte humedad = 0;

  if (SENSOR_DHT11.read(SENSOR_PIN, &temperatura, &humedad, NULL))
    return;

  // Validar valor de la TEMPERATURA
  if ((int)temperatura >= 25)
    digitalWrite(LED_TEMPERATURA, HIGH);
  else
    digitalWrite(LED_TEMPERATURA, LOW);

  // Validar valor de la HUMEDAD
  if ((int)humedad >= 35)
    digitalWrite(LED_TEMPERATURA, HIGH);
  else
    digitalWrite(LED_TEMPERATURA, LOW);

  // Imprimir valores
  Serial.println("\n ::::::::::::::::::::::::::::::");
  Serial.println("Temperatura: " + (int)temperatura);
  Serial.println("Humedad: " + (int)humedad);
  delay(200);
}