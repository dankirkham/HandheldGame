#ifndef ARDUINO

#include "Screen.h"

void draw()
{
}

void Screen::erase() {
  for (int i = 0; i < ROWS * COLUMNS; i++) {
      *(this->buf + i) = false;
  }
}

bool* Screen::getBuffer() {
  return this->buf;
}

#endif
