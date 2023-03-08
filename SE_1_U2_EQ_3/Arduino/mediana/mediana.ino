const int potPin = A0;   // Pin analógico utilizado para leer el potenciómetro
int valores[10];          // Array para almacenar los valores leídos del potenciómetro
int mediana;             // Variable para almacenar la mediana

void setup() {
  Serial.begin(9600);
}

void loop() {
 // Leer valores del potenciómetro y almacenarlos en el array
  for (int i = 0; i < 10; i++) {
    valores[i] = analogRead(potPin);
    Serial.print(valores[i]);  // Imprimir el valor actual
    Serial.print(",");       // Separador para los valores
    delay(50);
  }

  // Ordenar los valores del array
  for (int i = 0; i < 10; i++) {
    for (int j = i+1; j < 10; j++) {
      if (valores[j] < valores[i]) {
        int temp = valores[i];
        valores[i] = valores[j];
        valores[j] = temp;
      }
    }
  }
  
  // Imprimir los valores ordenados en el monitor serial
  Serial.print("Valores ordenados: ");
  for (int i = 0; i < 10; i++) {
    Serial.print(valores[i]);
    Serial.print(",");
  }
  Serial.println();

  // Calcular la mediana
  if (10 % 2 == 0) {
    mediana = (valores[4] + valores[5]) / 2;
  } else {
    mediana = valores[5];
  }

  // Imprimir la mediana en el monitor serial
  Serial.print("Mediana: ");
  Serial.println(mediana);
  

  delay(1000);  // 
}