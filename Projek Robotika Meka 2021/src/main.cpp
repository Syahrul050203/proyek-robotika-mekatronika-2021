#include "Arduino.h"
#include "sensor.hh"
#include "strategi.hh"

sensor color;
strategi competiton;

void setup() {
  Serial.begin(57600);

  competiton.StrategiInit();
}

void loop() { 
  color.BallDetection();
  competiton.ManualMode();
}
