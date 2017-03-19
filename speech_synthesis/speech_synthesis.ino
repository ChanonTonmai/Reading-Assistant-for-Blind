#include <SPI.h>
#include <Ethernet.h>
#include "SpeechSynthesis.h"

char c;
char a[100];
bool in = 1;
int i = 0;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192, 168, 11, 52 }; //assigned arduino LAN IP address
byte server[] = { 192, 168, 11, 54 }; // laptop running apache LAN IP address
EthernetClient client; //apache web server running on port 80

void setup()
{
 Ethernet.begin(mac, ip);
 Serial.begin(9600);
 Serial.println("starting simple arduino client test");
 Serial.println();

 delay(1000);

 Serial.println("connecting...");

 if (client.connect(server,5000)) {
   Serial.println("connected");
   client.println("GET / HTTP/1.0"); //php page invoking my web service
   client.println();
 } else {
   Serial.println("connection failed");
 }
}

byte ssr[500];//define a character string

void loop()
{
  if (in == 1) {
    if (client.available()) {
      i = i+1;
    }
  for (int j=0; j <= i; j++){
      c = client.read();
      a[j] = c;
      Serial.println(a[j]);
    }
      Serial.println(a);

  if (!client.connected()) {
     Serial.println();
     Serial.println("disconnecting.");
     Serial.println("==================================");
     Serial.println("");
     client.stop();
     in = 0;
     Serial.println(in);
    }
  } 
  
  if (in == 0) {
    Serial.println(in);
    Serial.println(a);
    SpeechSynthesis.buf_init(ssr);
    SpeechSynthesis.English(ssr,4,"5");
    SpeechSynthesis.English(ssr,6,a);
    SpeechSynthesis.Espeaking(0,19,4,ssr);
    while(true);
  }
}
