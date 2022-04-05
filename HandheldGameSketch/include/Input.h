#ifndef Input_h
#define Input_h

#include "Pins.h"

enum class key_state_e {
  up,
  up_to_down,
  down,
  down_to_up
};

class IInput {
protected:
  static const int DEBOUNCE_COUNT = 1;
  static const int DELAY = 2;

  key_state_e key_state[(int)button_e::button_count] = { key_state_e::up };
  bool newPress[(int)button_e::button_count];
  unsigned int debounce_counters[(int)button_e::button_count];
public:
  virtual bool keyDown(button_e key) = 0;
  virtual bool keyHeld(button_e key) = 0;

  virtual void tick() = 0;

protected:
  unsigned char counter;

  virtual void handleKey(button_e key, bool isPressed) = 0;
};

#ifdef ARDUINO
#include "ArduinoInput.h"
#else
#include "GuiInput.h"
#endif

#endif
