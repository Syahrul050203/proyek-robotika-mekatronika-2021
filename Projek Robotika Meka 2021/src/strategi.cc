#include <Arduino.h>
#include "strategi.hh"
#include "sensor.hh"
#include "Servo.h"
#include "AFMotor.h"

#define SERVO1 10
#define SERVO2 9

sensor sens;
Servo servo1;

AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);

void strategi::StrategiInit() {
  servo1.attach(SERVO1);

  motor1.setSpeed(speed_motor1);
  motor2.setSpeed(speed_motor2);

  for (unsigned char i = 46; i <= 53; i++) {
    pinMode(i, INPUT);
  }
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

void strategi::Maju(unsigned char vel) {
  motor1.setSpeed(vel);
  motor2.setSpeed(vel);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void strategi::Mundur(unsigned char vel) {
  motor1.setSpeed(vel);
  motor2.setSpeed(vel);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void strategi::BelokKanan(unsigned char vel_r, unsigned  char vel_l) {
  motor1.setSpeed(vel_r);
  motor2.setSpeed(vel_l);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void strategi::BelokKiri(unsigned char vel_r, unsigned  char vel_l) {
  motor1.setSpeed(vel_r);
  motor2.setSpeed(vel_l);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
}