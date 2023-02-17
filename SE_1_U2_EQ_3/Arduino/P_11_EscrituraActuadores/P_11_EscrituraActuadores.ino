//Actuadores analogicos
int actuador1 = 3;
int actuador2 = 5;
int actuador3 = 6;

void setup() {
  Serial.begin(9600); 
  Serial.setTimeout(10);
}

int vA1 , vA2 , vA3;

void loop() {
  if(Serial.available()>0){
    String c = Serial.readString();
    Serial.println(c); //confirmacion de la lectura recibida
    //E001R010R220J
  
    if(c.length() == 13){ //cadena completa
      Serial.println(c.length());
      if(c.charAt(0) == "E"  && c.charAt(c.length()-1) == "J"){ //segunda validacion
          c. = c.substring(1,c.length()-2);
          Serial.println(c);
      }
    }
  }
  delay(100);
}