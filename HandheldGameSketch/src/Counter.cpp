#include "Game.h"
#include "Counter.h"
#include "Screen.h"
#include "Pins.h"
#include "Random.h"
#include "Font.h"


Counter::Counter(Screen* screen, Input* input) {
  this->screen = screen;
  this->input = input;
  this->init();
}

int Counter::getDelay() {
  return Counter::DELAY;
}

void Counter::init() {
  state.letter = 'A' - 1;
  state.game_over = false;
  state.paused = false;
}

void Counter::tick() {
  if (input->keyDown(button_e::start) && input->keyDown(button_e::select)) {
    this->gameToSwitchTo = games_e::MENU;
  } else if (input->keyDown(button_e::select)) {
    this->init();
  } else if (input->keyDown(button_e::start)) {
    state.paused = !state.paused;
  } else if (!state.game_over && !state.paused) {
    state.letter += 1;
    if (state.letter >= 'Z') {
      state.letter = 'A' - 1;
    }
  }

  // Draw birb
  screen->erase();
  draw_letter(screen, state.letter, 0, 0);
}
