#ifndef Menu_h
#define Menu_h

#include "ProgMem.h"
#include "Game.h"
#include "Games.h"

#include "Input.h"
#include "Screen.h"

const char string_1[] PROGMEM = "SNEK";
const char string_2[] PROGMEM = "BRICK";
const char string_3[] PROGMEM = "BIRB";
const char string_4[] PROGMEM = "TETRIS";
const char string_5[] PROGMEM = "DEBUG";

PGM_P const menu_items[] PROGMEM = {
  string_1,
  string_2,
  string_3,
  string_4,
  string_5
};

class Menu : public Game
{
public:
  static const int DELAY = 50; // ms

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
    char menu_item[10];
  };

  Menu::State state;
};

#endif
