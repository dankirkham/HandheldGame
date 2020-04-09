#ifndef Brick_h
#define Brick_h

#include "Game.h"
#include "Input.h"
#include "Screen.h"

class Brick : public Game
{
public:
  static const int DELAY = 25; // ms
  static const int MAX_LENGTH = 100;

  Brick(Screen* screen, Input *input);
  void tick();
  int getDelay();
private:
  static const int BALL_DELAY = 4;
  static const int BRICK_ROWS = 4;

  Input *input;
  Screen *screen;
  void init();

  struct State {
    int ball_pos_x;
    int ball_pos_y;
    int ball_vel_x;
    int ball_vel_y;
    int paddle_x;
    int ball_timer;
    bool game_over;
    bool paused;
    bool bricks[BRICK_ROWS * COLUMNS] = { true };
  };

  Brick::State state;
};

#endif
