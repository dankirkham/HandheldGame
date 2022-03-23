#include "Pins.h"

button_e to_button(pin_e pin)
{
  switch (pin)
  {
    case pin_e::button_start:
      return button_e::start;
    case pin_e::button_select:
      return button_e::select;
    case pin_e::button_a:
      return button_e::a;
    case pin_e::button_b:
      return button_e::b;
    case pin_e::button_up:
      return button_e::up;
    case pin_e::button_left:
      return button_e::left;
    case pin_e::button_down:
      return button_e::down;
    case pin_e::button_right:
      return button_e::right;
  }
}
