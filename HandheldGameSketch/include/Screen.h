#ifndef Screen_h
#define Screen_h

#include "Constants.h"

enum class color_e : int {
  off = 0,
  dark = 1,
  light = 2,
  bright = 3
};

class IScreen {
protected:
  unsigned char buffer_1[ROWS * COLUMNS / 4] = {0};
  unsigned char *screen = (unsigned char*) this->buffer_1;

#if 0
  char buffer_2[ROWS * COLUMNS / 8] = {0};
  char *buf = (char*) this->buffer_2;
#else
  unsigned char *buf = (unsigned char*) this->buffer_1;
#endif

public:
  void setPixel(int x, int y, color_e);
  void setPixel(int x, int y);
  color_e getPixel(int x, int y);
  unsigned char getSegment(int n, int y);
  void erase();

public:
  virtual void draw() = 0;
};

#ifdef ARDUINO
#include "ArduinoScreen.h"
#else
#include "GuiScreen.h"
#endif

#endif
