#ifdef ARDUINO

#include "Screen.h"
#include "Pins.h"
#include "Arduino.h"

Screen::Screen() {
  pinMode((int)pin_e::shift_data, OUTPUT);
  pinMode((int)pin_e::shift_clock, OUTPUT);
  pinMode((int)pin_e::shift_latch, OUTPUT);

  pinMode((int)pin_e::decade_reset, OUTPUT);
  pinMode((int)pin_e::decade_clock, OUTPUT);
}

void Screen::draw() {
  // Swap screen and buffer
  char *temp = this->screen;
  this->screen = this->buf;
  this->buf = temp;

  digitalWrite((int)pin_e::decade_reset, HIGH);
  digitalWrite((int)pin_e::shift_data, LOW);
  digitalWrite((int)pin_e::shift_clock, LOW);
  digitalWrite((int)pin_e::shift_latch, LOW);
  digitalWrite((int)pin_e::decade_reset, LOW);
  digitalWrite((int)pin_e::decade_clock, LOW);

  for (int i = 0; i < ROWS; i++) {
    for (int j = COLUMNS - 1; j >= 0; j--) {
      digitalWrite((int)pin_e::shift_data, getPixel(j, i) ? HIGH : LOW);
      //digitalWrite((int)pin_e::shift_data, *(this->screen + i * COLUMNS + j) ? HIGH : LOW);
      digitalWrite((int)pin_e::shift_clock, HIGH);
      digitalWrite((int)pin_e::shift_clock, LOW);
    }

    if (i != 0) {
      PORTD |= (1 << PD2) | (1 << PD4);
    } else {
      digitalWrite((int)pin_e::shift_latch, HIGH);
    }


    digitalWrite((int)pin_e::shift_latch, LOW);
    digitalWrite((int)pin_e::decade_clock, LOW);
  }

  // Last row gets same display time as the other rows
  for (int j = COLUMNS - 1; j >= 0; j--) {
      digitalWrite((int)pin_e::shift_data, LOW);
      digitalWrite((int)pin_e::shift_clock, HIGH);
      digitalWrite((int)pin_e::shift_clock, LOW);
  }

  PORTD |= (1 << PD2) | (1 << PD4);
  digitalWrite((int)pin_e::shift_latch, LOW);
  digitalWrite((int)pin_e::decade_clock, LOW);
}

#endif
