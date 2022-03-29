#include "Game.h"
#include "Tetris.h"
#include "Screen.h"
#include "Pins.h"
#include "Random.h"
#include "Font.h"

Tetris::Tetris(Screen* screen, Input* input) {
  this->screen = screen;
  this->input = input;
  this->init();
}

int Tetris::getDelay() {
  return Tetris::DELAY;
}

void Tetris::init() {
  state.game_over = false;
  state.paused = false;

  for (int i = 0; i < COLUMNS * ROWS; i++) {
    state.placed_blocks[i] = false;
  }

  spawnBlock();
}

bool Tetris::withBlock(
  action_e action,
  unsigned char new_rotation,
  char new_x,
  char new_y
  ) {
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 4; i++) {
      if (state.block[(j << 2) + i]) {
        int x, y;

        if (new_rotation == 0) {
          x = i + new_x;
          y = j + new_y;
        } else if (new_rotation == 1) {
          x = j + new_x;
          y = 2 - i + new_y;
        } else if (new_rotation == 2) {
          x = 2 - i + new_x;
          y = 2 - j + new_y;
        } else { // 3
          x = 2 - j + new_x;
          y = i + new_y;
        }

        if (action == action_e::can_move) {
          if (
            state.placed_blocks[y * COLUMNS + x] ||
            x < 0 ||
            y < 0 ||
            y >= ROWS
          ) return false;
        } else if (action == action_e::freeze) {
          if (x >= COLUMNS) return false; // Game Over!
          state.placed_blocks[y * COLUMNS + x] = true;
        } else { // action == action_e::draw
          if (x >= 0 && x < COLUMNS && y >= 0 && y < ROWS) screen->setPixel(x, y);
        }
      }
    }
  }

  return true;
}

void Tetris::spawnBlock() {
  auto block_type = (block_e)random(0, (int)block_e::total_blocks - 1);
  memcpy_P(state.block, (PGM_P)pgm_read_word(&(BLOCKS[(int)block_type])), 8);

  state.move_counter = Tetris::MOVE_COUNTER;
  state.rotation = 1;
  state.x = 15;
  state.y = 4;
}

void Tetris::tick() {
  bool new_block = false;

  if (input->keyDown(button_e::start) && input->keyDown(button_e::select)) {
    this->gameToSwitchTo = games_e::MENU;
  } else if (input->keyDown(button_e::select)) {
    this->init();
  } else if (input->keyDown(button_e::start)) {
    state.paused = !state.paused;
  } else if (!state.game_over && !state.paused) {
    unsigned int new_rotation = state.rotation;
    if (input->keyDown(button_e::a)) {
      new_rotation = state.rotation + 1;
      new_rotation &= 0x3;
      if (!withBlock(action_e::can_move, new_rotation, state.x, state.y)) {
        new_rotation = state.rotation;
      }
    } else if (input->keyDown(button_e::b)) {
      new_rotation = state.rotation - 1;
      new_rotation &= 0x3;
      if (!withBlock(action_e::can_move, new_rotation, state.x, state.y)) {
        new_rotation = state.rotation;
      }
    }
    state.rotation = new_rotation;


    unsigned int new_y = state.y;
    if (input->keyHeld(button_e::up)) {
      new_y = state.y - 1;
      if (!withBlock(action_e::can_move, state.rotation, state.x, new_y)) {
        new_y = state.y;
      }
    } else if (input->keyHeld(button_e::down)) {
      new_y = state.y + 1;
      if (!withBlock(action_e::can_move, state.rotation, state.x, new_y)) {
        new_y = state.y;
      }
    }
    state.y = new_y;

    unsigned int new_x = state.x;
    state.move_counter--;
    if (state.move_counter == 0 || input->keyHeld(button_e::left)) {
    //if (state.move_counter == 0) {
      state.move_counter = Tetris::MOVE_COUNTER;
      new_x = state.x - 1;

      if (withBlock(action_e::can_move, state.rotation, new_x, state.y)) {
        state.x = new_x;
      } else {
        if (!withBlock(action_e::freeze, state.rotation, state.x, state.y)) {
          state.game_over = true;
        } else {
          new_block = true;
        }
      }
    }

    // Check for completed rows
    if (new_block) {
      for (int x = 0; x < COLUMNS; x++) {
        bool empty_spot = false;
        for (int y = 0; y < ROWS; y++) {
          if (!state.placed_blocks[y * COLUMNS + x]) {
            empty_spot = true;
            break;
          }
        }

        if (!empty_spot) {
          // Move all the blocks
          for (int i = x + 1; i < COLUMNS; i++) {
            for (int y = 0; y < ROWS; y++) {
              state.placed_blocks[y * COLUMNS + i - 1] = state.placed_blocks[y * COLUMNS + i];
            }
          }
          for (int y = 0; y < ROWS; y++) {
            state.placed_blocks[y * COLUMNS + ROWS - 1] = 0;
          }

          x--; // The next column has shifted to the left, make sure not to skip it
        }
      }
    }
  }

  screen->erase();

  // Draw the block
  withBlock(action_e::draw, state.rotation, state.x, state.y);

  // Draw frozen blocks
  for (int y = 0; y < ROWS; y++) {
    for (int x = 0; x < COLUMNS; x++) {
      if (state.placed_blocks[y * COLUMNS + x]) screen->setPixel(x, y);
    }
  }

  if (new_block) spawnBlock();
}
