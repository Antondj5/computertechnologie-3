#define LED1 7
#define LED2 8
#define K1 2
#define K2 3
boolean locked = true;
void knop1ISR(){
  delay(20);
   if(digitalRead(LED1) == HIGH){
    digitalWrite(LED1,LOW);
   }   else {
    digitalWrite(LED1,HIGH);
   }
  }
void knop2ISR(){
  if(locked==false){
    detachInterrupt(K1);
    digitalWrite(LED2,HIGH);
    locked = true;
  }else{
    attachInterrupt(digitalPinToInterrupt(K1),knop1ISR, FALLING);
    digitalWrite(LED2,LOW);
  }
}
void setup() {
  // put your setup code here, to run once:
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode (K1,INPUT_PULLUP ); 
  pinMode (K2,INPUT_PULLUP ); 
  attachInterrupt(digitalPinToInterrupt(K2),knop2ISR, FALLING);
  digitalWrite(LED2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
}
