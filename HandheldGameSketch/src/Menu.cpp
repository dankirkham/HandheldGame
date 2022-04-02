#include "Constants.h"
#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "Pins.h"
#include "Font.h"

#define TEXT_Y 2
#define text_len 4
const short MENU_ITEMS = sizeof(menu_items)/sizeof(menu_items[0]);
const short SCROLLBAR_WIDTH = COLUMNS / MENU_ITEMS;

Menu::Menu(Screen* screen, Input* input) {
  this->screen = screen;
  this->input = input;
  this->init();
}

int Menu::getDelay() {
  return Menu::DELAY;
}

void Menu::init() {
  state.initial_delay = 4;
  state.x = 0;
  state.direction = Direction::RIGHT;
  state.selection = 0;
  strcpy_P(state.menu_item, (PGM_P)pgm_read_word(&(menu_items[state.selection])));
}

void Menu::tick() {
  if (state.initial_delay > 0) {
    state.initial_delay--;

    screen->erase();
    bool odd_even = state.initial_delay % 2;
    for (int x = 0; x < COLUMNS; x++) {
      for (int y = 0; y < ROWS; y++) {
        if (x % 2 == odd_even) {
          screen->setPixel(x, y);
        }
        odd_even = !odd_even;
      }
    }

    input->keyDown(button_e::start);
    input->keyDown(button_e::select);
    input->keyDown(button_e::up);
    input->keyDown(button_e::left);
    input->keyDown(button_e::down);
    input->keyDown(button_e::left);
    input->keyDown(button_e::a);
    input->keyDown(button_e::b);

    return;
  }

  if (state.direction == Direction::RIGHT) {
    state.x--;

    if (state.x <= COLUMNS - strlen(state.menu_item) * 6 + 1)
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

  if (
    input->keyDown(button_e::start) ||
    input->keyDown(button_e::a)
    ) {
    // Process selection
    switch (state.selection) {
      case 0:
        this->gameToSwitchTo = games_e::SNEK;
        break;
      case 1:
        this->gameToSwitchTo = games_e::BRICK;
        break;
      case 2:
        this->gameToSwitchTo = games_e::BIRB;
        break;
      case 3:
        this->gameToSwitchTo = games_e::TETRIS;
        break;
      case 4:
        this->gameToSwitchTo = games_e::PONG;
        break;
      case 5:
        this->gameToSwitchTo = games_e::COUNTER;
        break;
      default:
        break;
    }
  } else if (
    input->keyDown(button_e::left)
    ) {
    state.selection--;
    state.x = 0;
    state.direction = Direction::RIGHT;

    if (state.selection < 0)
    {
      state.selection = 0;
    }

    strcpy_P(state.menu_item, (PGM_P)pgm_read_word(&(menu_items[state.selection])));
  } else if (
    input->keyDown(button_e::right)
    ) {
    state.selection++;
    state.x = 0;
    state.direction = Direction::RIGHT;

    if (state.selection >= MENU_ITEMS)
    {
      state.selection = MENU_ITEMS - 1;
    }
    strcpy_P(state.menu_item, (PGM_P)pgm_read_word(&(menu_items[state.selection])));
  }

  // Calculate scroll bar
  unsigned char scrollbar_x1 = state.selection * SCROLLBAR_WIDTH;
  unsigned char scrollbar_x2 = scrollbar_x1 + SCROLLBAR_WIDTH;

  screen->erase();
  for (int x = scrollbar_x1; x <= scrollbar_x2; x++) screen->setPixel(x, 0);
  draw_text(screen, state.menu_item, state.x, TEXT_Y);
}
