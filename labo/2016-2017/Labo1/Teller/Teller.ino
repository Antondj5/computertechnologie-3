#define K1 2
int tel=0;
long huidigeT,vorigeT= millis();
boolean flag = false;
void knop1ISR(){
  huidigeT=millis();
  if((huidigeT-vorigeT )> 100){
    tel+=1;
    flag=true;
  }
  vorigeT=millis();
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (K1,INPUT_PULLUP ); 
  attachInterrupt(digitalPinToInterrupt(K1),knop1ISR, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(flag==true){
    Serial.println(tel);
  }
  flag=false;
}
