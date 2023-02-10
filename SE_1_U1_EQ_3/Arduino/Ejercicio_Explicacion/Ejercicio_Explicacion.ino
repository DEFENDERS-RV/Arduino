byte variable = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(variable == 0){
    Serial.println("La variable ha llegado al limite inferior");
  }
  if(variable == 255){
    Serial.println("La variable ha llegado al limite superior");
  }
  variable++;
  delay(100);
}
