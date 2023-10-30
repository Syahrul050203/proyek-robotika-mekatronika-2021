#ifndef SENSOR_HH_
#define SENSOR_HH_

class sensor {
private:
  float dataColor_;
  
public:
  unsigned char pin;

  char BallDetection();
};

#endif