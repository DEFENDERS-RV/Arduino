int s1 = A0;
int s2 = A1;
int s3 = A2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 // Serial.setTimeout(10); //ES OPCIONAL
  }

//comprar potenciadores y 
void loop() {
  // put your main code here, to run repeatedly:
  int v1 = analogRead(s1);
  int v2 = analogRead(s2);
  int v3 = analogRead(s3);

  String c = "E" + String(v1) + "R" + String(v2) + "R" + String(v3) + "C";
  Serial.print("\n"+c);
  delay(500);
}
