#ifndef GuiInput_h
#define GuiInput_h

#include "Input.h"
#include "Pins.h"

class Input : public IInput {
private:
  void handleKey(button_e key, bool isPressed) override;
public:
  bool keyDown(button_e key) override;
  bool keyHeld(button_e key) override;
  void tick() override;
public:
  void keyPressEvent(button_e);
  void keyReleaseEvent(button_e);
};

#endif
