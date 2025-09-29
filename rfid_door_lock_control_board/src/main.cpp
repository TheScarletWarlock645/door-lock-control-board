#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include <LittleFS.h>

const char* ssid = "SSID"; //replace SSID with the proper SSID
const char* passwd = "PASSWD"; // replace PASSWD with the propper password

AsyncWebServer server(80);

IPAddress local_ip(192,168,0,200);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,0,0);

void setup() {
  Serial.begin(115200);
  
  if (!WiFi.config(local_ip, gateway, subnet)) {
      Serial.println("ERROR: WiFi failed to configure!");
    }

  WiFi.begin(ssid, passwd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFI!");
  Serial.println("IP addr: " + WiFi.localIP());

  if (!LittleFS.begin()) {
    Serial.println("ERROR: There was an error mounting LittleFS file system!");
    return;

  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}