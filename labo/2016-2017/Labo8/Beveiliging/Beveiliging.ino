#include <sha256.h>
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet2.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp2.h>
#include <Twitter.h>
#include <util.h>
#define sha256Length 32

int nrLED ;
bool statusLED ;
String geheime_code = "1234";
//hash berekenen van randomwaarde + led + geheime_code

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
 // Serial.println(hash);

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
          String readin="";
          String hash= "";
          while(client.available()){
            readin+= char(client.read());
          }
          client.println(readin.substring(0,3));
          if(readin.substring(0,3)=="led"){
            int randomWaarde = millis();
            client.println(randomWaarde);
            Sha256.init();
            String toString = String(randomWaarde)+"led"+"1234";
            Sha256.print(toString);
            uint8_t* result = Sha256.result();
            for(int i=0; i<32 ; i++){
               if(result[i] < 0x10) hash += "0" ;
                hash += String(result[i],HEX);
               }
            Serial.println(hash);
            while(client.available()==0){};
            String hash2 = "";
            for(int i = 0; i<64;i++){
              while(client.available()){
              hash2 += char(client.read());
              }
            }
            client.println(hash2);
            client.println(hash==hash2);
            if(hash==hash2){
              digitalWrite(2,HIGH);
            }
            }
          
        }
          delay(1);
          readString="";
      }
    }
  }



