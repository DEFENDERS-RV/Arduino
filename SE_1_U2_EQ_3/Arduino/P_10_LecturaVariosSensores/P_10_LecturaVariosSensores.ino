int sensor1 = A0; //pot1
int sensor2 = A1; //pot2
int sensor3 = A2; //pot3



void setup() {
Serial.begin(9600) ;
//Serial.setTimeout(100); 
//100 miliegundos leyendo la informacion
pinMode(led,OUTPUT);
}

int vP1 , vP2 , vP3;

void loop() {
 vP1 = analogRead(sensor1);
 vP2 = analogRead(sensor2);
 vP3 = analogRead(sensor3);


Serial.println("E"+ String(vP1) + "G" String(vP2) + "G" String(vP3) + "J");


delay(100);
}
