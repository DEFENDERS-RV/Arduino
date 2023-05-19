#include <LiquidCrystal.h>

// Inicialización del objeto LiquidCrystal para controlar la pantalla LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Definición de los pines utilizados
const int trigPin = 7;         // Pin de salida para el sensor de ultrasonidos (trig)
const int echoPin = 6;         // Pin de entrada para el sensor de ultrasonidos (echo)
const int sensor1 = 8;         // Pin de entrada para el primer sensor de velocidad
const int sensor2 = 9;         // Pin de entrada para el segundo sensor de velocidad
const int ledRojo = 2;         // Pin de salida para el LED rojo
const int ledAmarillo = 3;     // Pin de salida para el LED amarillo
const int ledVerde = 4;        // Pin de salida para el LED verde

// Variables para el cálculo de la velocidad
unsigned long t1 = 0;
unsigned long t2 = 0;
unsigned long delta_t = 0;
float velocidad = 0.0;

void setup() {
  // Inicialización de la comunicación serial
  Serial.begin(9600);

  // Configuración de los pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  // Inicialización de la pantalla LCD
  lcd.begin(16, 2);  // Inicializa la LCD con 16 columnas y 2 filas
  lcd.print("Objeto fuera");  // Muestra el mensaje inicial
  lcd.setCursor(0, 1);
  lcd.print("de rango");
  delay(2000);  // Muestra el mensaje durante 2 segundos
}

void loop() {
  // Sensor de ultrasonidos
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  // Sensores de velocidad
  int valor1 = digitalRead(sensor1);
  int valor2 = digitalRead(sensor2);

  // Lectura de los estados de los LEDs
  int rojo = digitalRead(ledRojo);
  int amarillo = digitalRead(ledAmarillo);
  int verde = digitalRead(ledVerde);

  // Cálculo de la velocidad
  if (valor1 == LOW && valor2 == HIGH) {
    t1 = micros();
  }

  if (valor1 == HIGH && valor2 == LOW) {
    t2 = micros();
    delta_t = t2 - t1;
    velocidad = 170000.0 / delta_t;  // La distancia entre los sensores es de 17 cm, se multiplica por 100 para convertir a cm/s
  }

  // Impresión de los resultados en el Monitor Serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print("\tVelocidad: ");
  Serial.print(velocidad);
  Serial.println(" cm/s");

  // Mostrar los resultados en la pantalla LCD
  lcd.clear();
  if (distance <= 55) {
    lcd.print("Distancia: ");
    lcd.print(distance);
    lcd.print(" cm");
    lcd.setCursor(0, 1);
    lcd.print("Velocidad: ");
    lcd.print(velocidad);
    lcd.print(" cm/s");
  } else {
    lcd.print("Objeto fuera");
    lcd.setCursor(0, 1);
    lcd.print("de rango");
  }

  delay(100);
}
