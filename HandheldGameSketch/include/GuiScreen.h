#ifndef GuiScreen_h
#define GuiScreen_h

#include "Screen.h"

class Screen : public IScreen {
public:
  void draw() override;
  void erase() override;
  bool* getBuffer() override;
};

#endif
