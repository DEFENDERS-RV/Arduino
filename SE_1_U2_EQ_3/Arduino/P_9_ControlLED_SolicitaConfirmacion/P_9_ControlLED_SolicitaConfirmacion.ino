int led = 13;
void setup() {
Serial.begin(9600) ;
Serial.setTimeout(100);
//100 miliegundos leyendo la informacion
pinMode(led,OUTPUT);
}

//long val = 0
int estado;

void loop() {
 if(Serial.available()>0){
    estado = Serial.readString().toInt();
    digitalWrite(led,estado); // 1 0
    Serial.println()
 }

 Serial.println(String(estado));
delay(10);
}
