#ifndef Birb_h
#define Birb_h

#include "Game.h"
#include "Games.h"
#include "Input.h"
#include "Screen.h"

class Birb : public Game
{
public:
  static const int DELAY = 100; // ms
  static const int MAX_LENGTH = 100;

  Birb(Screen* screen, Input *input);
  void tick();
  int getDelay();

private:
  Input *input;
  Screen *screen;
  void init();

  struct State {
    short birb_y;
    short birb_vy;
    short accel_ticks;
    bool game_over;
    bool paused;
    short next_gate;
    short gate_x[3];
    short gate_y[3];
  };

  Birb::State state;
};

#endif
