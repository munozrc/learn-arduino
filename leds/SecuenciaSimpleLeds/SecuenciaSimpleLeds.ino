// Establemos las variables del archivo
// Este es un arreglo de los pines a los cuales estan conectados los leds
uint8_t arregloDePines[] = {D0, D1, D2, D3, D4, D5};

// Esta variables nos permite saber el tamaño del anterios arreglo de pines
uint8_t tamaño = sizeof(arregloDePines) / sizeof(arregloDePines[0]);

void setup()
{
  // Configuramos todos los pines del arreglo como pines de salida
  for (uint8_t posicion = 0; posicion < tamaño; posicion++)
  {
    pinMode(arregloDePines[posicion], OUTPUT);
  }
}

void loop()
{
  /*
    Para crear el efecto de encendido de los leds unos tras otros
    debemos usar el ciclo for el cual recorre de forma acedente todos los pines
    del arreglo. Despues de cada ciclo aumentamos el valor
    de posicion.
  */
  for (uint8_t posicion = 0; posicion < tamaño; posicion++)
  {
    // Encedemos el led enviando una seña de HIGH al pin actual
    digitalWrite(arregloDePines[posicion], HIGH);
    // Establecemos un tiempo de esperan antes que pase a la siguiente instrucción
    delay(500);

    /*
      El ciclo finalizar cuando haya encendidos todos los leds, esto
      se dermina cuando el valor de posicion se a igual al tamaño del arreglo.
    */
  }

  /*
    Despues del enceder todos los leds debemos apagarlos de forma desendente, para lograrlo
    debemos recorrer el arreglo de pines de atras hacia a adelante, lo haremos definiendo como valor
    inicial de posicion el tamaño del arreglo, que sera de 6. para determinar cuando debe terminar
    el ciclo comparamos el valor de posicion es mayor a cero, despues de cada ciclo decrementamos el valor
    de posicion.
  */
  for (uint8_t posicion = tamaño; posicion > 0; posicion--)
  {
    // Apagamos el led enviado una señal de LOW al pin
    // NOTA: para acceder a elemento de la posicion usamos posicion - 1, porque
    // en el arreglo no existe la posicion 6, ya que se cuenta desde la posicion 0 a 5
    // dando como resultado 6 elementos.
    digitalWrite(arregloDePines[posicion - 1], LOW);
    // Establecemos un tiempo de esperan antes que pase a la siguiente instrucción
    delay(500);
  }

  // Al terminar todos los ciclos, se hace un nuevo llamado a la funcion loop()
  // Creando el efecto de secuencia de encedido y apagado de los leds de forma infinita.
}