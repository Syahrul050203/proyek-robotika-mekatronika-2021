#include <Arduino.h>
#include "strategi.hh"
#include "Servo.h"
#include "AFMotor.h"

#define SERVO1 10
#define SERVO2 9

Servo servo1;

AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);

void strategi::StrategiInit() {
  servo1.attach(SERVO1);

  motor1.setSpeed(speed_motor1);
  motor2.setSpeed(speed_motor2);
}

void strategi::ManualMode() {
  servo1.write(0);
  delay(1000);
  servo1.write(180);
  delay(1000);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(5000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void strategi::RedTeam() {

}

void strategi::BlueTeam() {

}