#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet2.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp2.h>
#include <Twitter.h>
#include <util.h>

#define K1 2
#define K2 3
#define LED1 8
#define LED2 9

byte mac[] = {0x90,0xA2,0xDA,0x10,0xAF,0xD7};

void knopISR1() {
  delay(10);
  if (digitalRead(LED1) == LOW){
    digitalWrite(LED1, HIGH);
  } else digitalWrite(LED1, LOW);
}

void knopISR2() {
  delay(10);
  if (digitalRead(LED2) == LOW){
    digitalWrite(LED2, HIGH);
  } else digitalWrite(LED2, LOW);
}
EthernetServer server(80);
EthernetClient client ;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(K1), knopISR1, FALLING);
  attachInterrupt(digitalPinToInterrupt(K2), knopISR2, FALLING);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  Serial.begin(9600);
  if(Ethernet.begin(mac)){
    Serial.println("IP - adres ontvangen :");
    Serial.println(Ethernet.localIP());
    server.begin();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
    EthernetClient client = server.available () ;
    if(client){
    while(client.connected()){
      if(client.available()){
          client.println(" HTTP /1.1 200 OK ") ;
          client.println(" Content - Type : text / html ");
          client.println();
          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<meta http-equiv='refresh' content='1'>");
          client.println("</HEAD>");
          client.println("</HTML>");
          Serial.println("connected");
          client.println("Led 1:");
          (digitalRead(LED1)==LOW)?client.println("uit"):client.println("aan");
          client.println("Led 2:");
          (digitalRead(LED2)==LOW)?client.println("uit"):client.println("aan");
          client.stop();
    
    
  }}
}}
