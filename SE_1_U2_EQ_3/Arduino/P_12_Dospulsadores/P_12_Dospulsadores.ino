int pulsador1 = 3; //elegimos pines digitales , menos el 0 y el 1 
int pulsador2 = 4;
int v1 , v2;
void setup() {
  // put your setup code here, to run once:

  pinMode(pulsador1 , INPUT_PULLUP);
  pinMode(pulsador2 , INPUT_PULLUP);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  v1 = digitalRead(pulsador1); // 0 - 1 
  v2 = digitalRead(pulsador2); // 0 - 1 

  v1 = (v1 == 1) ? 0 : 1;
  v2 = (v2 == 1) ? 0 : 1; //SIMULACIONES DE LAS COMPUERTAS LOGICAS CON LEDS Y PULSADORES
  //and or , sorts , una entrada y una salida 

  String c = "E" + String(v1) + "R" + String(v2) + "C";
  Serial.println(c);
  delay(100);





}
