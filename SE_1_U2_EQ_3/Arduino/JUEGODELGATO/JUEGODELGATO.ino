int ledPins[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10}; // Pines para los LEDs
int buttonPins[2] = {11, 12}; // Pines para los botones

int player = 1; // Jugador actual (1 o 2)
int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // Tablero de juego (0: vacío, 1: jugador 1, 2: jugador 2)

void setup() {
  // Configuración de los pines
  for (int i = 0; i < 9; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPins[0], INPUT_PULLUP);
  pinMode(buttonPins[1], INPUT_PULLUP);
}

void loop() {
  // Esperar a que se presione un botón
  while (digitalRead(buttonPins[0]) == HIGH && digitalRead(buttonPins[1]) == HIGH) {
    // Mostrar el tablero actual
    for (int i = 0; i < 9; i++) {
      if (board[i] == 1) {
        digitalWrite(ledPins[i], HIGH); // Jugador 1
      } else if (board[i] == 2) {
        digitalWrite(ledPins[i], LOW); // Jugador 2
      } else {
        digitalWrite(ledPins[i], LOW); // Vacío
      }
    }
    delay(100);
  }
  
  // Determinar la posición seleccionada por el jugador
  int pos = 0;
  while (digitalRead(buttonPins[0]) == HIGH || digitalRead(buttonPins[1]) == HIGH) {
    if (digitalRead(buttonPins[0]) == LOW) {
      pos = 1;
      break;
    } else if (digitalRead(buttonPins[1]) == LOW) {
      pos = 2;
      break;
    }
  }
  while (digitalRead(buttonPins[0]) == LOW || digitalRead(buttonPins[1]) == LOW) {}
  delay(100);
  
  // Actualizar el tablero
  int index = posToIndex(pos);
  if (board[index] == 0) {
    board[index] = player;
    player = 3 - player; // Cambiar al siguiente jugador
  }
}

// Función para convertir la posición del botón en un índice del tablero
int posToIndex(int pos) {
  switch (pos) {
    case 1: return 0;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    case 5: return 4;
    case 6: return 5;
    case 7: return 6;
    case 8: return 7;
    case 9: return 8;
    default: return 0;
  }
