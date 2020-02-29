#include "Game.h"
#include "Snek.h"
#include "Pins.h"
#include "Screen.h"
#include "Arduino.h"

Snek::Snek(Screen* screen, Input* input) {
  this->screen = screen;
  this->input = input;
  this->init();
}

void Snek::init() {
  // Init the snek
  state.dir = RIGHT;
  state.len = 3;
  state.body_x[0] = 5;
  state.body_y[0] = 5;
  state.body_x[1] = 4;
  state.body_y[1] = 5;
  state.body_x[2] = 3;
  state.body_y[2] = 5;
  state.food_x = 3;
  state.food_y = 3;
  state.game_over = false;
  state.paused = false;
}

void Snek::tick() {
  bool* buf = screen->getBuffer();

  if (input->keyDown(PIN_BUTTON_SELECT)) {
    this->init();
  } else if (input->keyDown(PIN_BUTTON_START)) {
    state.paused = !state.paused;
  } else if (!state.game_over && !state.paused) {
    // Change dir
    if (input->keyDown(PIN_BUTTON_UP) && state.dir != DOWN) {
      state.dir = UP;
    } else if (input->keyDown(PIN_BUTTON_RIGHT) && state.dir != LEFT) {
      state.dir = RIGHT;
    } else if (input->keyDown(PIN_BUTTON_DOWN) && state.dir != UP) {
      state.dir = DOWN;
    } else if (input->keyDown(PIN_BUTTON_LEFT) && state.dir != RIGHT) {
      state.dir = LEFT;
    }

    // Move the snek body
    for (int i = state.len - 1; i > 0; i--) {
      state.body_x[i] = state.body_x[i - 1];
      state.body_y[i] = state.body_y[i - 1];
    }

    // Find new snek hed pos
    short new_head_x = state.body_x[0];
    short new_head_y = state.body_y[0];
    switch (state.dir) {
      case UP:
        new_head_y = state.body_y[0] - 1;
        break;
      case RIGHT:
        new_head_x = state.body_x[0] + 1;
        break;
      case DOWN:
        new_head_y = state.body_y[0] + 1;
        break;
      case LEFT:
        new_head_x = state.body_x[0] - 1;
        break;
    }

    // Check Mr. Snek for game over
    bool head_hit_wall = (
      new_head_x < 0 ||
      new_head_x > COLUMNS - 1 ||
      new_head_y < 0 ||
      new_head_y > ROWS - 1
    );

    bool head_hit_body = false;
    for (int i = 1; i < state.len; i++) {
      if (new_head_x == state.body_x[i] && new_head_y == state.body_y[i]) {
        head_hit_body = true;
        break;
      }
    }

    if (head_hit_wall || head_hit_body) {
      state.game_over = true;
    } else {
      state.body_x[0] = new_head_x;
      state.body_y[0] = new_head_y;
    }

    // Chck Mr. Snek for foodz
    if (new_head_x == state.food_x && new_head_y == state.food_y) {
      // Make snek long
      state.len += 1;

      // Snek gro backwards
      state.body_x[state.len - 1] = state.body_x[state.len - 2];
      state.body_y[state.len - 1] = state.body_y[state.len - 2];

      // New foods; this will infinite loop when you win. Consider it an easter
      // egg.
      bool food_in_body = false;
      do {
        state.food_x = random(0, COLUMNS - 1);
        state.food_y = random(0, ROWS - 1);

        bool food_in_body = false;
        for (int i = 0; i < state.len; i++) {
          if (state.food_x == state.body_x[i] && state.food_y == state.body_y[i]) {
            food_in_body = true;
            break;
          }
        }
      } while (food_in_body);
    }
  }

  // Paint mr snek
  screen->erase();
  for (int i = 0; i < state.len; i++) {
    *(buf + state.body_y[i] * COLUMNS + state.body_x[i]) = true;
  }

  // Draw food
  *(buf + state.food_y * COLUMNS + state.food_x) = true;
}
