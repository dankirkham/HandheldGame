#ifndef Counter_h
#define Counter_h

#include "Game.h"
#include "Games.h"
#include "Input.h"
#include "Screen.h"

class Counter : public Game
{
public:
  static const int DELAY = 100; // ms
  static const int MAX_LENGTH = 100;

  Counter(Screen* screen, Input *input);
  void tick();
  int getDelay();

private:
  Input *input;
  Screen *screen;
  void init();

  struct State {
    bool game_over;
    bool paused;
    char letter;
  };

  Counter::State state;
};

#endif
