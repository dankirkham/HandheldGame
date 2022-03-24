#include "Screen.h"

void IScreen::erase() {
  for (int i = 0; i < ROWS * (COLUMNS / 8); i++) {
      *(this->buf + i) = false;
  }
}

void IScreen::setPixel(int x, int y) {
  //*(buf + y * COLUMNS + x) = true;

  *(buf + y * (COLUMNS / 8) + (x / 8)) |= (1 << (x % 8));
}

bool IScreen::getPixel(int x, int y) {
  //return *(screen + y * COLUMNS + x);
  return *(buf + y * (COLUMNS / 8) + (x / 8)) & (1 << (x % 8));
}

