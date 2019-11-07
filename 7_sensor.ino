#include <Wire.h>
#include <ESP8266WiFi.h>
#include "SSD1306.h"

SSD1306 display(0x3c, D1, D2);
int timer = 0;
const char* ssid = "FPT UGlobal";
const char* password = "123456789";
String ip;
const int trigPin = D3;
const int echoPin = D4;
long duration, cm, inches;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115520);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  display.init();
  Serial.print("Connecting to");

  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

  }
  Serial.println("");
  Serial.println("Wifi Connected");
  Serial.println("IP address");
  ip = WiFi.localIP().toString();
  Serial.println(ip);
  display.clear();

}

void loop() {
  //time counter//
  int hour, minute, second;
  delay(1000);
  timer++;
  hour = timer / 3600;
  minute = (timer % 3600) / 60;
  second = timer % 60;
  //ultrasonic//
   digitalWrite(trigPin, LOW);
   delayMicroseconds(5);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);

   // Convert the time into a distance//
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  Serial.print(inches);
  Serial.print("in,");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
}
