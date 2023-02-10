int Led1 = 11;
int Led2 = 10;
int Led3 = 9;
int Led4 = 8;
int Led5 = 7;
int Led6 = 6;
int Led7 = 3;
int Led8 = 4;
int Potenciometro = 0;    



void setup() 
{
Serial.begin (9600); 
   
pinMode(Led1, OUTPUT);
pinMode(Led2, OUTPUT);
pinMode(Led3, OUTPUT); 
pinMode(Led4, OUTPUT);
pinMode(Led5, OUTPUT);
pinMode(Led6, OUTPUT);
pinMode(Led7, OUTPUT);
pinMode(Led8, OUTPUT);
}
 //Serial.begin (9600); 



void loop(){
  
  int ValorPot;
  
  
  ValorPot = analogRead(Potenciometro);    
  
   
  digitalWrite(Led1, HIGH);// 1.- PATRON DE IZQUIERDA A DERECHA
  delay(ValorPot);
  digitalWrite(Led1, LOW);
  delay(ValorPot);
  digitalWrite(Led2, HIGH);
  delay(ValorPot);
  digitalWrite(Led2, LOW);
  delay(ValorPot);
  digitalWrite(Led3, HIGH);
  delay(ValorPot);
  digitalWrite(Led3, LOW);
  delay(ValorPot);
  digitalWrite(Led4, HIGH); 
  delay(ValorPot);
  digitalWrite(Led4, LOW);
  delay(ValorPot);
  digitalWrite(Led5, HIGH);
  delay(ValorPot);
  digitalWrite(Led5, LOW);
  delay(ValorPot);
  digitalWrite(Led6, HIGH);
  delay(ValorPot);
  digitalWrite(Led6, LOW);
  delay(ValorPot);
  digitalWrite(Led7, HIGH);
  delay(ValorPot);
  digitalWrite(Led7, LOW);
  delay(ValorPot);
  digitalWrite(Led8, HIGH);
  delay(ValorPot);
  digitalWrite(Led8, LOW);
  delay(ValorPot);
  
  ///////////////////////////////////////
  
  digitalWrite(Led8, HIGH);//  LOS LEDS DE DERECHA A IZQUIERDA
  delay(ValorPot);
  digitalWrite(Led8, LOW);
  delay(ValorPot);
  digitalWrite(Led7, HIGH);
  delay(ValorPot);
  digitalWrite(Led7, LOW);
  delay(ValorPot);
  digitalWrite(Led6, HIGH);\
  
  delay(ValorPot);
  digitalWrite(Led6, LOW);
  delay(ValorPot);
  digitalWrite(Led5, HIGH); 
  delay(ValorPot);
  digitalWrite(Led5, LOW);
  delay(ValorPot);
  digitalWrite(Led4, HIGH);
  delay(ValorPot);
  digitalWrite(Led4, LOW);
  delay(ValorPot);
  digitalWrite(Led3, HIGH);
  delay(ValorPot);
  digitalWrite(Led3, LOW);
  delay(ValorPot);
  digitalWrite(Led2, HIGH);
  delay(ValorPot);
  digitalWrite(Led2, LOW);
  delay(ValorPot);
  digitalWrite(Led1, HIGH);
  delay(ValorPot);
  digitalWrite(Led1, LOW);
  delay(ValorPot);
  
  //////////////////////
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH); // 2.- TODOS LOS LEDS SE ENCIENDEN Y APAGAN
  digitalWrite(Led4, HIGH);
  digitalWrite(Led5, HIGH);
  digitalWrite(Led6, HIGH);
  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);     
  delay(ValorPot);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, LOW);
  digitalWrite(Led8, LOW);     
  delay(ValorPot);
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led4, HIGH);
  digitalWrite(Led5, HIGH);
  digitalWrite(Led6, HIGH);
  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);     
  delay(ValorPot);  
///////////////////////////////////
  digitalWrite(Led8, LOW);
  digitalWrite(Led7, LOW);     //3.- Se apagan los leds de a dos, de derecha a izquierda
  delay(ValorPot);
  
  digitalWrite(Led8, LOW);
  digitalWrite(Led7, LOW);
  delay(ValorPot);
  
  digitalWrite(Led6, LOW);
  digitalWrite(Led5, LOW);
  delay(ValorPot);

  digitalWrite(Led4, LOW);
  digitalWrite(Led3, LOW);
  delay(ValorPot);

  digitalWrite(Led2, LOW);
  digitalWrite(Led1, LOW);
  delay(ValorPot);

  }