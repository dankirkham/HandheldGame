#ifndef Screen_h
#define Screen_h

#include "Pins.h"

class Screen {
private:
  bool buffer_1[ROWS * COLUMNS] = { false };
  bool buffer_2[ROWS * COLUMNS] = { false };
  bool *screen = (bool*) this->buffer_1;
  bool *buf = (bool*) this->buffer_2;

public:
  Screen();
  void draw();
  void erase();
  bool* getBuffer();
};

#endif
