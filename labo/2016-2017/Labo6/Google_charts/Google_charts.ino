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
          client.println("<html>");
client.println("  <head>");
client.println("<meta http-equiv=\"refresh\" content=\"1\">");
client.println("   <script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>");
client.println("   <script type=\"text/javascript\">");
client.println("       google.charts.load('current', {'packages':['gauge']});");
client.println("      google.charts.setOnLoadCallback(drawChart);");
client.println("      function drawChart() {");
client.println("");
client.println("        var data = google.visualization.arrayToDataTable([");
client.print("          ['Label', 'Value'],['Potmeter',");
client.print(val);
client.println("]");
client.println("          ");
client.println("          ");
client.println("        ]);");
client.println("");
client.println("        var options = {");
client.println("          width: 400, height: 120,");
client.println("          redFrom: 900, redTo: 1024,");
client.println("          yellowFrom:750, yellowTo: 900,");
client.println("          minorTicks: 5");
client.println("        };");
client.println("");
client.println("        var chart = new google.visualization.Gauge(document.getElementById('chart_div'));");
client.println("");
client.println("        chart.draw(data, options);");
client.println("");
client.println("        setInterval(function() {");
client.print("          data.setValue(0, 1, ");
client.print(val);
client.println(" ); ");
client.println("          chart.draw(data, options);");
client.println("        }, 1000);");
client.println("      ");
client.println("      }");
client.println("    </script>");
client.println("  </head>");
client.println("  <body>");
client.println("    <div id=\"chart_div\" style=\"width: 400px; height: 120px;\"></div>");
client.println("  </body>");
client.println("</html>");

          client.stop();
    
    
  }}
}}

  // put your main code here, to run repeatedly:
  
