#ifndef ArduinoScreen_h
#define ArduinoScreen_h

#include "Screen.h"
#include "Pins.h"

class Screen : public IScreen {
private:
  unsigned char counter;

  const unsigned char COLOR_THRESHOLDS[4] = {
    0, // color_e::off
    1, // color_e::dark
    1, // color_e::light
    2, // color_e::bright
  };
public:
  Screen();
  void draw() override;
};

#endif
