#include <SoftwareSerial.h>

int bluethoothTx = 2;
int bluethoothRx = 3;


SoftwareSerial bluetooth(bluethoothTx,bluethoothRx);

void setup() {
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);
  Serial.begin(9600);
  bluetooth.begin(115200);
  bluetooth.print("$$$");
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);
  bluetooth.print("$$$");
  delay(100);
  bluetooth.println("D");
  delay(100); 
  while(bluetooth.available()) {
    Serial.print((char)bluetooth.read());
  }
  delay(100); 
  bluetooth.println("---");
  Serial.println("A = Aan U = Uit");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  char input;
  if(bluetooth.available()) {

    input=(char)bluetooth.read();
  }
  if(input=='A'){
    digitalWrite(4,HIGH);
  }else if (input=='B'){
    digitalWrite(4,LOW);
  }
  
}
