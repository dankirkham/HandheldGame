#include "Snek.h"
#include "Pins.h"
#include "Input.h"
#include "Screen.h"

int counter;
Input *input = new Input();
Screen *screen = new Screen();
Snek *snek = new Snek(screen, input);

void setup() {
  // Timer config
  counter = Snek::DELAY;
  TCCR0A = (1<<WGM01); // CTC mode
  OCR0A = 0xF9; // 1 ms
  TIMSK0 |= (1<<OCIE0A); // Interrupt enable
  TCCR0B |= (1<<CS01) | (1<<CS00); // 1/64 prescale
  sei(); // Global interrupt enable
}

void loop() {}

ISR(TIMER0_COMPA_vect) {
  counter--;
  if (counter == 0) {
    counter = Snek::DELAY;
    snek->tick();
  }

  screen->draw();
}
