#pragma once
#include <SFML/Graphics.hpp>
#include "platform.h"
#include "physics.h"

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

  void playerMovement(sf::RenderWindow& window, Platform& plat);
  bool platformCollision(Platform& plat);
  const sf::RectangleShape& getShape() const;

  void update(sf::RenderWindow& window, Platform& plat);
  void render(sf::RenderWindow* window);
};
