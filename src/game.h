#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"

class Game
{
private:
  sf::VideoMode videoMode;
  sf::RenderWindow* window;
  sf::Event ev;

  void initVariables();
  void initWindow();

  //Classes
  Player player;

public:
  Game();
  virtual ~Game();
  const bool isRunning() const;

  void pollEvents();

  void update();
  void render();
};
