#include "Game.h"

games_e Game::getGameToSwitchTo() {
  games_e tmpGame = gameToSwitchTo;

  gameToSwitchTo = games_e::NO_CHANGE;

  return tmpGame;
}
