#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("hola :)");
  delay(2000);
}

void loop() {
  lcd.clear();
  lcd.print("Sigueme en mis");
  lcd.setCursor(0,1);
  lcd.print("redes sociales");
  delay(2000);
  lcd.clear();
  lcd.print("@emmaprofemx");
  delay(2000);
}
