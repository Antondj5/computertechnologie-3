#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet2.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp2.h>
#include <Twitter.h>
#include <util.h>


byte mac[] = {0x90,0xA2,0xDA,0x10,0xAF,0xD7};
int val = 0;
int potPin = 0;

EthernetServer server(80);
EthernetClient client ;

void setup() {
  if(Ethernet.begin(mac)){
    Serial.println("IP - adres ontvangen :");
    Serial.println(Ethernet.localIP());
    server.begin();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    val = analogRead(potPin);
    EthernetClient client = server.available () ;
    if(client){
    while(client.connected()){
      if(client.available()){
        char c = client.read() ;
        if ( readString.length() < 100) {
          readString += c ;
        }
        if(c=="\ n") {
          if( readString.substring(6 ,10) == " LED = ") {
            nrLED = readString.charAt(10)- 0x30 ;
            statusLED = bool(readString.charAt(14)- 0x30) ;
            digitalWrite(nrLED ,statusLED);
        }

          client.println(" HTTP /1.1 200 OK ") ;
          client.println(" Content - Type : text / html ");
          client.println();
          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<meta http-equiv='refresh' content='1'>");
          client.println("</HEAD>");
          client.println("</HTML>");
          Serial.println("connected");
          client.println("Potentiometer:");
          client.print("<progress value='");
          client.print(val);
          client.println("' max='1024'></progress>");
          client.stop();
    
    
  }}
}}

  // put your main code here, to run repeatedly:
  
