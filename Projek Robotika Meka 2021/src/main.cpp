#include "Arduino.h"
#include "strategi.hh"

strategi competiton;

void setup() {
  Serial.begin(57600);

  competiton.StrategiInit();
}

void loop() { 
  if (!(digitalRead(16)) && !(digitalRead(17)))
    Serial.println("Init & calib");
  else if  (!(digitalRead(16)) && (digitalRead(17)))
    competiton.RedTeam();
  else if  ((digitalRead(16)) && !(digitalRead(17)))
    competiton.BlueTeam();
  else
    competiton.ManualMode();
}
