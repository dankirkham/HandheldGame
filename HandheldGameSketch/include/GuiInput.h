#ifndef GuiInput_h
#define GuiInput_h

#include "Input.h"

class Input : public IInput {
public:
  Input();
private:
  bool keys[17];
public:
  bool keyDown(int key) override;
  void tick() override;
public:
  void keyPressEvent(int);
  void keyReleaseEvent(int);
};

#endif
