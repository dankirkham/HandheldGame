#ifndef ARDUINO

#include "Input.h"

void Input::tick()
{
  for (int i = 0; i < (int)button_e::button_count; i++)
  {
    newPress[i] = false;
  }
}

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
