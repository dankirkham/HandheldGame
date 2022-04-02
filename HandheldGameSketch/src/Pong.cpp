#include "Game.h"
#include "Pong.h"
#include "Screen.h"
#include "Pins.h"
#include "Random.h"

#define PADDLE_HEIGHT 3

Pong::Pong(Screen* screen, Input* input) {
  this->screen = screen;
  this->input = input;
  this->init();
}

int Pong::getDelay() {
  return Pong::DELAY;
}

void Pong::init() {
  state.game_over = false;
  state.paused = false;
  state.l_y = 5;
  state.r_y = 5;
  state.ball_x = 1;
  state.ball_y = 6;
  state.vel_x = 1;
  state.vel_y = 1;
}

void Pong::tick() {
  if (input->keyDown(button_e::start) && input->keyDown(button_e::select)) {
    this->gameToSwitchTo = games_e::MENU;
  } else if (input->keyDown(button_e::select)) {
    this->init();
  } else if (input->keyDown(button_e::start)) {
    state.paused = !state.paused;
  } else if (!state.game_over && !state.paused) {
    unsigned char new_x, new_y;

    if (input->keyHeld(button_e::down)) {
      if (state.l_y < (ROWS - PADDLE_HEIGHT)) {
        state.l_y++;
      }
    }

    if (input->keyHeld(button_e::up)) {
      if (state.l_y > 0) {
        state.l_y--;
      }
    }

    do {
      // Move ball
      new_x = state.ball_x + state.vel_x;
      new_y = state.ball_y + state.vel_y;

      if (new_y < 0 || new_y >= ROWS) {
        state.vel_y = state.vel_y * -1;
        continue;
      }

      if (new_x == 0) {
        if (new_y >= state.l_y && new_y < state.l_y + PADDLE_HEIGHT) {
          state.vel_x = state.vel_x * -1;
          continue;
        } else {
          state.game_over = true;
          break;
        }
      }

      if (new_x == COLUMNS - 1) {
        if (new_y >= state.r_y && new_y < state.r_y + PADDLE_HEIGHT) {
          state.vel_x = state.vel_x * -1;
          continue;
        } else {
          state.game_over = true;
          break;
        }
      }

      break;
    } while (true);

    state.ball_x = new_x;
    state.ball_y = new_y;

    if (!state.game_over) {
      if (random(1, 2) == 1) {
        if (state.r_y < new_y) {
          state.r_y++;
        } else if (state.r_y > new_y) {
          state.r_y--;
        }
      } else {
        state.r_y = new_y - 1;
      }
      if (state.r_y < 0) state.r_y = 0;
      if (state.r_y > ROWS - PADDLE_HEIGHT) state.r_y = ROWS - PADDLE_HEIGHT;
    }
  }

  screen->erase();

  // Paddles
  for (unsigned char y = state.l_y; y < state.l_y + PADDLE_HEIGHT; y++) {
    screen->setPixel(0, y);
  }
  for (unsigned char y = state.r_y; y < state.r_y + PADDLE_HEIGHT; y++) {
    screen->setPixel(COLUMNS - 1, y);
  }

  // Ball
  screen->setPixel(state.ball_x, state.ball_y);
}
