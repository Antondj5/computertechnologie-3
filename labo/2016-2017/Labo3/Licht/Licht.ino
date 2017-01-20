int leds[] = {9,10,11,12};
//max = 700, grenzen:0 - 140 140 - 280 280 - 420 420 - 560 560 - 700
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
  int aan;
  if(in < 140){
    aan = 4;
  }else if(in < 280){
     aan = 3;
  }else if(in < 420){
     aan = 2;
  }else if(in < 560){
     aan = 1;
  }else if(in < 700){
     aan = 0;
  }
  for(int i = 0; i < aan; i++){
    digitalWrite(leds[i],HIGH);
  }
}
