#include "Screen.h"
#include "Pins.h"
#include "Arduino.h"

Screen::Screen() {
  pinMode(PIN_SHIFT_DATA, OUTPUT);
  pinMode(PIN_SHIFT_CLOCK, OUTPUT);
  pinMode(PIN_SHIFT_LATCH, OUTPUT);

  pinMode(PIN_DECADE_RESET, OUTPUT);
  pinMode(PIN_DECADE_CLOCK, OUTPUT);
}

void Screen::draw() {
  // Swap screen and buffer
  bool *temp = this->screen;
  this->screen = this->buf;
  this->buf = temp;

  digitalWrite(PIN_DECADE_RESET, HIGH);
  digitalWrite(PIN_SHIFT_DATA, LOW);
  digitalWrite(PIN_SHIFT_CLOCK, LOW);
  digitalWrite(PIN_SHIFT_LATCH, LOW);
  digitalWrite(PIN_DECADE_RESET, LOW);
  digitalWrite(PIN_DECADE_CLOCK, LOW);

  for (int i = 0; i < ROWS; i++) {
    for (int j = COLUMNS - 1; j >= 0; j--) {
      digitalWrite(PIN_SHIFT_DATA, *(this->screen + i * COLUMNS + j) ? HIGH : LOW);
      digitalWrite(PIN_SHIFT_CLOCK, HIGH);
      digitalWrite(PIN_SHIFT_CLOCK, LOW);
    }

    if (i != 0) {
      PORTD |= (1 << PD2) | (1 << PD4);
    } else {
      digitalWrite(PIN_SHIFT_LATCH, HIGH);
    }


    digitalWrite(PIN_SHIFT_LATCH, LOW);
    digitalWrite(PIN_DECADE_CLOCK, LOW);
  }

  // Last row gets same display time as the other rows
  for (int j = COLUMNS - 1; j >= 0; j--) {
      digitalWrite(PIN_SHIFT_DATA, LOW);
      digitalWrite(PIN_SHIFT_CLOCK, HIGH);
      digitalWrite(PIN_SHIFT_CLOCK, LOW);
  }

  PORTD |= (1 << PD2) | (1 << PD4);
  digitalWrite(PIN_SHIFT_LATCH, LOW);
  digitalWrite(PIN_DECADE_CLOCK, LOW);
}

void Screen::erase() {
  for (int i = 0; i < ROWS * COLUMNS; i++) {
      *(this->buf + i) = false;
  }
}

bool* Screen::getBuffer() {
  return this->buf;
}
