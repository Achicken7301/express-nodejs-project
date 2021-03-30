void setup() {
  Serial.begin(115200);
  //Serial.setDebugOutput(true);
  Serial.setDebugOutput(true);
  Serial.println("ESP8266 Websocket Server");
  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
  Serial.println("Connected to ");
  Serial.println(ssid);


  for(uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }
  // start a server
  
  server.begin();
  Serial.println("Server started");
    // handle index
    server.on("/", []() {
        // send index.html
        server.send(200, "text/html", INDEX_HTML);
        });
  webSocket.begin();
  // event handler
  webSocket.onEvent(webSocketEvent);
}