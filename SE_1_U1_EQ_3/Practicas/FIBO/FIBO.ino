const int numLeds = 8; // Número de leds utilizados
const int ledPins[numLeds] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pinout de cada uno de los leds
int fib[numLeds]; // Array para almacenar los valores de la secuencia Fibonacci
void setup() {
  // Configura cada uno de los pines de los leds como salida
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(A0, INPUT); // Configura el pin del potenciómetro como entrada
  Serial.begin(9600); // Inicializa la comunicación serial
  // Calcula los primeros valores de la secuencia Fibonacci
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < numLeds; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
}
void loop() {
  int val = analogRead(A0); // Lee el valor del potenciómetro
  int index = map(val, 0, 1023, 0, 7); // Convierte el valor leído en un índice para la secuencia Fibonacci
  int binary = fib[index]; // Selecciona un valor de la secuencia
  String binaryString = ""; // Inicializa una cadena para almacenar el valor binario
  for (int i = 0; i < numLeds; i++) {
    int ledVal = binary % 2; // Obtiene el último dígito binario del valor
    binary = binary / 2; // Quita el último dígito binario del valor
    digitalWrite(ledPins[i], ledVal); // Escribe el valor en el led correspondiente
    binaryString = String(ledVal) + binaryString; // Concatena el valor binario a la cadena
  }
  Serial.println("Valor binario: " + binaryString); // Muestra el valor binario en la consola serial
  delay(100); // Espera un poco antes de volver a repetir el ciclo
}