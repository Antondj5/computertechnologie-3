#include <LiquidCrystal.h>

LiquidCrystal lcd (12 , 11 , 5 , 4 , 3 , 2) ;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,1);
  //56
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Dit is een tekst die langer is dan de groote van het lcd");
  for(int pos = 0; pos < 40;pos++){
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for(int i =0;i<3;i++){
    lcd.clear();
    delay(300);
    lcd.setCursor(0,1);
    lcd.print("hallo");
    lcd.display();
    delay(300);
    lcd.noDisplay();
    lcd.clear();
  }
  lcd.display();
}

