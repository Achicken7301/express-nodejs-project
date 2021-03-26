#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

String readString;
const char* ssid = "SSID";
const char* password = "Password";

const char* host = "script.google.com";
const int httpsPort = 443;

/*
AKfycbzBgMbEFAFvSGjHhjoY-WTutFOV06kx2aVNiX56BdEMtJLpi0RzWfHfm4bDllaxfYB-Qw
https://script.google.com/macros/s/AKfycbzBgMbEFAFvSGjHhjoY-WTutFOV06kx2aVNiX56BdEMtJLpi0RzWfHfm4bDllaxfYB-Qw/exec?value1=20&value2=30&value3=550
*/

WiFiClientSecure client;


const char* fingerprint = "46 B2 C3 44 9C 59 09 8B 01 B6 F8 BD 4C FB 00 74 91 2F EF F6";
String GAS_ID = "1V8IrFzVKb2IbDPLHfi5rsul3g-65jf3J-2kthBCuOw4";  // Replace by your GAS service id


void setup()
{

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  sendData(113, 125); // Send test data
}

void loop()
{
  int a, b;                      //a,b are variables to store sensor values
  a = 1;
  b = 1;
  sendData(a, b);              //This function uploads data to Google Sheets
}




void sendData(int x, int y)
{
  client.setInsecure();
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  if (client.verify(fingerprint, host)) {
    Serial.println("certificate matches");
  } else {
    Serial.println("certificate doesn't match");
  }
  String string_x     =  String(x, DEC);
  String string_y     =  String(y, DEC);
  String url = "/macros/s/" + GAS_ID + "/exec?Value1=" + string_x + "&Value2=" + string_y;
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
}