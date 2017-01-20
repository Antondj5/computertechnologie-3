#include <LiquidCrystal.h>

LiquidCrystal lcd (12 , 11 , 5 , 4 , 3 , 2) ;
byte c05[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte c15[8] = {
  0b10000,0b10000,0b10000,0b10000,0b10000,0b10000,0b10000,0b10000
};

byte c25[8] = {
  0b11000,0b11000,0b11000,0b11000,0b11000,0b11000,0b11000,0b11000
};

byte c35[8] = {
  0b11100,0b11100,0b11100,0b11100,0b11100,0b11100,0b11100,0b11100
};

byte c45[8] = {
  0b11110,0b11110,0b11110,0b11110,0b11110,0b11110,0b11110,0b11110
};
byte c55[8] = {
  0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111
};
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.createChar(0,c05);
  lcd.createChar(1,c15);
  lcd.createChar(2,c25);
  lcd.createChar(3,c35);
  lcd.createChar(4,c45);
  lcd.createChar(5,c55);

  lcd.setCursor(0,1);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
