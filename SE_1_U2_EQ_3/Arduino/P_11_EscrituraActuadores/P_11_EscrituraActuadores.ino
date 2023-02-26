//Actuadores analogicos
int actuador1 = 3;
int actuador2 = 5;
int actuador3 = 6;

void setup() {
  Serial.begin(9600); 
  Serial.setTimeout(10);
}

int vA , vB , vC , cont =0;
String cadena;
void loop() {
  if(Serial.available()>0){
    String c = Serial.readString();
    //Serial.println(c); //confirmacion de la lectura recibida
    //E001R010R220J
  
    if(cadena.length() == 13){ //cadena completa
       // Serial.println(cadena);
        if(cadena.charAt(0) == 'E' && cadena.charAt(cadena.length()-1) == 'J'){ //segunda validacion
         String c = cadena.substring(1,cadena.length()-1);
         Serial.println("C:" + c + ":D");

          //strtok
          //charAt y un for
          //indexOf
          //en lugar de readString usar read
          //substring

          //---->>Keystrokes en Python....
          //EJEMPLOS DEL FUNCIONAMIENTO DE KEYSTROKES

          //---->> Pulsador en su configuuracion pullup con Arduino
          //ES VALIDO SOLO SI SE PUEDE USAR
          char *cad = c.c_str();

          char *garuco = strtok(cad,"R"); //toquenizador

          //Serial.println(garuco)
          while(*garuco != NULL){//INICIO DEL WHILE
            switch (cont) {
            case 0:
            vA = String(garuco).toInt();
            break;
            case 1:
            vB = String(garuco).toInt();
            break;
            case 2:
            vC = String(garuco).toInt();
            break;
            }
            cont++;
             garuco = strtok(NULL, "R");
          } //FIN DEL WHILE
          Serial.println(String(vA) + " " + String(vB) + " " + String(vC));
        
      }
    }
  }
  delay(100);
}