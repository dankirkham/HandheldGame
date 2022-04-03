#ifndef Quest_h
#define Quest_h

#include "Game.h"
#include "Games.h"
#include "Input.h"
#include "Screen.h"
#include "Pins.h"
#include "ProgMem.h"
#include "Constants.h"

#define MAP_ROWS 2
#define MAP_COLUMNS 2

namespace quest {

constexpr char _ = 0;
constexpr char X = 1;
constexpr char k = 2;
constexpr char s = 3;
constexpr char d = 4;
constexpr char f = 5;

const char area_0_0[ROWS * COLUMNS] PROGMEM = {
  X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, s, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, X, X, X, X, X, X, _, X, X, X, X, X, X, X, X
};

const char area_0_1[ROWS * COLUMNS] PROGMEM = {
  X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
  _, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, X, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, X, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, X, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, X, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, X, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, X, _, _, _, _, X,
  X, X, X, _, X, X, X, X, _, X, X, X, _, X, X, X
};

const char area_1_0[ROWS * COLUMNS] PROGMEM = {
  X, X, X, X, X, X, X, _, X, X, X, X, X, X, X, X,
  X, _, _, _, _, _, _, _, X, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, X, _, _, _, k, _, _, X,
  X, _, _, _, _, _, _, _, X, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, X, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, X, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, X, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, X, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X
};

const char area_1_1[ROWS * COLUMNS] PROGMEM = {
  X, X, X, _, X, X, X, X, _, X, X, X, _, X, X, X,
  X, _, _, _, _, _, X, _, _, _, X, _, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, X, _, _, _, _, X,
  X, X, X, X, X, _, X, _, _, _, X, _, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, X, _, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, X, _, _, X, X, X,
  X, _, X, X, X, X, X, _, _, _, X, _, _, _, d, f,
  X, _, _, _, _, _, _, _, _, _, X, _, _, X, X, X,
  X, _, _, _, _, _, _, _, _, _, X, _, _, _, _, X,
  X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X
};

} // quest

PGM_P const level_0[MAP_ROWS * MAP_COLUMNS] PROGMEM = {
  quest::area_0_0,
  quest::area_0_1,
  quest::area_1_0,
  quest::area_1_1
};

class Quest : public Game
{
public:
  static const int DELAY = 50; // ms

  Quest(Screen* screen, Input *input);
  void tick();
  int getDelay();

private:
  Input *input;
  Screen *screen;
  void init();

  struct State {
    bool game_over;
    bool paused;

    char map_x;
    char map_y;
    char level[ROWS*COLUMNS];

    // Player
    char x;
    char y;
    char keys;
  };

  Quest::State state;

private:
  void loadLevel(bool start);
  char getCell(int, int);
};

#endif
