#ifndef STRATEGI_HH_
#define STRATEGI_HH_

class strategi {
  private:

  public:
   void StrategiInit();
   void RedTeam();
   void BlueTeam();
   void ManualMode();
   void Maju(unsigned char vel);
   void Mundur(unsigned char vel);
   void BelokKanan(unsigned char vel_r, unsigned  char vel_l);
   void BelokKiri(unsigned char vel_r, unsigned  char vel_l);

   void DebugJoy(int err);
   void RunJoy();

};

#endif