#include "player.h"
#include <iostream>

void Player::initVariables()
{
  this->health = 5;
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

void Player::playerMovement(sf::RenderWindow& window, Platform& plat)
{
  static bool pressed = false;
  this->canJump = this->platformCollision(plat);

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

bool Player::platformCollision(Platform& plat)
{
  if(this->player.getGlobalBounds().intersects(plat.getShape().getGlobalBounds()))
  {
    this->physics.resetVelocityY();
    this->player.setPosition(this->player.getPosition().x, plat.getShape().getPosition().y - this->player.getGlobalBounds().height);
    return true;
  }
  else 
  {
    return false;
  }
}

const sf::RectangleShape& Player::getShape() const
{
  return this->player;
}

void Player::update(sf::RenderWindow& window, Platform& plat)
{
  this->playerMovement(window, plat);
  this->physics.updatePhysics();
  this->player.move(this->physics.returnVelocity());
}

void Player::render(sf::RenderWindow* window)
{
  window->draw(this->player);
}
