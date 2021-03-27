#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);
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
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  void setupBpm280();
}

void sendData(float x, float y);
void loop()
{
  int a, b;                      //a,b are variables to store sensor values
  temp = bmp.readTemperature();
  press = bmp.readPressure();
  sendData(a, b);              //This function uploads data to Google Sheets
}




