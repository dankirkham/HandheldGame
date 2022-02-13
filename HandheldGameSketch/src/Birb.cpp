#include "Game.h"
#include "Birb.h"
#include "Screen.h"
#include "Pins.h"
#include "Random.h"
#include "Font.h"

#define BIRB_X 2
#define Y_MULTIPLIER 25
#define JUMP_TIME 5
#define ACCEL 2
#define GATE_COUNT 3
#define GATE_HEIGHT 5

Birb::Birb(Screen* screen, Input* input) {
  this->screen = screen;
  this->input = input;
  this->init();
}

int Birb::getDelay() {
  return Birb::DELAY;
}

void Birb::init() {
  // Init the birb
  state.birb_y = 4;
  state.birb_vy = 0;
  state.accel_ticks = 0;
  state.game_over = false;
  state.paused = false;
  for (int i = 0; i < GATE_COUNT; i++) {
    state.gate_x[i] = COLUMNS + (6 * i);
    state.gate_y[i] = random(1, ROWS - GATE_HEIGHT);
  }
}

void Birb::tick() {
  bool* buf = screen->getBuffer();

  if (input->keyDown(PIN_BUTTON_START) && input->keyDown(PIN_BUTTON_SELECT)) {
    this->gameToSwitchTo = games_e::MENU;
  } else if (input->keyDown(PIN_BUTTON_SELECT)) {
    this->init();
  } else if (input->keyDown(PIN_BUTTON_START)) {
    state.paused = !state.paused;
  } else if (!state.game_over && !state.paused) {
    if (input->keyDown(PIN_BUTTON_A)) {
      if (state.accel_ticks == 0) {
        state.accel_ticks = JUMP_TIME;
        state.birb_vy = 0;
      }
    }

    if (state.accel_ticks > 0) {
      state.accel_ticks -= 1;
      state.birb_vy -= ACCEL;
    } else {
      state.birb_vy += ACCEL;
    }

    state.birb_y += state.birb_vy;

    if (state.birb_vy > 10) state.birb_vy = 10;

    if (state.birb_y >= Y_MULTIPLIER * (ROWS - 1)) {
      state.game_over = true;
      state.birb_y = Y_MULTIPLIER * (ROWS - 1);
    } else if (state.birb_y < 0) {
      state.birb_y = 0;
      state.birb_vy = 0;
    }

    // Move the gates
    for (int i = 0; i < GATE_COUNT; i++) {
      state.gate_x[i] -= 1;
      if (state.gate_x[i] < 0) {
        state.gate_x[i] = COLUMNS + 1;
        state.gate_y[i] = random(1, ROWS - GATE_HEIGHT);
      }
    }

    // Check for collsion
    for (int i = 0; i < GATE_COUNT; i++) {
      auto gate_x = state.gate_x[i];
      if (gate_x != BIRB_X) continue;
      auto gate_y = state.gate_y[i];
      if (
        (state.birb_y / Y_MULTIPLIER) < gate_y ||
        (state.birb_y / Y_MULTIPLIER) >= gate_y + GATE_HEIGHT
      ) {
        state.game_over = true;
      }
    }
  }

  // Draw birb
  screen->erase();
  short y = state.birb_y / Y_MULTIPLIER;
  *(buf + (y * COLUMNS + BIRB_X)) = true;

  // Draw the gates
  for (int i = 0; i < GATE_COUNT; i++) {
    auto gate_x = state.gate_x[i];
    if (gate_x >= 0 && gate_x < COLUMNS) {
      auto gate_y = state.gate_y[i];
      for (int j = 0; j < gate_y; j++) {
        *(buf + (j * COLUMNS + gate_x)) = true;
      }
      for (int j = gate_y + GATE_HEIGHT; j < ROWS; j++) {
        *(buf + (j * COLUMNS + gate_x)) = true;
      }
    }
  }
}
