#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char* ssid = "Sabar";
const char* password = "eephrs3h";
ESP8266WebServer server(80);
int ledPin = 2;
bool ledStatus = HIGH;

void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi terhubung ");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  //
  Serial.print("Starting Webserver on IP" +WiFi.localIP().toString());
  server.on("/", handleWebServer);
  server.on("/ledOff", handleLedOff);
  server.on("/ledOn", handleLedOn);
  server.begin();
  Serial.println("...");
  
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,ledStatus);
  
}

void loop() {
  server.handleClient();
}

void handleWebServer(){
  String statusLed = "ON";
  String statusColor = "<h1 style='color: green;' align='center'>ON</h1>"; 

  //
  String btn = "<button class='buttonred' onclick=\"location.href = '/ledOff'\">Turn Off</button>";
  if(ledStatus==0){
    statusLed = "OFF";
    btn = "<button class='button'onclick=\"location.href = '/ledOn'\">Turn On</button>";
    statusColor = "<h1 style='color: red;' align='center'>OFF</h1>";   
  }

  String clientIP = server.client().remoteIP().toString();
  String strWebServer = R"===(
    <!DOCTYPE html>
    <html lang ="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content "IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Idupin Lampu</title>
        <style>
          .button {
           background-color: #4CAF50;
           border: none;
           color: white;
           padding: 15px 32px;
           text-align: center;
           text-decoration: none;
           display: inline-block;
           font-size: 20px;
           margin: 4px 2px;
           cursor: pointer;
          }

          .buttonred {
           background-color: #FF0000;
           border: none;
           color: white;
           padding: 15px 32px;
           text-align: center;
           text-decoration: none;
           display: inline-block;
           font-size: 20px;
           margin: 4px 2px;
           cursor: pointer;
          }
      </style>
    </head>
    <body>
        <p align="center">
         <h1 align="center">The Lamp is </h1>
         )==="+ statusColor + R"===(
        </p>
        <hr style="height:2px;border-width:0;color:gray;background-color:gray">
        <p align="center">
         )==="+ btn + R"===(
        </p>
     )===";
    server.send(200, "text/html", strWebServer);
}

void handleLedOff(){
  ledStatus = 0;
  digitalWrite(ledPin, ledStatus);
  server.sendHeader("Location", String("/"), true);
  server.send(302, "text/plain", "");
}

void handleLedOn(){
  ledStatus = 1;
  digitalWrite(ledPin, ledStatus);
  server.sendHeader("Location", String("/"), true);
  server.send(302, "text/plain", "");
}