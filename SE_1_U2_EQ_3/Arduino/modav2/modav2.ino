int potenciometro = A0;
const int totMuestras = 30;

int muestras[totMuestras];

void setup() {
  Serial.begin(9600);
}

void loop() {
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