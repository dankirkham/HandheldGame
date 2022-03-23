#ifndef ARDUINO

#include "Screen.h"

void Screen::draw()
{
  // Swap screen and buffer
  bool *temp = this->screen;
  this->screen = this->buf;
  this->buf = temp;
}

#endif
