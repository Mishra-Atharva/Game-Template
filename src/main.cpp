#include "game.h"

int main()
{
  Game game;

  while(game.isRunning())
  {
    game.update();
    game.render();
  }
}