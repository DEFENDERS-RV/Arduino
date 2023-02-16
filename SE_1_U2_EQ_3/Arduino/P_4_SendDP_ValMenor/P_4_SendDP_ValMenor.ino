int potenciometro = A0;

int totMuestras = 30;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int i , valor , valorMenor = 1024; //9999
void loop() {
  // put your main code here, to run repeatedly:
    for(i = 0; i <toMuestras; i++){ //-> Teorema del Limite Central
      valor = analogRead(potenciometro);
      if(valor<valorMenor){
          valorMenor = valor;
      }
    }
  //valor /= 10;
  Serial.println(valorMenor);
  delay(1000);

}
