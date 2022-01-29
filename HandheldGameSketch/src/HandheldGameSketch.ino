#include "Brick.h"
#include "Game.h"
#include "Input.h"
#include "Pins.h"
#include "Screen.h"
#include "Snek.h"
#include "Menu.h"

int counter;
int input_counter;
Input *input = new Input();
Screen *screen = new Screen();
Snek *snek = new Snek(screen, input);
Brick *brick = new Brick(screen, input);
Menu *menu = new Menu(screen, input);
Game *game = menu;

void setup() {
  // Timer config
  counter = game->getDelay();
  input_counter = Input::DELAY;
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

void loop() {}

ISR(TIMER0_COMPA_vect) {
  counter--;
  if (counter == 0) {
    counter = game->getDelay();
    game->tick();
  }

  input_counter--;
  if (input_counter == 0) {
    input_counter = Input::DELAY;
    input->tick();
  }

  screen->draw();

  games_e nextGame = game->getGameToSwitchTo();

  switch (nextGame) {
    case games_e::SNEK:
      game = snek;
      break;
    case games_e::BRICK:
      game = brick;
      break;
    case games_e::MENU:
      game = menu;
      break;
    default:
      break;
  }

  if (nextGame != games_e::NO_CHANGE) {
    game->init();
  }
}

ISR(PCINT0_vect) {
  input->handleB();
}

ISR(PCINT1_vect) {
  input->handleC();
}
