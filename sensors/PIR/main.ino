#define sensor 2
#define led 13

int sensorValue = LOW;
boolean sensorStatus = false;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop()
{
  sensorValue = digitalRead(sensor);
  digitalWrite(led, sensorValue == HIGH ? HIGH : LOW);
  Serial.println(sensorValue);
}