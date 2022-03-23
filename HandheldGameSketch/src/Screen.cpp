#include "Screen.h"

void IScreen::erase() {
  for (int i = 0; i < ROWS * COLUMNS; i++) {
      *(this->buf + i) = false;
  }
}

void IScreen::setPixel(int x, int y) {
  *(buf + y * COLUMNS + x) = true;
}

bool IScreen::getPixel(int x, int y) {
  return *(screen + y * COLUMNS + x);
}

