#include "Game.h"
#include "Quest.h"
#include "Screen.h"
#include "Pins.h"
#include "Random.h"

#define PADDLE_HEIGHT 3

Quest::Quest(Screen* screen, Input* input) {
  this->screen = screen;
  this->input = input;
  this->init();
}

int Quest::getDelay() {
  return Quest::DELAY;
}

void Quest::init() {
  state.game_over = false;
  state.paused = false;
  state.map_x = 0;
  state.map_y = 0;
  state.x = 0;
  state.y = 0;
  state.keys = 0;

  loadEntities();
  loadLevel(true);
}

void Quest::tick() {
  if (input->keyDown(button_e::start) && input->keyDown(button_e::select)) {
    this->gameToSwitchTo = games_e::MENU;
  } else if (input->keyDown(button_e::select)) {
    this->init();
  } else if (input->keyDown(button_e::start)) {
    state.paused = !state.paused;
  } else if (!state.game_over && !state.paused) {
    char new_x = state.x;
    char new_y = state.y;
    bool move_valid = false;

    if (input->keyHeld(button_e::left)) {
      new_x = state.x - 1;
    } else if (input->keyHeld(button_e::up)) {
      new_y = state.y - 1;
    } else if (input->keyHeld(button_e::right)) {
      new_x = state.x + 1;
    } else if (input->keyHeld(button_e::down)) {
      new_y = state.y + 1;
    }

    // Moving off the map?
    if (new_x < 0) {
      if (state.map_x > 0) {
        state.x = COLUMNS - 1;
        state.map_x--;
        loadLevel(false);
      }
    } else if (new_x >= COLUMNS) {
      if (state.map_x < MAP_COLUMNS - 1) {
        state.x = 0;
        state.map_x++;
        loadLevel(false);
      }
    } else if (new_y < 0) {
      if (state.map_y > 0) {
        state.y = ROWS - 1;
        state.map_y--;
        loadLevel(false);
      }
    } else if (new_y >= ROWS) {
      if (state.map_y < MAP_ROWS - 1) {
        state.y = 0;
        state.map_y++;
        loadLevel(false);
      }
    } else { // Staying on the map
      auto cell = getCell(new_x, new_y);
      switch (cell) {
        case quest::X:
          break;

        case quest::f:
          state.game_over = true;
          move_valid = true;
          break;

        case quest::s:
        case quest::_:
          move_valid = true;
          break;

        // A key or door
        default:
          if (state.entities[cell - 1] == quest::d) {
            if (state.keys > 0) {
              state.keys--;
              move_valid = true;
              state.entities[cell - 1] = quest::_;
            }
          } else if (state.entities[cell - 1] == quest::k) {
            state.keys++;
            move_valid = true;
            state.entities[cell - 1] = quest::_;
          } else if (state.entities[cell - 1] == quest::_) {
            move_valid = true;
          }
          break;
      }

      if (move_valid) {
        state.x = new_x;
        state.y = new_y;
      }
    }
  }

  screen->erase();

  for (int y = 0; y < ROWS; y++) {
    for (int x = 0; x < COLUMNS; x++) {
      auto cell = getCell(x, y);
      switch (cell) {
        case quest::X:
          screen->setPixel(x, y);
          break;
        case quest::s:
        case quest::f:
        case quest::_:
          break;

        default:
        // Check if the key has been picked up
          if (state.entities[cell - 1]) {
            screen->setPixel(x, y);
          }
          break;
      }
    }
  }

  // Draw player
  screen->setPixel(state.x, state.y);
}

void Quest::loadEntities() {
  memcpy_P(
    state.entities,
    (PGM_P)pgm_read_word(&entities_0),
    ENTITY_COUNT
  );
}

void Quest::loadLevel(bool start) {
  memcpy_P(
    state.level,
    (PGM_P)pgm_read_word(&(level_0[state.map_y * MAP_COLUMNS + state.map_x])),
    ROWS * COLUMNS
  );

  // Find start pos
  for (int y = 0; y < ROWS; y++) {
    for (int x = 0; x < COLUMNS; x++) {
      auto cell = getCell(x, y);
      switch (cell) {
        case quest::s:
          if (start) {
            state.x = x;
            state.y = y;
          }
          break;
        case quest::f:
        case quest::X:
        case quest::_:
        default:
          break;
      }
    }
  }
}

char Quest::getCell(int x, int y) {
  return state.level[y * COLUMNS + x];
}
