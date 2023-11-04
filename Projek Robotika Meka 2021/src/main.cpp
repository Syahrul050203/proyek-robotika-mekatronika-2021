#include "Arduino.h"
#include "strategi.hh"

strategi competiton;

void setup() {
  Serial.begin(57600);

  competiton.StrategiInit();
}

void loop() { 
  // competiton.ManualMode();
  sens.LineDetection();
}
