#ifndef Game_h
#define Game_h

//#include "Arduino.h"

class Game
{
  public:
    virtual int getDelay();
    virtual void init();
    virtual void tick();
};

#endif
