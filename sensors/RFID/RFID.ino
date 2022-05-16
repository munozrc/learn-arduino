#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN 9 // Pin 9 para el reset del RC522
#define SS_PIN 10 // Pin 10 para el SS (SDA) del RC522
#define ledAzulPin 2
#define ledRojoPin 3
#define servoPin 6

MFRC522 mfrc522(SS_PIN, RST_PIN); /// Creamos el objeto para el RC522
Servo servo;

void setup()
{
  Serial.begin(9600); // Iniciamos La comunicacion serial
  SPI.begin();        // Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos el MFRC522
  Serial.println("Control de acceso:");

  servo.attach(servoPin); // activamos el servo en el pin 5
  servo.write(90);        // activamos el giro del servo para 90 grados

  pinMode(ledAzulPin, OUTPUT);
  pinMode(ledRojoPin, OUTPUT);
}

byte ActualUID[4];                             // almacenará el código del Tag leído
byte UsuarioUno[4] = {0x9D, 0xDC, 0xE7, 0x2B}; // código del usuario 1

void loop()
{
  // Revisamos si hay nuevas tarjetas  presentes
  if (mfrc522.PICC_IsNewCardPresent())
  {
    // Seleccionamos una tarjeta
    if (mfrc522.PICC_ReadCardSerial())
    {
      // Enviamos serialemente su UID
      Serial.print(F("Card UID:"));
      for (byte i = 0; i < mfrc522.uid.size; i++)
      {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        ActualUID[i] = mfrc522.uid.uidByte[i];
      }
      Serial.print("     ");
      // comparamos los UID para determinar si es uno de nuestros usuarios
      if (compareArray(ActualUID, UsuarioUno))
      {
        Serial.println("Acceso concedido...");
        hi();
      }
      else
        Serial.println("Acceso denegado...");

      // Terminamos la lectura de la tarjeta tarjeta  actual
      mfrc522.PICC_HaltA();
    }
  }
}

// Función para comparar dos vectores
boolean compareArray(byte array1[], byte array2[])
{
  if (array1[0] != array2[0])
    return (false);
  if (array1[1] != array2[1])
    return (false);
  if (array1[2] != array2[2])
    return (false);
  if (array1[3] != array2[3])
    return (false);
  return (true);
}

void hi()
{
  servo.write(0);                 // el angulo del servo se corre a 0 grados
  digitalWrite(ledAzulPin, HIGH); // prende el led verde de abierto
  digitalWrite(ledRojoPin, LOW);  // apaga el led tojo de cerrado
  delay(2000);                    // lo hace por 2 sg
  servo.write(90);                // luego se devulve 90 grados el servo
  digitalWrite(ledAzulPin, LOW);  // apaga el led verde de abierto
  digitalWrite(ledRojoPin, HIGH); // prende el led rojo de cerrado
  delay(1000);                    // hace las iteraciones en 1 sg
}