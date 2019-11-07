#include <Wire.h>
//#include <ESP8266WiFi.h>
//#include "SSD1306.h"

const int trigPin1 = 5;
const int echoPin1 = 6;
const int trigPin2 = 3;
const int echoPin2 = 4;
const int trigPin3 = 7;
const int echoPin3 = 8;
const int trigPin4 = 9;
const int echoPin4 = 10;
long duration1, cm1, inches1;
long duration2, cm2, inches2;
long duration3, cm3, inches3;
long duration4, cm4, inches4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115520);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin4, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin4, INPUT); // Sets the echoPin as an Input
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
      //ultrasonic 3//
   digitalWrite(trigPin3, LOW);
   delayMicroseconds(5);
   digitalWrite(trigPin3, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin3, LOW);
   pinMode(echoPin3, INPUT);
   duration3 = pulseIn(echoPin3, HIGH);
        //ultrasonic 4//
   digitalWrite(trigPin4, LOW);
   delayMicroseconds(5);
   digitalWrite(trigPin4, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin4, LOW);
   pinMode(echoPin4, INPUT);
   duration4 = pulseIn(echoPin4, HIGH);
  
  
   // Convert the time into a distance//
  cm1 = (duration1/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches1= (duration1/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  cm2 = (duration2/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches2 = (duration2/2) / 74;   // Divide by 74 or multiply by 0.0135
  cm3 = (duration3/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches3 = (duration3/2) / 74;   // Divide by 74 or multiply by 0.0135
    cm4 = (duration4/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches4 = (duration4/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  //serial output//
  Serial.print("Sensor 1");
  Serial.println();
 // Serial.print("in, ");
 // Serial.print(inches1);
  Serial.print(cm1);
  Serial.print("cm");
  delay(100);
  Serial.println();
  Serial.print("Sensor 2");
  Serial.println();
 // Serial.print(inches2); 
//  Serial.print("in, ");
  Serial.print(cm2);
  Serial.print("cm");
  Serial.println();
  delay(100);
  Serial.println();
  Serial.print("Sensor 3");
  Serial.println();
  Serial.print(cm3);
  Serial.print("cm");
  Serial.println();
  delay(100);
   Serial.println();
  Serial.print("Sensor 4");
  Serial.println();
  Serial.print(cm4);
  Serial.print("cm");
  Serial.println();
  delay(100);
}
