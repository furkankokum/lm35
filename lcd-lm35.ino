#include <Wire.h>
#include <LiquidCrystal.h>

const int lm35 = A3;

float voltajDeger = 0;
float sicaklik = 0;
float sicaklikF = 0;
int gelenVeri = 0;
byte karakter1[8] = {0x0C,0x12,0x12,0x0C,0x00,0x00,0x00,0x00};
LiquidCrystal lcd (12,11,5,4,3,2);
void setup() {
  lcd.begin(16,2);
  lcd.createChar(5,karakter1);
}
void loop() {
  gelenVeri = analogRead(lm35);
  voltajDeger = (gelenVeri/1023.0)*5000;
  sicaklik = voltajDeger / 10.0;  //derece cinsinden
  sicaklikF = (sicaklik*1.8)+32;
  lcd.clear();
  lcd.home();
  lcd.print("sicaklik = ");
  lcd.setCursor(0,1);
  lcd.print(sicaklikF);
  lcd.write(byte(5));
  lcd.print("Fahrenheit");
  delay(1000);
  
}
