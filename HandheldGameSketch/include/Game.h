#ifndef Game_h
#define Game_h

//#include "Arduino.h"

class Game
{
public:
  virtual int getDelay() = 0;
  virtual void init() = 0;
  virtual void tick() = 0;
};

#endif
