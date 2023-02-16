int potenciometro = A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//Serial.println();
}

int i,valor;
void loop() {
  // put your main code here, to run repeatedly:
  for(i=0;i<10; i++){
    valor += analogRead(potenciometro);
  }
  valor /=10;

  //Serial.println("Valor=" + String(valor));
  Serial.println(valor);
  delay(1000);
}
