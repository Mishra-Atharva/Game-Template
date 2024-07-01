#pragma once
#include <SFML/Graphics.hpp>
#include "physics.h"
#include "map.h"

class Player
{
private:
  int health;
  sf::RectangleShape player;

  bool canJump;

  void initVariables();
  void initPlayer();

  Physics physics;

public:
  Player();

  void playerMovement(sf::RenderWindow& window, Map& map);
  void platformCollision(Map& map);
  const sf::RectangleShape& getShape() const;

  void update(sf::RenderWindow& window, Map& map);
  void render(sf::RenderWindow* window);
};
