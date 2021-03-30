

#include <Arduino_JSON.h>

#include <Arduino.h>
//#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


#include <WebSocketsServer.h>
#include <Hash.h>





const char* ssid = "Your SSID";
const char* password = "Your Password.";

const unsigned short port = 3484;
 
//Một số biến dùng cho việc tạo một task
//unsigned long previousMillis = 0;
//long interval = 2000;
WebSocketsServer webSocket = WebSocketsServer(port);
ESP8266WebServer server(80);
//#define USE_SERIAL Serial1
void loop() {
  webSocket.loop();
  server.handleClient();
 
}