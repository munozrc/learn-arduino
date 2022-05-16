#define echoPin 2
#define trigerPin 3

void setup()
{
  Serial.begin(9600);

  pinMode(echoPin, INPUT);
  pinMode(trigerPin, OUTPUT);
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

  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}