#ifndef Snek_h
#define Snek_h

#include "Game.h"
#include "Games.h"
#include "Input.h"
#include "Screen.h"

class Snek : public Game
{
public:
  static const int DELAY = 100; // ms
  static const int MAX_LENGTH = 16;

  Snek(Screen* screen, Input *input);
  void tick();
  int getDelay();

private:
  Input *input;
  Screen *screen;
  void init();

  enum class Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
  };

  struct State {
    short len;
    short food_x;
    short food_y;
    short body_x[Snek::MAX_LENGTH];
    short body_y[Snek::MAX_LENGTH];
    Snek::Direction dir;
    bool game_over;
    bool paused;
  };

  Snek::State state;
};

#endif
