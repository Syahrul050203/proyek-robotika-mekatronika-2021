#include "Arduino.h"

float data_analog;

void setup() {
  Serial.begin(57600);
}

void loop() { 
  detectionBall();
  
  delay(500);
}

void detectionBall() {
  data_analog = analogRead(A0);

  Serial.println(data_analog);
  Serial.println(" ");

  if (data_analog < 130 && data_analog >= 100) 
    Serial.println("Bola Oren");
  else if (data_analog >= 130 && data_analog <= 160)
    Serial.println("Bola Putih");
  else
    Serial.println("Tidak Ada Bola") ;
}