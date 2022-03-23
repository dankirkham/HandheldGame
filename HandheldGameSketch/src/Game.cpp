#include "Game.h"

#ifndef ARDUINO
#include <iostream>
Game::~Game() {
  std::cout << "A Game was destroyed!" << std::endl;
}
#else
Game::~Game() {
}
#endif // ARDUINO

games_e Game::getGameToSwitchTo() {
  games_e tmpGame = gameToSwitchTo;

  gameToSwitchTo = games_e::NO_CHANGE;

  return tmpGame;
}
