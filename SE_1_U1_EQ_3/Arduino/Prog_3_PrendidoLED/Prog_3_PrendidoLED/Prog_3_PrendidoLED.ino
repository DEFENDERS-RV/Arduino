//LOS LEDS TIENEN DOS MODOS DE TRABAJNO , UNO DIGITIAL Y EL OTRO ANALOGICO


int led = 13;
//ARDUINO UNO Y MEGA CUENTAN CON UN LED EN LA PLACA QUE SRIVE PARA REALIZAR PRUEBAS 
//ESTE LED SE UBICA EN EL PIN 13 

void setup() {
  // put your setup code here, to run once:
  //SIEMPRE QUE SE TRABAJE CON UN PIN DIGITAL , SE DEBE DEFINIR SI EL PIN SERA DE ENTRADA O DE SALIDA
  pinMode(led, OUTPUT);
}

void loop() { //16mHZ
  // put your main code here, to run repeatedly:
   ///OP1

  
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  //op2 .- lo mas comun es esto
  delay(1000);

}
