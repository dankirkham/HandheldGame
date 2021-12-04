#ifndef GuiInput_h
#define GuiInput_h

#include "Input.h"

class Input : public IInput {
public:
  bool keyDown(int key) override;
  void tick() override;
};

#endif
