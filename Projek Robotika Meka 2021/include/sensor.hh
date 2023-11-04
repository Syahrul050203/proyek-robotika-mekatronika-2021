#ifndef SENSOR_HH_
#define SENSOR_HH_

class sensor {
private:
  float dataColor_;
  
public:
  int error_joy = 0;

  unsigned char pin;

  char BallDetection();

  unsigned char LineDetection();
};

#endif