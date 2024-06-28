#pragma once
#include <SFML/Graphics.hpp>

class Physics
{
private:
  sf::Vector2f velocity;
  float velocityMax;
  float velocityMaxY;
  float velocityMin;
  float acceleration;
  float gravity;
  float drag;

  void initPhysics();

public:
  Physics();

  const sf::Vector2f& returnVelocity() const;
  void movement(const float dirX, const float dirY);
  void jump();
  void updatePhysics();
  void resetVelocityY();

  void update();
};
