int potenciometro = A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

int valor;
void loop() {
  // put your main code here, to run repeatedly:
  valor = analogRead(potenciometro);

  //Serial.println("Valor=" + String(valor));
  Serial.println(valor);
  delay(1000);
}