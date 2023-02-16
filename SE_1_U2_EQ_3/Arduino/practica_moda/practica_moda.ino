// Definición de la entrada analógica del potenciómetro
int potenciometro = A0;

// Definición de la cantidad de muestras a tomar
int totMuestras = 30;

// Array para almacenar las muestras tomadas
int muestras[totMuestras];

void setup() {
  // Inicializar la comunicación serie a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Tomar las muestras de la entrada analógica
  for (int i = 0; i < totMuestras; i++) {
    muestras[i] = analogRead(potenciometro);
  }

  // Ordenar las muestras de mayor a menor
  for (int i = 0; i < totMuestras - 1; i++) {
    for (int j = i + 1; j < totMuestras; j++) {
      if (muestras[i] < muestras[j]) {
        int temp = muestras[i];
        muestras[i] = muestras[j];
        muestras[j] = temp;
      }
    }
  }

  // Calcular la moda
  int moda = muestras[0];
  int contadorModa = 1;
  int contador = 1;
  for (int i = 1; i < totMuestras; i++) {
    if (muestras[i] == muestras[i - 1]) {
      contador++;
      if (contador > contadorModa) {
        contadorModa = contador;
        moda = muestras[i];
      }
    } else {
      contador = 1;
    }
  }

  // Mostrar la moda en el monitor serie
  Serial.println("Moda: " + String(moda));
  delay(1000);
}
