#ifndef ARDUINO

#include "Input.h"

void Input::keyPressEvent(button_e key)
{
  handleKey(key, true);
}

void Input::keyReleaseEvent(button_e key)
{
  handleKey(key, false);
}

#endif
