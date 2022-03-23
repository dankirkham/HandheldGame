#ifndef ArduinoScreen_h
#define ArduinoScreen_h

#include "Screen.h"
#include "Pins.h"

class Screen : public IScreen {
public:
  Screen();
  void draw() override;
};

#endif
