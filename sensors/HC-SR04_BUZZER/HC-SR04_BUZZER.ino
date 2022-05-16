#define echoPin 3
#define trigerPin 4
#define buzzerPin 7
#define ledVerdePin 6
#define ledRojoPin 5
#define ledAzulPin 2

void setup()
{
  Serial.begin(9600);

  pinMode(echoPin, INPUT);
  pinMode(trigerPin, OUTPUT);

  pinMode(ledVerdePin, OUTPUT);
  pinMode(ledRojoPin, OUTPUT);
  pinMode(ledAzulPin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);
}

long duration;
int distance;

void loop()
{
  // Clears the trigPin condition
  digitalWrite(trigerPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  // Validations
  if (distance < 10)
  {
    digitalWrite(ledRojoPin, HIGH);
    digitalWrite(ledVerdePin, LOW);
    digitalWrite(ledAzulPin, LOW);
    noTone(buzzerPin);
  }

  if (distance > 30)
  {
    digitalWrite(ledAzulPin, HIGH);
    digitalWrite(ledRojoPin, LOW);
    digitalWrite(ledVerdePin, LOW);
    noTone(buzzerPin);
  }

  if (distance == 10)
  {
    digitalWrite(ledVerdePin, HIGH);
    digitalWrite(ledRojoPin, LOW);
    digitalWrite(ledAzulPin, LOW);
    tone(buzzerPin, 200);
  }

  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}