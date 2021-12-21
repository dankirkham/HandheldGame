#ifndef ARDUINO

#include "Input.h"

Input::Input()
{
  for (int i = 0; i < 17; i++)
  {
    keys[i] = false;
  }
}

bool Input::keyDown(int key)
{
  return keys[key];
}

void Input::tick()
{
}

void Input::keyPressEvent(int key)
{
  keys[key] = true;
}

void Input::keyReleaseEvent(int key)
{
  keys[key] = false;
}

#endif
