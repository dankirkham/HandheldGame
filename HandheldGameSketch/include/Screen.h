#ifndef Screen_h
#define Screen_h

#include "Constants.h"

class IScreen {
protected:
  bool buffer_1[ROWS * COLUMNS] = { false };
  bool buffer_2[ROWS * COLUMNS] = { false };
  bool *screen = (bool*) this->buffer_1;
  bool *buf = (bool*) this->buffer_2;

public:
  virtual void draw() = 0;
  virtual void erase() = 0;
  virtual bool* getBuffer() = 0;
};

#ifdef ARDUINO
#include "ArduinoScreen.h"
#else
#include "GuiScreen.h"
#endif

#endif
