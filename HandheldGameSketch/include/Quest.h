#ifndef Quest_h
#define Quest_h

#include "Game.h"
#include "Games.h"
#include "Input.h"
#include "Screen.h"
#include "Pins.h"
#include "ProgMem.h"
#include "Constants.h"

#define MAP_ROWS 3
#define MAP_COLUMNS 3
#define ENTITY_COUNT 10

namespace quest {

constexpr char _ = 0;
constexpr char k = 123;
constexpr char X = 124;
constexpr char s = 125;
constexpr char d = 126;
constexpr char f = 127;

const char area_0_0[ROWS * COLUMNS] PROGMEM = {
  X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
  X, _, _, _, _, _, _, _, _, _, _, X, _, _, _, X,
  X, _, _, s, _, _, _, _, _, _, _, X, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, X, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, _, X, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, _, X, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, _, _, _, _, _, _,
  X, _, _, _, _, _, X, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, _, _, _, _, _, X,
  X, X, X, X, _, X, X, X, X, X, X, X, X, X, X, X
};

const char area_1_0[ROWS * COLUMNS] PROGMEM = {
  X, X, X, X, _, X, X, X, X, X, X, X, X, X, X, X,
  X, _, _, _, _, _, X, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, X, _, _, 1, _, _, _, _, _, _,
  X, _, _, _, _, _, X, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, _, 2, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, X, _, _, _, _, _, _, _, _, X,
  X, X, _, X, X, X, X, X, X, X, X, X, X, X, X, X
};

const char area_2_0[ROWS * COLUMNS] PROGMEM = {
  X, X, _, X, X, X, X, X, X, X, X, X, X, X, X, X,
  X, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, _, _, _, _, _, _,
  X, _, _, X, X, X, X, X, X, _, _, _, _, _, _, X,
  X, _, _, _, 5, _, _, 6, _, _, _, _, _, _, _, X,
  X, _, _, X, X, X, X, X, X, _, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X,
  X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X
};

const char area_0_1[ROWS * COLUMNS] PROGMEM = {
  X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, X, _, _, _, _, _, _, X, _, _, _, X,
  X, _, _, _, X, _, _, _, _, _, _, X, _, _, _, X,
  _, _, _, _, X, _, _, _, _, _, _, X, _, _, _, X,
  X, _, _, _, X, _, _, _, _, _, _, X, _, _, _, X,
  X, _, _, _, X, _, _, _, _, _, _, X, _, _, _, X,
  X, X, X, X, X, X, X, _, X, X, X, X, X, X, X, X
};

const char area_1_1[ROWS * COLUMNS] PROGMEM = {
  X, X, X, X, X, X, X, _, X, X, X, X, X, X, X, X,
  X, _, _, _, _, X, _, _, _, X, _, _, _, _, _, _,
  X, _, _, _, _, X, _, _, _, X, _, _, _, _, _, X,
  X, _, _, _, _, X, X, X, X, X, _, _, _, _, _, X,
  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X
};

const char area_2_1[ROWS * COLUMNS] PROGMEM = {
  X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
  X, _, _, _, _, _, X, _, _, _, _, _, _, _, _, X,
  X, _, _, 4, _, _, X, _, _, _, _, _, _, _, _, X,
  _, _, _, _, _, _, X, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, X, _, _, 3, _, _, _, _, _, _,
  X, _, _, _, _, _, X, _, _, _, _, _, _, _, _, X,
  X, _, X, _, X, _, X, _, _, _, _, _, _, _, _, X,
  X, _, X, 7, X, _, X, _, _, _, _, _, _, _, _, X,
  X, _, X, _, X, _, X, _, _, _, _, _, _, _, _, X,
  X, X, X, f, X, X, X, X, X, X, X, X, X, X, X, X
};

const char area_0_2[ROWS * COLUMNS] PROGMEM = {
  X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, _, _, _, _, _, X,
  X, X, X, X, X, X, X, X, X, X, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, X, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, X, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, X, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, X, _, _, _, _, _, X,
  X, X, _, X, X, X, X, _, X, X, X, X, X, _, X, X
};

const char area_1_2[ROWS * COLUMNS] PROGMEM = {
  X, X, _, X, X, X, X, _, X, X, X, X, X, _, X, X,
  _, _, _, _, _, X, _, _, _, X, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, X, _, _, _, _, _, X,
  X, X, X, X, X, X, _, _, _, X, X, X, _, _, _, X,
  X, _, _, _, _, _, _, _, _, _, 8, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, X, X, X, _, _, _, X,
  X, _, _, _, _, _, _, _, _, X, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, X, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, _, X, _, _, _, _, _, X,
  X, X, X, X, X, X, X, X, X, X, X, _, X, X, X, X
};

const char area_2_2[ROWS * COLUMNS] PROGMEM = {
  X, X, X, X, X, X, X, X, X, X, X, _, X, X, X, X,
  X, _, _, _, _, _, _, _, X, _, _, _, _, _, _, X,
  X, _, _, _, _, _, _, _, X, _, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, X, _, _, _, _, _, _, X,
  _, _, _, _, _, X, _, _, X, _, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, X, _, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, _, _, _, _, _, _, _, X,
  X, _, _, _, _, X, _, _, X, _, _, _, _, _, _, X,
  X, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X
};

} // quest

PGM_P const level_0[MAP_ROWS * MAP_COLUMNS] PROGMEM = {
  quest::area_0_0,
  quest::area_0_1,
  quest::area_0_2,
  quest::area_1_0,
  quest::area_1_1,
  quest::area_1_2,
  quest::area_2_0,
  quest::area_2_1,
  quest::area_2_2
};

const char entities_0[ENTITY_COUNT] PROGMEM = {
  quest::k,
  quest::k,
  quest::k,
  quest::k,
  quest::d,
  quest::d,
  quest::d,
  quest::d
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
    char entities[ENTITY_COUNT];

    // Player
    char x;
    char y;
    char keys;
  };

  Quest::State state;

private:
  void loadEntities();
  void loadLevel(bool start);
  char getCell(int, int);
};

#endif
