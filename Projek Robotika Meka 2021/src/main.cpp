#include "Arduino.h"

void setup() {
  Serial.begin(57600);
}

void loop() {
  float data_analog = analogRead(A0);
  unsigned char data_digital = digitalRead(7);
  
  Serial.println(data_analog);
  Serial.println(" ");

  if (data_analog < 130 && data_analog >= 100) 
    Serial.println("Bola Oren");
  else if (data_analog >= 130 && data_analog <= 160)
    Serial.println("Bola Putih");
  else
    Serial.println("Tidak Ada Bola") ;
  delay(500);
}