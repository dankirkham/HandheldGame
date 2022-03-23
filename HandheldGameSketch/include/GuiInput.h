#ifndef GuiInput_h
#define GuiInput_h

#include "Input.h"
#include "Pins.h"

class Input : public IInput {
public:
  bool keyDown(button_e key) override;
  void tick() override;
public:
  void keyPressEvent(button_e);
  void keyReleaseEvent(button_e);
};

#endif
