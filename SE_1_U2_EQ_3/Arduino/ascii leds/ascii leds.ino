void setup() {
  // Configurar los pines de los LED como salidas
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  // Iniciar la comunicación serie a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readString();
    Serial.println(input);
    // Recorrer cada carácter de la cadena y encender los LEDs correspondientes
    for (int i = 0; i < input.length(); i++) {
      int ascii = input.charAt(i);
      for (int j = 0; j < 8; j++) {
        digitalWrite(j + 2, (ascii >> j) & 1);
      }
      delay(500); // Esperar medio segundo antes de apagar los LEDs
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      delay(500); // Esperar medio segundo antes de continuar con el siguiente carácter
    }
  }
}