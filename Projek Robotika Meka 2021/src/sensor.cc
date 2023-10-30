#include <Arduino.h>
#include "sensor.hh"

char sensor::BallDetection() {
   dataColor_ = analogRead(A0);

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