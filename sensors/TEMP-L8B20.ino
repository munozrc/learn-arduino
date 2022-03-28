#include <OneWire.h>
#include <DallasTemperature.h>

#define sensor 3
#define led 2

OneWire oneWire(sensor);
DallasTemperature sensors(&oneWire);

void setup()
{
  Serial.begin(9600);

  // Inicializar entrada del sensor
  sensors.begin();
  Serial.println("Letura de temperatura Sensor TEMP-18B20\n");

  // Inicializar pin numero 2 como salida
  pinMode(led, OUTPUT);
}

void loop()
{
  sensors.requestTemperatures();

  Serial.print("\nLa temperatura del medio es de: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print(" C°\n");

  if (sensors.getTempCByIndex(0) >= 45)
  {
    digitalWrite(led, HIGH);
    Serial.println(">>> Alta temperatura");
  }
  else
  {
    digitalWrite(led, LOW);
  }
}