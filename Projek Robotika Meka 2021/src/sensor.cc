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

   bool sensor_line[6];

   for (unsigned char i = 0; i < 6; i++) {
      sensor_line[i] = digitalRead(46 + i);
      if (sensor_line[i])
         result |= (1<<(5-i));
      else
         result &= ~(1<<(5-i));
   }

   return result;
}