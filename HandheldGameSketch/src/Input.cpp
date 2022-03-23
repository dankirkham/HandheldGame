#include "Input.h"

bool Input::keyDown(button_e key)
{
  bool result = pressed[(int)key] || newPress[(int)key];
  newPress[(int)key] = false;
  return result;
}
