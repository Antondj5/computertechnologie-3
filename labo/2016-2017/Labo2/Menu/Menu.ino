int leds[] = {10,11,12,13};
char select;
char inputcchar;
int inputcnumb;
void setup() {
  // put your setup code here, to run once:
  for(int i =0;i<4;i++){
    pinMode(leds[i],OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Toets de letter in van uw keuze:");
  Serial.println("a. alle LED’s aan");
  Serial.println("b. alle LED’s uit");
  Serial.println("c. individuele LED aansturen");
}

void loop() {
  // put your main code here, to run repeatedly:
    if(Serial.available() > 0){
    select = Serial.read();
    if(select == 'a'){
      for(int i = 0;i<4;i++){
        digitalWrite(leds[i],HIGH);
      }
    }else if(select == 'b'){
      for(int i = 0;i<4;i++){
        digitalWrite(leds[i],LOW);
      }
    }else if(select == 'c'){
      Serial.println("geef het nummer van de LED gevolgd door A (aan) of U (uit), bv. 2A:");
      while(Serial.available()==0);
       inputcnumb = Serial.parseInt();
       while(Serial.available()==0);
       inputcchar = Serial.read();
       if(inputcchar=='a'){
        digitalWrite(leds[inputcnumb-1],HIGH);
       }else if (inputcchar=='u'){
        digitalWrite(leds[inputcnumb-1],LOW);
       }
    }else{
      Serial.println("geef het juiste karakter in");
    }
  }
   
  
}
