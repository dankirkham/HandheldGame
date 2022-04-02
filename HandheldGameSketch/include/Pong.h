#ifndef Pong_h
#define Pong_h

#include "Game.h"
#include "Games.h"
#include "Input.h"
#include "Screen.h"

class Pong : public Game
{
public:
  static const int DELAY = 50; // ms

  Pong(Screen* screen, Input *input);
  void tick();
  int getDelay();

private:
  Input *input;
  Screen *screen;
  void init();

  struct State {
    bool game_over;
    bool paused;
    char l_y;
    char r_y;
    char ball_x;
    char ball_y;
    char vel_x;
    char vel_y;
  };

  Pong::State state;
};

#endif
