#ifndef Game_h
#define Game_h

#include "Games.h"

class Game
{
public:
  ~Game();
  virtual int getDelay() = 0;
  virtual void init() = 0;
  virtual void tick() = 0;
  games_e getGameToSwitchTo();

protected:
  games_e gameToSwitchTo;
};

#endif
