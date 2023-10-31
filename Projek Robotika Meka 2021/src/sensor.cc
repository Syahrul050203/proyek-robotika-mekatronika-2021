#include <Arduino.h>
#include "sensor.hh"

char sensor::BallDetection() {
   dataColor_ = analogRead(A7);
   Serial.println(dataColor_);

   if (dataColor_ < 130 && dataColor_ >= 100) {
    return 'O';
   }
   else if (dataColor_ >= 130 && dataColor_ <= 160) {
    return 'P';
   }
   else {
    return 'N';
   }
   
}

unsigned char sensor::LineDetection() {
   unsigned char result = 0;
   bool line_1 = digitalRead(51);
   bool line_2 = digitalRead(50);
   bool line_3 = digitalRead(49);
   bool line_4 = digitalRead(48);
   bool line_5 = digitalRead(47);
   bool line_6 = digitalRead(46);

   Serial.print(line_6); Serial.print(" ");
   Serial.print(line_5); Serial.print(" ");
   Serial.print(line_4); Serial.print(" ");
   Serial.print(line_3); Serial.print(" ");
   Serial.print(line_2); Serial.print(" ");
   Serial.print(line_1); Serial.print(" ");
   Serial.println(" "); Serial.println(" ");

   return result;
}