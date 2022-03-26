#ifndef ARDUINO

#include "Screen.h"

void Screen::draw()
{
  // Swap screen and buffer
  unsigned char *temp = this->screen;
  this->screen = this->buf;
  this->buf = temp;
}

#endif
