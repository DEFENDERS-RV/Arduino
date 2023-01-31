int leds [] = {4 , 5 , 6}; //pines digitales
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
  actionLeds(1);
  //op2 .- lo mas comun es esto
  delay(1000);
    actionLeds(0);
  delay(1000);

}

void actionLeds(int v){
    for (i = 0; i < tam; i++){
    digitalWrite(leds[i], v);
}
}