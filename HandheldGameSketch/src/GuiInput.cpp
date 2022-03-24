#ifndef ARDUINO

#include "Input.h"

void Input::keyPressEvent(button_e key)
{
  pressed[(int)key] = true;
  newPress[(int)key] = true;
}

void Input::keyReleaseEvent(button_e key)
{
  pressed[(int)key] = false;
}

#endif
