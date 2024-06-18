#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
  int health;
  sf::RectangleShape player;
  
  void initVariables();
  void initPlayer();

public:
  Player();

  void playerMovement(sf::RenderWindow& window);

  void update(sf::RenderWindow& window);
  void render(sf::RenderWindow* window);
};
