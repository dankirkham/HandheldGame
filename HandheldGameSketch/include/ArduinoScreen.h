#ifndef ArduinoScreen_h
#define ArduinoScreen_h

#include "Screen.h"
#include "Pins.h"

class Screen : public IScreen {
private:
  bool buffer_1[ROWS * COLUMNS] = { false };
  bool buffer_2[ROWS * COLUMNS] = { false };
  bool *screen = (bool*) this->buffer_1;
  bool *buf = (bool*) this->buffer_2;

public:
  Screen();
  void draw() override;
  void erase() override;
  bool* getBuffer() override;
};

#endif
