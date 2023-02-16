int led = 13;
void setup() {
Serial.begin(9600) ;
Serial.setTimeout(100);
//100 miliegundos leyendo la informacion
pinMode(led,OUTPUT);
}

//long val = 0

void loop() {
 if(Serial.available()>0){
    int v = Serial.readString().toInt();
    digitalWrite(led,v); // 1 0
 }
  delay(10);
}
