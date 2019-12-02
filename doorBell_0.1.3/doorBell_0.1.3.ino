#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "SSID_WiFi"
#define STAPSK  "Password_WiFi"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

const char* host = "djxmmx.net";
const uint16_t port = 17;

const int buttonPin = D0;
const int buzzerPin = D8;

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("IP Size: ");
  Serial.println(sizeof(WiFi.localIP()));

  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  doorBell();
}
