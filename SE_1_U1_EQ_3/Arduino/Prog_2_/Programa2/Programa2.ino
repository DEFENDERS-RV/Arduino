byte numero; // 0 -255

void setup() {
  // put your setup code here, to run once:
  numero = 0;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(numero);
if(numero < 255){
  numero++;
}
else{
  Serial.print("- Se ha llegadao al limite de la Varibale");

}
Serial.println();
delay(1000);
}
