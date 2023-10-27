#include "Arduino.h"
#include "Servo.h"
#include "AFMotor.h"

#define SERVO1 10
#define SERVO2 9

const unsigned char speed_motor1 = 255;
const unsigned char speed_motor2 = 255;

Servo servo1;

AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);

float data_analog;

void setup() {
  Serial.begin(57600);

  servo1.attach(SERVO1);
  
  motor1.setSpeed(speed_motor1);
  motor2.setSpeed(speed_motor2);
}

void loop() { 
  detectionBall();

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

void detectionBall() {
  data_analog = analogRead(A0);

  Serial.println(data_analog);
  Serial.println(" ");

  if (data_analog < 130 && data_analog >= 100) 
    Serial.println("Bola Oren");
  else if (data_analog >= 130 && data_analog <= 160)
    Serial.println("Bola Putih");
  else
    Serial.println("Tidak Ada Bola") ;
}