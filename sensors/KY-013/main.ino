#define PIN_SENSOR_KY_013 A0
#define PIN_SENSOR_KY_028 A1

float R1 = 10000;                                            // Valor de R1 de la PCB 10k
float logR2, R2, TK, TC;                                     // Elementos para realizar la ecuación
float A = 0.001129148, B = 0.000234125, C = 0.0000000876741; // Valores constantes considerando NTC de 10K y trabajando a una temperatura entre -55°C a +125°C

void setup()
{
  // Configurar conexion del puerto serial
  Serial.begin(9600);

  // Configurar pines de entrada de datos
  pinMode(PIN_SENSOR_KY_013, INPUT);
}

void loop()
{
  int valor = analogRead(PIN_SENSOR_KY_013); // Se asigna los valores leídos a la variable valor
  Serial.print("Valor Analógico:");          // Se imprimirá los valores del sensor
  Serial.println(valor);                     // que va de 0-1023, esto para saber que que valores esta teniendo en reposo en termistor

  // para evitar la exponencial, usaremos la función map
  // valor = map(valor, 0, 270, 0, 50); // en donde 0-270, serán los valores de entrada analógico vs 0-50 el valor de temperatura
  float temperatura = Thermister(valor);
  Serial.print("Temperatura es:");
  Serial.println(temperatura); // Impresión de temperatura en Celsius
  delay(500);
}

double Thermister(int RawADC)
{
  double r = 10000.0; // en teoria tienen 10k ambos sensores (KY-013 Y KY-028)
  double a = 2.108508173e-3, b = 0.7979204727e-4, c = 6.535076315e-7;
  // Steinhart-Hart model
  double Temp;
  Temp = log(r / (1023.0 / RawADC - 1.0));
  Temp = 1.0 / (a + b * Temp + c * Temp * Temp * Temp);
  Temp = Temp - 273.15; // Conversion de Kelvin a Celcius https://www.metric-conversions.org/es/temperatura/kelvin-a-celsius.htm
  return Temp;
}