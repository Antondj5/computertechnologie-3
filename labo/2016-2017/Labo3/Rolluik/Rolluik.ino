int onder = 140;
int boven = 560;
int grensBoven=(560/100)*5;
int grensOnder=(140/100)*5;
int leds[] = {9,10,11,12};
void setup() {
Serial.begin(9600);
  for(int i = 0;i<4;i++){
    pinMode(leds[i],OUTPUT);
  }
  pinMode(A0,INPUT);
}

void loop() {
  for(int i = 0; i < 4; i++){
    digitalWrite(leds[i],LOW);
  }
  
  int in = analogRead(A0);
  
  if(in < onder + grensOnder ){
    digitalWrite(9,HIGH);
  }
  
  if(in < boven + grensBoven){
    digitalWrite(10,HIGH);
  }
  
  if(in < onder - grensOnder){
    digitalWrite(9,HIGH);
  }
  
  if(in < boven - grensBoven){
    digitalWrite(10,HIGH);
  }

}
