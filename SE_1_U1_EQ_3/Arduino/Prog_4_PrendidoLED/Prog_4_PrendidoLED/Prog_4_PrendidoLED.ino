//LOS LEDS TIENEN DOS MODOS DE TRABAJNO , UNO DIGITIAL Y EL OTRO ANALOGICO


int led1 = 4; //pines digitales: 0 - 13
int led2 = 5;
int led3 = 6;
//ARDUINO UNO Y MEGA CUENTAN CON UN LED EN LA PLACA QUE SRIVE PARA REALIZAR PRUEBAS 
//ESTE LED SE UBICA EN EL PIN 13 

void setup() {
  // put your setup code here, to run once:
  //SIEMPRE QUE SE TRABAJE CON UN PIN DIGITAL , SE DEBE DEFINIR SI EL PIN SERA DE ENTRADA O DE SALIDA
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);


}

void loop() { //16mHZ
  // put your main code here, to run repeatedly:
   ///OP1
  digitalWrite(led1, HIGH);
    digitalWrite(led2, true);
  digitalWrite(led3, 1); //LA MAS RECOMENDADA

  delay(1000);

  digitalWrite(led1, LOW);
    digitalWrite(led2, false);
  digitalWrite(led3, 0); //LA MAS RECOMENDADA


  //op2 .- lo mas comun es esto
  delay(1000);

}
