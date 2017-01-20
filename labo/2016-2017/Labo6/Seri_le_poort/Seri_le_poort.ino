#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet2.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp2.h>
#include <Twitter.h>
#include <util.h>

int val;
byte mac[] = {0x90,0xA2,0xDA,0x10,0xAF,0xD7};
int potPin = 0;
String readString = "";
String out ="";
EthernetServer server(80);
EthernetClient client ;

void setup() {
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
      if(Serial.available()){
        char c = Serial.read();
        if (readString.length() < 100) {
            if(c == '\n'){
              out+="<BR>";
            }
            readString += c ;
            out += readString;
        }
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
          client.print(out);
          client.stop();
          readString="";
    
    
  }}
}

  // put your main code here, to run repeatedly:
  
