void setup() {
  // put your setup code here, to run once:
 analogReference(INTERNAL);
 pinMode(A0,INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long beging = micros();
   int in = analogRead(A0);
   long einde = micros();
   Serial.print(in);
   Serial.print("    :");
   Serial.println(einde - beging);
   delay(1000);
}
