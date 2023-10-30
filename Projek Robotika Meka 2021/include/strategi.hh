#ifndef STRATEGI_HH_
#define STRATEGI_HH_

const unsigned char speed_motor1 = 255;
const unsigned char speed_motor2 = 255;

class strategi {
  private:

  public:
   void StrategiInit();
   void RedTeam();
   void BlueTeam();
   void ManualMode();

};

#endif