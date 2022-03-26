#include "Screen.h"

void IScreen::erase() {
  for (int i = 0; i < ROWS * (COLUMNS / 4); i++) {
      *(this->buf + i) = false;
  }
}

void IScreen::setPixel(int x, int y, color_e color) {
  *(buf + y * (COLUMNS >> 2) + (x >> 2)) &= ~(0x3 << ((x & 3) << 1)); // Clear bits
  *(buf + y * (COLUMNS >> 2) + (x >> 2)) |= ((int)color << ((x & 3) << 1)); // Set bits
}

void IScreen::setPixel(int x, int y) {
  setPixel(x, y, color_e::bright);
}

color_e IScreen::getPixel(int x, int y) {
  int val = (
    (
     *(buf + y * (COLUMNS >> 2) + (x >> 2)) & (0x3 << ((x & 3) << 1))
    ) >> ((x & 3) << 1)
  );

  return (color_e) val;
}

unsigned char IScreen::getSegment(int n, int y)
{
  return *(buf + y * (COLUMNS >> 2) + n);
}
