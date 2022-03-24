#ifdef ARDUINO

#include "Input.h"
#include "Pins.h"
#include "Arduino.h"

void Input::handleB() {
  bool isPressed;

  isPressed = !(PINB & (1 << RAW_PIN_BUTTON_START));
  if (pressed[(int)button_e::start] != isPressed) {
    pressed[(int)button_e::start] = isPressed;
    if (isPressed) {
      newPress[(int)button_e::start] = true;
    }
  }

  isPressed = !(PINB & (1 << RAW_PIN_BUTTON_SELECT));
  if (pressed[(int)button_e::select] != isPressed) {
    pressed[(int)button_e::select] = isPressed;
    if (isPressed) {
      newPress[(int)button_e::select] = true;
    }
  }
}

void Input::handleC() {
  bool isPressed;

  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_A));
  if (pressed[(int)button_e::a] != isPressed) {
    pressed[(int)button_e::a] = isPressed;
    if (isPressed) {
      newPress[(int)button_e::a] = true;
    }
  }

  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_B));
  if (pressed[(int)button_e::b] != isPressed) {
    pressed[(int)button_e::b] = isPressed;
    if (isPressed) {
      newPress[(int)button_e::b] = true;
    }
  }

  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_UP));
  if (pressed[(int)button_e::up] != isPressed) {
    pressed[(int)button_e::up] = isPressed;
    if (isPressed) {
      newPress[(int)button_e::up] = true;
    }
  }

  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_LEFT));
  if (pressed[(int)button_e::left] != isPressed) {
    pressed[(int)button_e::left] = isPressed;
    if (isPressed) {
      newPress[(int)button_e::left] = true;
    }
  }

  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_DOWN));
  if (pressed[(int)button_e::down] != isPressed) {
    pressed[(int)button_e::down] = isPressed;
    if (isPressed) {
      newPress[(int)button_e::down] = true;
    }
  }

  isPressed = !(PINC & (1 << RAW_PIN_BUTTON_RIGHT));
  if (pressed[(int)button_e::right] != isPressed) {
    pressed[(int)button_e::right] = isPressed;
    if (isPressed) {
      newPress[(int)button_e::right] = true;
    }
  }
}

#endif
