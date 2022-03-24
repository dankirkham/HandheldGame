#ifndef Screen_h
#define Screen_h

#include "Constants.h"

class IScreen {
protected:
  char buffer_1[ROWS * COLUMNS / 8] = {0};
  char *screen = (char*) this->buffer_1;

#if 0
  char buffer_2[ROWS * COLUMNS / 8] = {0};
  char *buf = (char*) this->buffer_2;
#else
  char *buf = (char*) this->buffer_1;
#endif

public:
  void setPixel(int x, int y);
  bool getPixel(int x, int y);
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
