#include "Executor.h"

#ifdef ARDUINO
void *operator new(size_t size, void *ptr)
{
  return ptr;
}

void operator delete(void *ptr, unsigned int size)
{
  for (int i = 0; i < size; i++) *((char*)ptr + i) = 0;
}
#endif

Input* Executor::input = new INPUT_BUFFER Input();
Screen* Executor::screen = new SCREEN_BUFFER Screen();
Game* Executor::game = new GAME_BUFFER Menu(screen, input);
int Executor::counter = game->getDelay();

void Executor::tick() {
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
      //delete game;
      game = new GAME_BUFFER Snek(screen, input);
      break;
    case games_e::BRICK:
      //delete game;
      game = new GAME_BUFFER Brick(screen, input);
      break;
    case games_e::BIRB:
      //delete game;
      game = new GAME_BUFFER Birb(screen, input);
      break;
    case games_e::MENU:
      //delete game;
      game = new GAME_BUFFER Menu(screen, input);
      break;
    case games_e::TETRIS:
      //delete game;
      game = new GAME_BUFFER Tetris(screen, input);
      break;
    case games_e::PONG:
      //delete game;
      game = new GAME_BUFFER Pong(screen, input);
      break;
    case games_e::COUNTER:
      //delete game;
      game = new GAME_BUFFER Counter(screen, input);
      break;
    default:
      break;
  }

  if (nextGame != games_e::NO_CHANGE) {
    game->init();
  }
}
