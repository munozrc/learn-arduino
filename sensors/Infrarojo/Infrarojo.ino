int led = 13;
int sensor = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop()
{
  int estado = digitalRead(sensor);
  digitalWrite(led, estado == HIGH ? HIGH : LOW);
  Serial.print("lectura = ");
  Serial.print(estado == HIGH ? "ALTO" : "BAJO");
  Serial.println();
  delay(20);
}
