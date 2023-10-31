#ifndef SENSOR_HH_
#define SENSOR_HH_

int a ;
class sensor {
private:
  float dataColor_;
  
public:
  unsigned char pin;

  char BallDetection();

  unsigned char LineDetection();
};

#endif