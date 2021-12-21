#ifndef ARDUINO

#include "Screen.h"

void Screen::draw()
{
  // Swap screen and buffer
  bool *temp = this->screen;
  this->screen = this->buf;
  this->buf = temp;
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
