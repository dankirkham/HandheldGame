#ifdef ARDUINO

#include "Input.h"
#include "Pins.h"
#include "Arduino.h"

Input::Input() {
  pressed[(int)button_e::a] = !digitalRead((int)pin_e::button_a);
  pressed[(int)button_e::b] = !digitalRead((int)pin_e::button_b);
  pressed[(int)button_e::start] = !digitalRead((int)pin_e::button_start);
  pressed[(int)button_e::select] = !digitalRead((int)pin_e::button_select);
  pressed[(int)button_e::up] = !digitalRead((int)pin_e::button_up);
  pressed[(int)button_e::left] = !digitalRead((int)pin_e::button_left);
  pressed[(int)button_e::down] = !digitalRead((int)pin_e::button_down);
  pressed[(int)button_e::right] = !digitalRead((int)pin_e::button_right);
}

void Input::tick() {
  if (debounce[(int)button_e::start] > 0) debounce[(int)button_e::start]--;
  if (debounce[(int)button_e::select] > 0) debounce[(int)button_e::select]--;
  if (debounce[(int)button_e::a] > 0) debounce[(int)button_e::a]--;
  if (debounce[(int)button_e::b] > 0) debounce[(int)button_e::b]--;
  if (debounce[(int)button_e::up] > 0) debounce[(int)button_e::up]--;
  if (debounce[(int)button_e::left] > 0) debounce[(int)button_e::left]--;
  if (debounce[(int)button_e::down] > 0) debounce[(int)button_e::down]--;
  if (debounce[(int)button_e::right] > 0) debounce[(int)button_e::right]--;
}

void Input::handleB() {
  if (debounce[(int)button_e::start] == 0) {
    bool isPressed = !(PINB & (1 << RAW_PIN_BUTTON_START));
    if (pressed[(int)button_e::start] != isPressed) {
      debounce[(int)button_e::start] = Input::DEBOUNCE_COUNT;
      pressed[(int)button_e::start] = isPressed;
    }
  }

  if (debounce[(int)button_e::select] == 0) {
    bool isPressed = !(PINB & (1 << RAW_PIN_BUTTON_SELECT));
    if (pressed[(int)button_e::select] != isPressed) {
      debounce[(int)button_e::select] = Input::DEBOUNCE_COUNT;
      pressed[(int)button_e::select] = isPressed;
    }
  }
}

void Input::handleC() {
  if (debounce[(int)button_e::a] == 0) {
    bool isPressed = !(PINC & (1 << RAW_PIN_BUTTON_A));
    if (pressed[(int)button_e::a] != isPressed) {
      debounce[(int)button_e::a] = Input::DEBOUNCE_COUNT;
      pressed[(int)button_e::a] = isPressed;
    }
  }

  if (debounce[(int)button_e::b] == 0) {
    bool isPressed = !(PINC & (1 << RAW_PIN_BUTTON_B));
    if (pressed[(int)button_e::b] != isPressed) {
      debounce[(int)button_e::b] = Input::DEBOUNCE_COUNT;
      pressed[(int)button_e::b] = isPressed;
    }
  }

  if (debounce[(int)button_e::up] == 0) {
    bool isPressed = !(PINC & (1 << RAW_PIN_BUTTON_UP));
    if (pressed[(int)button_e::up] != isPressed) {
      debounce[(int)button_e::up] = Input::DEBOUNCE_COUNT;
      pressed[(int)button_e::up] = isPressed;
    }
  }

  if (debounce[(int)button_e::left] == 0) {
    bool isPressed = !(PINC & (1 << RAW_PIN_BUTTON_LEFT));
    if (pressed[(int)button_e::left] != isPressed) {
      debounce[(int)button_e::left] = Input::DEBOUNCE_COUNT;
      pressed[(int)button_e::left] = isPressed;
    }
  }

  if (debounce[(int)button_e::down] == 0) {
    bool isPressed = !(PINC & (1 << RAW_PIN_BUTTON_DOWN));
    if (pressed[(int)button_e::down] != isPressed) {
      debounce[(int)button_e::down] = Input::DEBOUNCE_COUNT;
      pressed[(int)button_e::down] = isPressed;
    }
  }

  if (debounce[(int)button_e::right] == 0) {
    bool isPressed = !(PINC & (1 << RAW_PIN_BUTTON_RIGHT));
    if (pressed[(int)button_e::right] != isPressed) {
      debounce[(int)button_e::right] = Input::DEBOUNCE_COUNT;
      pressed[(int)button_e::right] = isPressed;
    }
  }
}

#endif
