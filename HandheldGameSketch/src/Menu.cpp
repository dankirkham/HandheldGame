#include "Constants.h"
#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "Pins.h"
#include "Font.h"

#define TEXT_Y 2
#define text_len 4

Menu::Menu(Screen* screen, Input* input) {
  this->screen = screen;
  this->input = input;
  this->init();
}

int Menu::getDelay() {
  return Menu::DELAY;
}

void Menu::init() {
  state.x = 0;
  state.direction = Direction::LEFT;
  state.selection = 0;
}

void Menu::tick() {
  bool* buf = screen->getBuffer();

  if (state.direction == Direction::RIGHT) {
    state.x--;

    if (state.x <= COLUMNS - menu_items[state.selection].len * 6 + 1)
    {
      state.direction = Direction::LEFT;
    }
  } else {
    state.x++;

    if (state.x >= 0)
    {
      state.direction = Direction::RIGHT;
    }
  }

  if (input->keyDown(PIN_BUTTON_START)) {
    // Process selection
    switch (state.selection) {
      case 0:
        this->gameToSwitchTo = games_e::SNEK;
        break;
      case 1:
        this->gameToSwitchTo = games_e::BRICK;
        break;
      default:
        break;
    }
  } else if (
    input->keyDown(PIN_BUTTON_UP) ||
    input->keyDown(PIN_BUTTON_LEFT)
    ) {
    state.selection--;
    state.x = 0;
    state.direction = Direction::RIGHT;

    if (state.selection < 0)
    {
      state.selection = 0;
    }
  } else if (
    input->keyDown(PIN_BUTTON_DOWN) ||
    input->keyDown(PIN_BUTTON_RIGHT)
    ) {
    state.selection++;
    state.x = 0;
    state.direction = Direction::RIGHT;

    const short len = sizeof(menu_items)/sizeof(menu_items[0]);
    if (state.selection >= len)
    {
      state.selection = len - 1;
    }
  }

  screen->erase();

  draw_text(buf, menu_items[state.selection].text, state.x, TEXT_Y);
}
