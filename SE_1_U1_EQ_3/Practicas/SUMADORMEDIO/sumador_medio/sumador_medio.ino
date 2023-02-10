int ledA = 13;   // LED A conectado al pin 13
int ledB = 12;   // LED B conectado al pin 12
int potSum = A0; // Potenciómetro para la suma conectado al pin A0
int potCarga = A1; // Potenciómetro para la carga conectado al pin A1

void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  Serial.begin(9600);   // Inicializar la comunicación serial a 9600 baudios
}

void loop() {
  int sum = analogRead(potSum);  // Leer el valor del potenciómetro para la suma
  int carga = analogRead(potCarga);  // Leer el valor del potenciómetro para la carga
  //sum = map(sum, 0, 1023, 0, 1);  // Mapear el rango de valores de 0 a 1023 a 0 a 1
  //carga = map(carga, 0, 1023, 0, 1);  // Mapear el rango de valores de 0 a 1023 a 0 a 1
  sum = map(sum, 0, 1023, 0, 255);
  carga = map(carga, 0, 1023, 0, 255);
  int media = (sum + carga) / 2;  // Calcular la media de los dos valores
  int bitA = media & 1;  // Obtener el bit menos significativo de la media
  int bitB = (media >> 1) & 1;  // Desplazar la media a la derecha y obtener el bit menos significativo

  digitalWrite(ledA, bitA);  // Encender o apagar el LED A según el bit A
  digitalWrite(ledB, bitB);  // Encender o apagar el LED B según el bit B

  Serial.print("Valor de la suma: ");
  Serial.println(sum);  // Imprimir el valor de la suma
  Serial.print("Valor de la carga: ");
  Serial.println(carga);  // Imprimir el valor de la carga
  Serial.print("Valor del bit A: ");
  Serial.println(bitA);  // Imprimir el valor del bit A
  Serial.print("Valor del bit B: ");
  Serial.println(bitB);  // Imprimir el valor del bit B
  delay(100);  // Esperar 1 segundo antes de la siguiente lectura
}