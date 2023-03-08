// Definir la palabra a adivinar
String palabra = "ARDUINO";

// Definir el número de intentos permitidos
const int numIntentos = 6;

// Definir las variables globales
int intentos = 0;
String palabraAdivinada = "";

void setup() {
  // Inicializar la comunicación con el monitor en serie
  Serial.begin(9600);

  // Inicializar la palabra a adivinar con guiones bajos
  for (int i = 0; i < palabra.length(); i++) {
    palabraAdivinada += "_";
  }
}

void loop() {
  // Mostrar la palabra adivinada y el número de intentos restantes
  Serial.println("Palabra a adivinar: " + palabraAdivinada);
  Serial.println("Intentos restantes: " + String(numIntentos - intentos));

  // Pedir al usuario que ingrese una letra
  Serial.print("Ingrese una letra: ");
  while (Serial.available() == 0) {
    // Esperar a que el usuario ingrese una letra
  }
  char letra = Serial.read();

  // Verificar si la letra ingresada está en la palabra a adivinar
  bool letraCorrecta = false;
  for (int i = 0; i < palabra.length(); i++) {
    if (palabra.charAt(i) == letra) {
      palabraAdivinada.setCharAt(i, letra);
      letraCorrecta = true;
    }
  }

  // Si la letra es incorrecta, incrementar el número de intentos
  if (!letraCorrecta) {
    intentos++;
  }

  // Verificar si el juego ha terminado
  if (palabraAdivinada == palabra) {
    Serial.println("¡Felicidades, has ganado!");
    while (true) {
      // Esperar aquí para que el juego no se reinicie automáticamente
    }
  }
  else if (intentos == numIntentos) {
    Serial.println("¡Lo siento, has perdido! La palabra era: " + palabra);
    while (true) {
      // Esperar aquí para que el juego no se reinicie automáticamente
    }
  }
}