const int trigPin = 7;  // Pin de salida del trigger
const int echoPin = 6;  // Pin de entrada del echo

void setup() {
  Serial.begin(9600);  // Iniciamos la comunicación serial
  pinMode(trigPin, OUTPUT);  // Pin de salida del trigger
  pinMode(echoPin, INPUT);  // Pin de entrada del echo
}

void loop() {
  // Enviamos una señal de trigger al sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medimos el tiempo que tarda en llegar el eco
  unsigned long duration = pulseIn(echoPin, HIGH);

  // Calculamos la distancia en cm
  float distance = duration * 0.034 / 2;

  // Comprobamos si el objeto está a menos de 30 cm
  if (distance <=30) {
    // Imprimimos la distancia en el monitor serie
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
  }else {
    // Imprimimos un mensaje de objeto no encontrado en el monitor serie
    Serial.println("Objeto fuera de rango");
  }
  // Esperamos 500ms antes de tomar la siguiente medida
  delay(500);
}
