#include "Executor.h"
#include "Pins.h"

void setup() {
  // Timer config
  TCCR0A = (1<<WGM01); // CTC mode
  OCR0A = 0xF9; // 1 ms
  TIMSK0 |= (1<<OCIE0A); // Interrupt enable
  TCCR0B |= (1<<CS01) | (1<<CS00); // 1/64 prescale

  // Button interrupt config
  // PCICR - Enable interrupts on Port C
  PCICR = (1<<PCIE1) | (1<<PCIE0);
  // PCMSK - Mask bits that correspond to a button press
  PCMSK0 = (1<<PCINT2) | (1<<PCINT1);
  PCMSK1 = (
    (1<<PCINT13) | (1<<PCINT12) | (1<<PCINT11) |
    (1<<PCINT10) | (1<<PCINT9) | (1<<PCINT8)
  );

  sei(); // Global interrupt enable
}

void loop() {
}

ISR(TIMER0_COMPA_vect) {
  Executor::tick();
}

ISR(PCINT0_vect) {
  Executor::input->handleB();
}

ISR(PCINT1_vect) {
  Executor::input->handleC();
}
