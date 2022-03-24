#ifndef Menu_h
#define Menu_h

#include "Game.h"
#include "Games.h"
#include "Input.h"
#include "Screen.h"

struct MenuItem {
  char* text;
  short len;
};

const MenuItem menu_items[] = {
  { .text="SNEK\0", .len=4 },
  { .text="BRICK\0", .len=5 },
  { .text="BIRB\0", .len=4 },
  { .text="COUNTER\0", .len=7 },
//  { .text="TETRIS\0", .len=6 },
//  { .text="DRAW\0", .len=4 },
//  { .text="REALLY LONG TEXT LOL\0", .len=20 },
};

class Menu : public Game
{
public:
  static const int DELAY = 25; // ms

  Menu(Screen* screen, Input *input);
  void tick();
  int getDelay();
private:
  Input *input;
  Screen *screen;
  void init();

  enum class Direction {
    RIGHT,
    LEFT
  };

  struct State {
    short initial_delay;
    short x;
    Direction direction;
    short selection;
  };

  Menu::State state;
};

#endif
