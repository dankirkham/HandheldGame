#ifndef Screen_h
#define Screen_h

#include "Constants.h"

class IScreen {
protected:
  bool buffer_1[ROWS * COLUMNS] = { false };
  //bool buffer_2[ROWS * COLUMNS] = { false };
  bool *screen = (bool*) this->buffer_1;
  bool *buf = (bool*) this->buffer_1;

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
