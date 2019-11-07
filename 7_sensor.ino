#include <Wire.h>
#include <ESP8266WiFi.h>
#include "SSD1306.h"

SSD1306 display(0x3c, D1, D2);
int timer = 0;
const char* ssid = "FPT UGlobal";
const char* password = "123456789";
String ip;
const int trigPin1 = D1;
const int echoPin1 = D2;
const int trigPin2 = D3;
const int echoPin2 = D4;
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
  //ultrasonic 1//
   digitalWrite(trigPin1, LOW);
   delayMicroseconds(5);
   digitalWrite(trigPin1, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin1, LOW);
   pinMode(echoPin1, INPUT);
   duration1 = pulseIn(echoPin1, HIGH);
   //ultrasonic 2//
   digitalWrite(trigPin2, LOW);
   delayMicroseconds(5);
   digitalWrite(trigPin2, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin2, LOW);
   pinMode(echoPin2, INPUT);
   duration2 = pulseIn(echoPin2, HIGH);
  
  
  
  

   // Convert the time into a distance//
  s1cm = (duration1/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  s1inches = (duration1/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  s2cm = (duration2/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  s2inches = (duration2/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  //serial output//
  Serial.print(s1inches);
  Serial.print("in,");
  Serial.print(s1cm);
  Serial.print("cm");
  Serial.println();
  Serial.print(s2inches);
  Serial.print("in,");
  Serial.print(s2cm);
  Serial.print("cm");
  Serial.println();
}
