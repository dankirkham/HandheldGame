#ifndef Input_h
#define Input_h

#include "Pins.h"

class IInput {
protected:
  static const int DEBOUNCE_COUNT = 0;

  bool pressed[(int)button_e::button_count];
  bool newPress[(int)button_e::button_count];
public:
  static const int DELAY = 5;

  virtual bool keyDown(button_e key) = 0;
};

#ifdef ARDUINO
#include "ArduinoInput.h"
#else
#include "GuiInput.h"
#endif

#endif
