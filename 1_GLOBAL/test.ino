#include <Arduino.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFi.h>

#include <WebSocketsClient.h>
#include <SocketIOclient.h>

#include <Hash.h>




const char* ssid = "JERRY";
const char* password = "0copass.";
const char* host = "192.168.20.19";
const unsigned short port = 3484;
const char* url = "/";
const char* protocol = "arduino";
//extern String RID;
//extern String Rfull;
 
 
//Một số biến dùng cho việc tạo một task
unsigned long previousMillis = 0;
long interval = 2000;

 ESP8266WiFiMulti WiFiMulti;
WebSocketsClient webSocket;

#define USE_SERIAL Serial1

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {

  switch(type) {
    case WStype_DISCONNECTED:
      USE_SERIAL.printf("[WSc] Disconnected!\n");
      break;
    case WStype_CONNECTED: {
      USE_SERIAL.printf("[WSc] Connected to url: %s\n", payload);

      // send message to server when Connected
      webSocket.sendTXT("Connected");
    }
      break;
    case WStype_TEXT:
      USE_SERIAL.printf("[WSc] get text: %s\n", payload);

      // send message to server
      // webSocket.sendTXT("message here");
      break;
    case WStype_BIN:
      USE_SERIAL.printf("[WSc] get binary length: %u\n", length);
      hexdump(payload, length);

      // send data to server
      // webSocket.sendBIN(payload, length);
      break;
        case WStype_PING:
            // pong will be send automatically
            USE_SERIAL.printf("[WSc] get ping\n");
            break;
        case WStype_PONG:
            // answer to a ping we send
            USE_SERIAL.printf("[WSc] get pong\n");
            break;
    }

}

void setup() {
  // USE_SERIAL.begin(921600);
  Serial.begin(115200);

  //Serial.setDebugOutput(true);
  Serial.setDebugOutput(true);
Serial.println("ESP8266 Websocket Client");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to ");
  Serial.println(ssid);


  for(uint8_t t = 4; t > 0; t--) {
    USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);
  }

  // server address, port and URL
  webSocket.begin(host,port,url);

  // event handler
  webSocket.onEvent(webSocketEvent);

  // use HTTP Basic Authorization this is optional remove if not needed
  //webSocket.setAuthorization("user", "Password");//don't need now

  // try ever 5000 again if connection has failed
  webSocket.setReconnectInterval(5000);
  
  // start heartbeat (optional)
  // ping server every 15000 ms
  // expect pong from server within 3000 ms
  // consider connection disconnected if pong is not received 2 times
  webSocket.enableHeartbeat(15000, 3000, 2);

}

void loop() {

  webSocket.loop();
}