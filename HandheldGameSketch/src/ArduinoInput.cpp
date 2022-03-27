#ifdef ARDUINO

#include "Input.h"
#include "Pins.h"
#include "Arduino.h"

void Input::handleB() {
  bool isPressed;
  button_e key;

  key = button_e::start;
  isPressed = !(PINB & (1 << RAW_PIN_BUTTON_START));
  handleKey(key, isPressed);

  key = button_e::select;
  isPressed = !(PINB & (1 << RAW_PIN_BUTTON_SELECT));
  handleKey(key, isPressed);
}

void Input::handleC() {
  bool isPressed;
  button_e key;

  key = button_e::a;
  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_A));
  handleKey(key, isPressed);

  key = button_e::b;
  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_B));
  handleKey(key, isPressed);

  key = button_e::up;
  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_UP));
  handleKey(key, isPressed);

  key = button_e::left;
  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_LEFT));
  handleKey(key, isPressed);

  key = button_e::down;
  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_DOWN));
  handleKey(key, isPressed);

  key = button_e::right;
  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_RIGHT));
  handleKey(key, isPressed);
}

#endif
