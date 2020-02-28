#include "Input.h"
#include "Pins.h"
#include "Arduino.h"

bool Input::keyDown(int key) {
  return !digitalRead(key);
}
