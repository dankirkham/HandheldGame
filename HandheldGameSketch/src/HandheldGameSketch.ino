#include "Brick.h"
#include "Game.h"
#include "Input.h"
#include "Pins.h"
#include "Screen.h"
#include "Snek.h"
#include "Menu.h"
#include "Birb.h"
#include "Tetris.h"
#include "Counter.h"

void *operator new(size_t size, void *ptr)
{
  return ptr;
}

void operator delete(void *ptr, unsigned int size)
{
  for (int i = 0; i < size; i++) *((char*)ptr + i) = 0;
}

int counter;

static char input_buffer[sizeof(Input)];
static Input *input = new (input_buffer) Input;

static char screen_buffer[sizeof(Screen)];
static Screen *screen = new (screen_buffer) Screen();

const auto game_buffer_size = sizeof(Snek) * 2; // Snek is our biggest game
static char game_buffer[game_buffer_size];

// This helps us determine RAM utilization at compile time
#if 0
char (*__kaboom0)[sizeof( Input )] = 1;
char (*__kaboom1)[sizeof( Screen )] = 1;
char (*__kaboom2)[sizeof( Snek )] = 1;
char (*__kaboom3)[sizeof( Brick )] = 1;
char (*__kaboom4)[sizeof( Birb )] = 1;
char (*__kaboom5)[sizeof( Menu )] = 1;
#endif

Game *game = new (game_buffer) Menu(screen, input);

void setup() {
  // Timer config
  counter = game->getDelay();
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
  counter--;
  if (counter == 0) {
    counter = game->getDelay();
    game->tick();
  }

  input->tick();

  screen->draw();

  games_e nextGame = game->getGameToSwitchTo();

  switch (nextGame) {
    case games_e::SNEK:
      delete game;
      game = new (game_buffer) Snek(screen, input);
      break;
    case games_e::BRICK:
      delete game;
      game = new (game_buffer) Brick(screen, input);
      break;
    case games_e::BIRB:
      delete game;
      game = new (game_buffer) Birb(screen, input);
      break;
    case games_e::MENU:
      delete game;
      game = new (game_buffer) Menu(screen, input);
      break;
    case games_e::TETRIS:
      delete game;
      game = new (game_buffer) Tetris(screen, input);
      break;
    case games_e::COUNTER:
      delete game;
      game = new (game_buffer) Counter(screen, input);
      break;
    default:
      break;
  }

  if (nextGame != games_e::NO_CHANGE) {
    game->init();
  }
}

ISR(TIMER0_COMPA_vect) {
}

ISR(PCINT0_vect) {
  input->handleB();
}

ISR(PCINT1_vect) {
  input->handleC();
}
