const int sensor1 = 8;
const int sensor2 = 9;

unsigned long t1 = 0;
unsigned long t2 = 0;
unsigned long delta_t = 0;
float velocidad = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
}

void loop() {
  int valor1 = digitalRead(sensor1);
  int valor2 = digitalRead(sensor2);

  if (valor1 == LOW && valor2 == HIGH) {
    t1 = micros();
  }

  if (valor1 == HIGH && valor2 == LOW) {
    t2 = micros();
    delta_t = t2 - t1;
    velocidad = 170000.0 / delta_t; // La distancia entre los sensores es de 17cm, se multiplica por 100 para convertir a cm/s
    Serial.print("Velocidad: ");
    Serial.print(velocidad);
    Serial.println(" cm/s");
  }

  delay(10);
}
