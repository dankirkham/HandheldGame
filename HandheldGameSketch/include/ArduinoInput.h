#ifndef ArduinoInput_h
#define ArduinoInput_h

#include "Pins.h"

// Don't include directly, include Input.h instead.

class Input : public IInput {
private:
  void handleKey(button_e key, bool isPressed) override;
public:
  void handleB();
  void handleC();

  bool keyDown(button_e key) override;
  bool keyHeld(button_e key) override;

  void tick() override;
};

#endif
