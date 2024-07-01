#include "player.h"
#include <iostream>

void Player::initVariables()
{
  this->health = 5;
  this->canJump = false;
}

void Player::initPlayer()
{
  this->player.setSize(sf::Vector2f(30.f, 20.f));
  this->player.setFillColor(sf::Color::Red);
  this->player.setPosition(sf::Vector2f(30.f, 10.f));
}

Player::Player() :physics()
{
  this->initVariables();
  this->initPlayer();
}

void Player::playerMovement(sf::RenderWindow& window, Map& map)
{
  static bool pressed = false;
  this->canJump = false;
  this->platformCollision(map);

  //Left and Right movement
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->player.getPosition().x > 0)
  {
    this->physics.movement(-1.f, 0.f);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->player.getPosition().x < (window.getSize().x - this->player.getSize().x))
  {
    this->physics.movement(1.f, 0.f);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !pressed && this->canJump)
  {
    pressed = true;
    this->physics.jump();
  }

  pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void Player::platformCollision(Map& map)
{
  for(size_t i = 0; i < map.returnShape().size(); i++)
  {
    if(map.returnShape()[i].getGlobalBounds().intersects(this->player.getGlobalBounds()))
    {
      this->physics.resetVelocityY();
      this->player.setPosition(this->player.getPosition().x, map.returnShape()[i].getPosition().y - this->player.getGlobalBounds().height);
      this->canJump = true;
    }
  }
}

const sf::RectangleShape& Player::getShape() const
{
  return this->player;
}

void Player::update(sf::RenderWindow& window, Map& map)
{
  this->playerMovement(window, map);
  this->physics.updatePhysics();
  this->player.move(this->physics.returnVelocity());
}

void Player::render(sf::RenderWindow* window)
{
  window->draw(this->player);
}
