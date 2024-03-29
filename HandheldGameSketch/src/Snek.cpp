#include "Game.h"
#include "Snek.h"
#include "Screen.h"
#include "Pins.h"
#include "Random.h"
#include "Font.h"

Snek::Snek(Screen* screen, Input* input) {
  this->screen = screen;
  this->input = input;
  this->init();
}

int Snek::getDelay() {
  return Snek::DELAY;
}

void Snek::init() {
  // Init the snek
  state.dir = Direction::RIGHT;
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
  if (input->keyDown(button_e::start) && input->keyDown(button_e::select)) {
    this->gameToSwitchTo = games_e::MENU;
  } else if (input->keyDown(button_e::select)) {
    this->init();
  } else if (input->keyDown(button_e::start)) {
    state.paused = !state.paused;
  } else if (!state.game_over && !state.paused) {
    // Change dir
    if (input->keyDown(button_e::up) && state.dir != Direction::DOWN) {
      state.dir = Direction::UP;
    } else if (input->keyDown(button_e::right) && state.dir != Direction::LEFT) {
      state.dir = Direction::RIGHT;
    } else if (input->keyDown(button_e::down) && state.dir != Direction::UP) {
      state.dir = Direction::DOWN;
    } else if (input->keyDown(button_e::left) && state.dir != Direction::RIGHT) {
      state.dir = Direction::LEFT;
    }

    short tail_x = state.body_x[state.len - 1];
    short tail_y = state.body_y[state.len - 1];

    // Move the snek body
    for (int i = state.len - 1; i > 0; i--) {
      state.body_x[i] = state.body_x[i - 1];
      state.body_y[i] = state.body_y[i - 1];
    }

    // Find new snek hed pos
    short new_head_x = state.body_x[0];
    short new_head_y = state.body_y[0];
    switch (state.dir) {
      case Direction::UP:
        new_head_y = state.body_y[0] - 1;
        break;
      case Direction::RIGHT:
        new_head_x = state.body_x[0] + 1;
        break;
      case Direction::DOWN:
        new_head_y = state.body_y[0] + 1;
        break;
      case Direction::LEFT:
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
      state.body_x[state.len - 1] = tail_x;
      state.body_y[state.len - 1] = tail_y;

      // New foods; this will infinite loop when you win. Consider it an easter
      // egg.
      bool food_in_body = false;
      do {
        state.food_x = random(0, COLUMNS - 1);
        state.food_y = random(0, ROWS - 1);

        food_in_body = false;
        for (int i = 0; i < state.len; i++) {
          if (state.food_x == state.body_x[i] &&
              state.food_y == state.body_y[i]) {
            food_in_body = true;
            break;
          }
        }
      } while (food_in_body);
    }
  }

  screen->erase();

  // Draw food
  screen->setPixel(state.food_x, state.food_y, color_e::dark);

  // Paint mr snek
  for (int i = 0; i < state.len; i++) {
    screen->setPixel(state.body_x[i], state.body_y[i]);
  }
}
