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
EthernetServer server(80);
EthernetClient client ;

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
          if (readString.length() < 100) {
            readString += c ;
          }
          if(c == '\n'){
            if( readString.substring(6,10)=="LED=") {
              if(readString.charAt(10)=='A'){
                statusLED = bool(readString.charAt(14)-0x30);
                for(int i = 0;i<4;i++){
                  digitalWrite(2+i,statusLED);
                }
              }else{
              nrLED = readString.charAt(10)-0x30;
              statusLED = bool(readString.charAt(14)-0x30) ;
              digitalWrite(nrLED,statusLED);
              }
          }
          client.println(" HTTP /1.1 200 OK ") ;
          client.println(" Content - Type : text / html ");
          client.println();
          client.println("<!DOCTYPE html>");
          client.println("<head>");
          client.println("</head>");
          client.println("<body>");
          client.println("<H1> LED besturing </H1>");
          for(int i = 2;i<6;i++){
          client.print("<input type=checkbox ");
          if(digitalRead(i))client.print("checked ");
          client.print("onclick=location.href='/?LED=");
          client.print(i,DEC);
          client.print("&S=");
          if (! digitalRead(i)) client.print("1");
          else client.print("0");
          client.print("'>LED");
          client.print(i-2);
          client.println("</>");
          }
          client.println("Alles aan/uit:");
          client.print("<input type=button value='aan' onclick=location.href='/?LED=");
          client.print("A");
          client.println("&S=1'>");
          client.print("<input type=button value='uit' onclick=location.href='/?LED=");
          client.print("A");
          client.print("&S=0'>");
          client.println("</body>");
          client.println("</html>");
          delay(1);
          client.stop();
          readString="";
      }
    }
  }
}
}
