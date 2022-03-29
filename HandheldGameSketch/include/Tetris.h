#ifndef Tetris_h
#define Tetris_h

#include "Game.h"
#include "Games.h"
#include "Input.h"
#include "ProgMem.h"
#include "Screen.h"

#define X true
#define _ false

namespace tetris {
const int BLOCK_HEIGHT = 2;
const int BLOCK_WIDTH = 4;

const char I[BLOCK_WIDTH * BLOCK_HEIGHT] PROGMEM = {
  _, _, _, _,
  X, X, X, X
};

const char O[BLOCK_WIDTH * BLOCK_HEIGHT] PROGMEM = {
  _, X, X, _,
  _, X, X, _
};

const char T[BLOCK_WIDTH * BLOCK_HEIGHT] PROGMEM = {
  _, X, _, _,
  X, X, X, _
};

const char S[BLOCK_WIDTH * BLOCK_HEIGHT] PROGMEM = {
  _, X, X, _,
  X, X, _, _
};

const char Z[BLOCK_WIDTH * BLOCK_HEIGHT] PROGMEM = {
  X, X, _, _,
  _, X, X, _
};

const char J[BLOCK_WIDTH * BLOCK_HEIGHT] PROGMEM = {
  X, _, _, _,
  X, X, X, _
};

const char L[BLOCK_WIDTH * BLOCK_HEIGHT] PROGMEM = {
  _, _, X, _,
  X, X, X, _
};

} // tetris

enum class block_e : char {
  I = 0,
  O = 1,
  T = 2,
  S = 3,
  Z = 4,
  J = 5,
  L = 6,
  total_blocks = 7
};

PGM_P const BLOCKS[(int)block_e::total_blocks] PROGMEM = {
  tetris::I,
  tetris::O,
  tetris::T,
  tetris::S,
  tetris::Z,
  tetris::J,
  tetris::L
};

enum class action_e {
  can_move,
  freeze,
  draw
};

class Tetris : public Game
{
public:
  static const int DELAY = 33; // ms
  static const int MAX_LENGTH = 100;
  static const int MOVE_COUNTER = 3;

  Tetris(Screen* screen, Input *input);
  void tick();
  int getDelay();

private:
  Input *input;
  Screen *screen;
  void init();
  bool withBlock(action_e, unsigned char, char, char);
  void spawnBlock();

  struct State {
    bool game_over;
    bool paused;
    char block[8];
    unsigned int move_counter;
    unsigned char rotation;
    char x;
    char y;
    unsigned char placed_blocks[COLUMNS * ROWS];
  };

  Tetris::State state;
};

#endif
