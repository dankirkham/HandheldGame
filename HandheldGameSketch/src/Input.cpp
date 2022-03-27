#include "Input.h"

void Input::handleKey(button_e key, bool isPressed) {
  key_state_e state;
  state = key_state[(int)key];
  if (isPressed) {
    if (state == key_state_e::up) {
      key_state[(int)key] = key_state_e::up_to_down;
      debounce_counters[(int)key] = Input::DEBOUNCE_COUNT;
    } else if (state == key_state_e::down_to_up) {
      key_state[(int)key] = key_state_e::down;
    }
  } else {
    if (state == key_state_e::down) {
      key_state[(int)key] = key_state_e::down_to_up;
      debounce_counters[(int)key] = Input::DEBOUNCE_COUNT;
    } else if (state == key_state_e::up_to_down) {
      key_state[(int)key] = key_state_e::up;
    }
  }
}

bool Input::keyDown(button_e key)
{
  bool result = newPress[(int)key];
  newPress[(int)key] = false;
  return result;
}

bool Input::keyHeld(button_e key)
{
  auto state = key_state[(int)key];
  bool pressed = state == key_state_e::down || state == key_state_e::down_to_up;
  bool result = pressed || newPress[(int)key];
  newPress[(int)key] = false;
  return result;
}

void Input::tick() {
  counter--;
  if (counter == 0) {
    counter = Input::DELAY;
    for (int key = 0; key < (int)button_e::button_count; key++) {
      auto state = key_state[key];

      if (state == key_state_e::down_to_up || state == key_state_e::up_to_down) {
        debounce_counters[key]--;
        if (debounce_counters[key] == 0) {
          if (state == key_state_e::down_to_up) {
            key_state[key] = key_state_e::up;
          } else {
            key_state[key] = key_state_e::down;
            newPress[key] = true;
          }
        }
      }
    }
  }
}
