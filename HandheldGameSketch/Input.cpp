#include "Input.h"
#include "Pins.h"
#include "Arduino.h"

Input::Input() {
  this->a_pressed = !digitalRead(PIN_BUTTON_A);
  this->b_pressed = !digitalRead(PIN_BUTTON_B);
  this->start_pressed = !digitalRead(PIN_BUTTON_START);
  this->select_pressed = !digitalRead(PIN_BUTTON_SELECT);
  this->up_pressed = !digitalRead(PIN_BUTTON_UP);
  this->left_pressed = !digitalRead(PIN_BUTTON_LEFT);
  this->down_pressed = !digitalRead(PIN_BUTTON_DOWN);
  this->right_pressed = !digitalRead(PIN_BUTTON_RIGHT);
}

bool Input::keyDown(int key) {
  switch (key) {
    case PIN_BUTTON_A:
      return this->a_pressed;
    case PIN_BUTTON_B:
      return this->b_pressed;
    case PIN_BUTTON_UP:
      return this->up_pressed;
    case PIN_BUTTON_LEFT:
      return this->left_pressed;
    case PIN_BUTTON_DOWN:
      return this->down_pressed;
    case PIN_BUTTON_RIGHT:
      return this->right_pressed;
    case PIN_BUTTON_START:
      return this->start_pressed;
    case PIN_BUTTON_SELECT:
      return this->select_pressed;
    default:
      return false;
  }
}

void Input::tick() {
  if (this->start_debounce_count > 0) this->start_debounce_count--;
  if (this->select_debounce_count > 0) this->select_debounce_count--;
  if (this->a_debounce_count > 0) this->a_debounce_count--;
  if (this->b_debounce_count > 0) this->b_debounce_count--;
  if (this->up_debounce_count > 0) this->up_debounce_count--;
  if (this->left_debounce_count > 0) this->left_debounce_count--;
  if (this->down_debounce_count > 0) this->down_debounce_count--;
  if (this->right_debounce_count > 0) this->right_debounce_count--;
}

void Input::handleB() {
  if (this->start_debounce_count == 0) {
    bool pressed = !(PINB & (1 << RAW_PIN_BUTTON_START));
    if (this->start_pressed != pressed) {
      this->start_debounce_count = Input::DEBOUNCE_COUNT;
      this->start_pressed = pressed;
    }
  }

  if (this->select_debounce_count == 0) {
    bool pressed = !(PINB & (1 << RAW_PIN_BUTTON_SELECT));
    if (this->select_pressed != pressed) {
      this->select_debounce_count = Input::DEBOUNCE_COUNT;
      this->select_pressed = pressed;
    }
  }
}

void Input::handleC() {
  if (this->a_debounce_count == 0) {
    bool pressed = !(PINC & (1 << RAW_PIN_BUTTON_A));
    if (this->a_pressed != pressed) {
      this->a_debounce_count = Input::DEBOUNCE_COUNT;
      this->a_pressed = pressed;
    }
  }

  if (this->b_debounce_count == 0) {
    bool pressed = !(PINC & (1 << RAW_PIN_BUTTON_B));
    if (this->b_pressed != pressed) {
      this->b_debounce_count = Input::DEBOUNCE_COUNT;
      this->b_pressed = pressed;
    }
  }

  if (this->up_debounce_count == 0) {
    bool pressed = !(PINC & (1 << RAW_PIN_BUTTON_UP));
    if (this->up_pressed != pressed) {
      this->up_debounce_count = Input::DEBOUNCE_COUNT;
      this->up_pressed = pressed;
    }
  }

  if (this->left_debounce_count == 0) {
    bool pressed = !(PINC & (1 << RAW_PIN_BUTTON_LEFT));
    if (this->left_pressed != pressed) {
      this->left_debounce_count = Input::DEBOUNCE_COUNT;
      this->left_pressed = pressed;
    }
  }

  if (this->down_debounce_count == 0) {
    bool pressed = !(PINC & (1 << RAW_PIN_BUTTON_DOWN));
    if (this->down_pressed != pressed) {
      this->down_debounce_count = Input::DEBOUNCE_COUNT;
      this->down_pressed = pressed;
    }
  }

  if (this->right_debounce_count == 0) {
    bool pressed = !(PINC & (1 << RAW_PIN_BUTTON_RIGHT));
    if (this->right_pressed != pressed) {
      this->right_debounce_count = Input::DEBOUNCE_COUNT;
      this->right_pressed = pressed;
    }
  }
}
