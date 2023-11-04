#include <Arduino.h>
#include "strategi.hh"
#include "sensor.hh"
#include "Servo.h"
#include "AFMotor.h"
#include "PS2X_lib.h"

#define SERVO1 10
#define SERVO2 9

sensor sens;
Servo servo1;

AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);

PS2X joyStick;

void strategi::StrategiInit() {
  servo1.attach(SERVO1);

  motor1.setSpeed(speed_motor1);
  motor2.setSpeed(speed_motor2);

  for (unsigned char i = 46; i <= 53; i++) {
    pinMode(i, INPUT);
  }

  sens.error_joy = joyStick.config_gamepad(25, 23, 24, 22, true, true);
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

void strategi::DebugJoy(int err) {
  switch (err) {
   case 0:
     Serial.println("Joystick tidak ada");
     break;
   case 1:
     Serial.println("Joystick ready tapi tidak menerima perintah");
     break; 
   case 2:
     Serial.println("Joystick menolak memasuki mode Tekanan");
     break;
  }
}

void strategi::RunJoy() {
  joyStick.read_gamepad(false, 0);
  unsigned char value_ry = joyStick.Analog(PSS_RY) ^ 255;
  unsigned char value_rx = joyStick.Analog(PSS_RX);

  // if (sens.error_joy == 1) 
  //   return;

  
  if (value_ry > 127) 
    Maju(value_ry);
  else if (value_ry < 127) 
    Mundur(value_ry ^ 255);
  else if (value_rx > 128) 
    BelokKanan(255 - value_rx, value_rx);
  else if (value_rx < 128)
    BelokKiri(value_rx ^ 255, 255 - (value_rx ^ 255));
  else 
    Maju(0);
  
  Serial.println(sens.error_joy);
  Serial.println(value_rx);

}