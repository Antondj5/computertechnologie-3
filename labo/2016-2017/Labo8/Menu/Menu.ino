#include <sha256.h>

  // put your main code here, to run repeatedly:
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet2.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp2.h>
#include <Twitter.h>
#include <util.h>

int nrLED ;
bool statusLED ;

byte mac[] = {0x90,0xA2,0xDA,0x10,0xAF,0xD7};
String readString = "";
EthernetServer server(23);
EthernetClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 for(int i = 0;i<4;i++){
  pinMode(2+i,OUTPUT);
 }
  if(Ethernet.begin(mac)){
    Serial.println("IP - adres ontvangen :");
    Serial.println(Ethernet.localIP());
    delay(1000);
    server.begin();
  }
 }

void loop() {
  EthernetClient client = server.available () ;
    if(client){
      while(client.connected()){
        if(client.available()){
          char c = client.read() ;
              if(c=='a'){
                for(int i = 0;i<4;i++){
                  digitalWrite(2+i,HIGH);
                }
               }else if(c=='b'){
                  for(int i = 0;i<4;i++){
                  digitalWrite(2+i,LOW);
                  }
               }else if(c=='c'){
                client.println("geef het nummer van de LED gevolgd door A (aan) of U (uit), bv. 2A:");
                char l = client.read();
                l = client.read();
                String out = "";
                while(client.available()==0){}
                byte led = client.read() - 0x31;
                char b = client.read();
                client.println(led);
                client.println(b);
                bool statusLed = (b=='A')?true:false;
                digitalWrite(led+2,statusLed);
            }else if(c=='q'){
                  client.stop();
               }else {
                client.println("a. alle LED’s aan") ;
                client.println("b. alle LED’s uit");
                client.println("c. individuele LED aansturen");
                client.println("q. verbinding verbreken");
               }
          }
          delay(1);
          readString="";
      }
    }
  }



