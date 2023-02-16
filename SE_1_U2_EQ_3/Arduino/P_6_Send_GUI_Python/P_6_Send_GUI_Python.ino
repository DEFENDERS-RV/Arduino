void setup() {

Serial.begin(9600)  

}

long val = 0

void loop() {
  val++;
  Serial.println(val);
  delay(100);
}
