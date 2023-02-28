//Actuadores analógicos
int actuador1 = 3;  // Asigna el pin 3 al primer actuador
int actuador2 = 5;  // Asigna el pin 5 al segundo actuador
int actuador3 = 6;  // Asigna el pin 6 al tercer actuador

void setup() {
  Serial.begin(9600);          // Inicia la comunicación serial con una velocidad de transmisión de 9600 baudios
  Serial.setTimeout(10);       // Configura un tiempo de espera de 10 milisegundos para la lectura serial
  pinMode(actuador1, OUTPUT);  // Configura el primer actuador como salida
  pinMode(actuador2, OUTPUT);  // Configura el segundo actuador como salida
  pinMode(actuador3, OUTPUT);  // Configura el tercer actuador como salida
}

int vA1, vA2, vA3;  // Variables para almacenar los valores de voltaje de los actuadores

void loop() {
  if (Serial.available() > 0) {      // Verifica si hay datos disponibles en la entrada serial
    String c = Serial.readString();  // Lee la cadena recibida desde la entrada serial y la guarda en la variable c
    Serial.println(c);               // Imprime la cadena leída para confirmar que se recibió correctamente

    if (c.length() == 13) {        // Verifica si la cadena recibida tiene una longitud de 13 caracteres
      Serial.println(c.length());  // Imprime la longitud de la cadena para verificar

      //E001R010R220J
      if (c.charAt(0) == 'E' && c.charAt(c.length() - 1) == 'J') {  // Verifica si la cadena comienza con 'E' y termina con 'J'
        c = c.substring(1, c.length() - 1);                         // Elimina el primer y último carácter de la cadena
        c.replace("R", "");                                         // Elimina todas las ocurrencias de la letra 'R' en la cadena

        Serial.println(c);  // Imprime la cadena resultante para verificar

        // Separa los valores de voltaje de la cadena
        String vA1_str = c.substring(0, 3);  // Obtiene los caracteres del 1 al 3 como una subcadena
        String vA2_str = c.substring(3, 6);  // Obtiene los caracteres del 4 al 6 como una subcadena
        String vA3_str = c.substring(6, 9);  // Obtiene los caracteres del 7 al 9 como una subcadena

        // Convierte los valores de voltaje de tipo String a tipo int
        vA1 = vA1_str.toInt();
        vA2 = vA2_str.toInt();
        vA3 = vA3_str.toInt();

        // Envía los valores de voltaje a los actuadores correspondientes
        analogWrite(actuador1, vA1);  // Envia el valor de voltaje del primer actuador al pin correspondiente
        analogWrite(actuador2, vA2);  // Envia el valor de voltaje del segundo actuador al pin correspondiente
        analogWrite(actuador3, vA3);  // Envia el valor de voltaje del tercer actuador al pin correspondiente

        // Imprime los valores de voltaje de cada actuador para verificar
        Serial.print("Voltaje Actuador 1: ");
        Serial.println(vA1);
        Serial.print("Voltaje Actuador 2: ");
        Serial.println(vA2);
        Serial.print("Voltaje Actuador 3: ");
        Serial.println(vA3);
      }
    }
  }
  delay(10);  // Retardo de 100 milisegundos antes de leer la entrada serial nuevamente
}