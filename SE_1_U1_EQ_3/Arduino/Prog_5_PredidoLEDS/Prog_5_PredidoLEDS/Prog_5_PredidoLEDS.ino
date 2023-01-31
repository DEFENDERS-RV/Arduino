//LOS LEDS TIENEN DOS MODOS DE TRABAJNO , UNO DIGITIAL Y EL OTRO ANALOGICO

int leds [] = {4 , 5 , 6};
int i , tam = 3;
//ARDUINO UNO Y MEGA CUENTAN CON UN LED EN LA PLACA QUE SRIVE PARA REALIZAR PRUEBAS 
//ESTE LED SE UBICA EN EL PIN 13 

void setup() {
  // put your setup code here, to run once:
for (i = 0; i < tam; i++){
  pinMode(leds[i], OUTPUT);
}
}

void loop() { //16mHZ
  // put your main code here, to run repeatedly:
   ///OP1
  for (i = 0; i < tam; i++){
    digitalWrite(leds[i], 1);
}
  delay(1000);
 for (i = 0; i < tam; i++){
    digitalWrite(leds[i], 0);
}
  //op2 .- lo mas comun es esto
  delay(1000);

}
