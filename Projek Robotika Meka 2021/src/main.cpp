#include "Arduino.h"
#include "sensor.hh"
#include "strategi.hh"

sensor sens;
strategi competiton;

void setup() {
  Serial.begin(57600);

  competiton.StrategiInit();
}

void loop() { 
  // sens.BallDetection();
  // competiton.ManualMode();
  sens.LineDetection();
}
