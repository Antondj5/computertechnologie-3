int input;
int leds[] = {10,11,12,13};
void setup() {
  // put your setup code here, to run once:
  for(int i =0;i<4;i++){
    pinMode(leds[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()==0);
  input = Serial.parseInt();

  if(input < 10){
    for(int i = 0;i<4;i++){
        digitalWrite(leds[i],LOW);
      }
    digitalWrite(10,HIGH);
    
  }else if(input < 100){
    digitalWrite(11,HIGH);
  }else if(input < 1000){
    for(int i = 0;i<4;i++){
        digitalWrite(leds[i],LOW);
      }
    digitalWrite(12,HIGH);
  }else if (input < 10000){
    for(int i = 0;i<4;i++){
        digitalWrite(leds[i],LOW);
      }
    digitalWrite(13,HIGH);
  }else{
    for(int i = 0;i<4;i++){
        digitalWrite(leds[i],LOW);
      }
    for(int i = 0;i<3;i++){
      for(int i = 0;i<4;i++){
        digitalWrite(leds[i],HIGH);
     }
     delay(200);
     for(int i = 0;i<4;i++){
        digitalWrite(leds[i],LOW);
      }
      delay(200);
    }
  }
}
