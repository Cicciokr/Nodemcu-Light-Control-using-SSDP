#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266SSDP.h>

const char* ssid = "Vodafone2.4GHz-Ciccio";
const char* password = "Cicciokr89";

int pinRelay = 14;
int relayState = HIGH;
ESP8266WebServer HTTP(80);

void setup() {
  Serial.begin(115200);

  // prepare GPI14
  pinMode(pinRelay, OUTPUT);
  
  Serial.println();
  Serial.println("Starting WiFi...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if(WiFi.waitForConnectResult() == WL_CONNECTED){

    Serial.printf("Starting HTTP...\n");
    HTTP.on("/index.html", HTTP_GET, [](){
      HTTP.send(200, "text/plain", "Hello World!");
    });
    HTTP.on("/description.xml", HTTP_GET, [](){
      SSDP.schema(HTTP.client());
    });

    HTTP.on("/OFF", HTTP_GET, [](){
      digitalWrite(pinRelay, HIGH);
      relayState = HIGH;
      int valR = digitalRead(pinRelay); 
      String sR = (valR)?"OFF":"ON";
      String message = "";
      message += "{ \"status\": \"";
      message += sR;
      message += "\"}";
      HTTP.send(200, "text/plain", message);
    });
    HTTP.on("/ON", HTTP_GET, [](){
      digitalWrite(pinRelay, LOW);
      relayState = LOW;
      int valR = digitalRead(pinRelay); 
      String sR = (valR)?"OFF":"ON";
      String message = "";
      message += "{ \"status\": \"";
      message += sR;
      message += "\"}";
      HTTP.send(200, "text/plain", message);
    });
    HTTP.on("/STATUS", HTTP_GET, [](){
      int valR = digitalRead(pinRelay); 
      String sR = (valR)?"OFF":"ON";
      String message = "";
      message += "{ \"status\": \"";
      message += sR;
      message += "\"}";
      HTTP.send(200, "text/plain", message);
    });
    HTTP.begin();

    Serial.printf("Starting SSDP...\n");
    SSDP.setSchemaURL("description.xml");
    SSDP.setHTTPPort(80);
    SSDP.setName("NodemcuLightOne");
    SSDP.setSerialNumber("0001");
    SSDP.setURL("index.html");
    SSDP.setModelName("nodemcu");
    SSDP.setModelNumber("0001");
    SSDP.setManufacturer("Cicciokr");
    SSDP.setDeviceType("upnp:nodemculight");
    SSDP.begin();

    Serial.printf("Ready!\n");
  } else {
    Serial.printf("WiFi Failed\n");
    while(1) delay(100);
  }
}

void loop() {
  HTTP.handleClient();
  delay(1);
}
