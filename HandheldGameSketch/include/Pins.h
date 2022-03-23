#ifndef Pins_h
#define Pins_h

#ifdef ARDUINO
#include "Arduino.h"
#else
#define A0 11
#define A1 12
#define A2 13
#define A3 14
#define A4 15
#define A5 16
#endif

//#define PIN_SHIFT_DATA 0 // PD0
//#define PIN_SHIFT_CLOCK 1 // PD1
//#define PIN_SHIFT_LATCH 2 // PD2
//#define PIN_DECADE_RESET 3 // PD3
//#define PIN_DECADE_CLOCK 4 // PD4
//#define PIN_BUTTON_START 9 // PB1
//#define PIN_BUTTON_SELECT 10 // PB2
//#define PIN_BUTTON_A A0 // PC0
//#define PIN_BUTTON_B A1 // PC1
//#define PIN_BUTTON_UP A2 // PC2
//#define PIN_BUTTON_LEFT A3 // PC3
//#define PIN_BUTTON_DOWN A4 // PC4
//#define PIN_BUTTON_RIGHT A5 // PC5

enum class pin_e : char {
  shift_data = 0, // PD0
  shift_clock = 1, // PD1
  shift_latch = 2, // PD2
  decade_reset = 3, // PD3
  decade_clock = 4, // PD4
  button_start = 9, // PB1
  button_select = 10, // PB2
  button_a = A0, // PC0
  button_b = A1, // PC1
  button_up = A2, // PC2
  button_left = A3, // PC3
  button_down = A4, // PC4
  button_right = A5 // PC5
};

enum class button_e : char {
  start = 0,
  select = 1,
  a = 2,
  b = 3,
  up = 4,
  left = 5,
  down = 6,
  right = 7,
  button_count = 8
};

button_e to_button(pin_e);

#define RAW_PIN_BUTTON_START 1
#define RAW_PIN_BUTTON_SELECT 2

#define RAW_PIN_BUTTON_A 0
#define RAW_PIN_BUTTON_B 1
#define RAW_PIN_BUTTON_UP 2
#define RAW_PIN_BUTTON_LEFT 3
#define RAW_PIN_BUTTON_DOWN 4
#define RAW_PIN_BUTTON_RIGHT 5

#endif
