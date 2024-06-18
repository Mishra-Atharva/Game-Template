#include "player.h"

void Player::initVariables()
{

}

void Player::initPlayer()
{
  this->player.setSize(sf::Vector2f(30.f, 20.f));
  this->player.setFillColor(sf::Color::Red);
  this->player.setPosition(sf::Vector2f(20.f, 20.f));
}

Player::Player()
{
  this->initVariables();
  this->initPlayer();
}

void Player::playerMovement(sf::RenderWindow& window)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->player.getPosition().x > 0)
  {
    this->player.move(sf::Vector2f(-10.f, 0.f));
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->player.getPosition().x < (window.getSize().x - this->player.getSize().x))
  {
    this->player.move(sf::Vector2f(10.f, 0.f));
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->player.getPosition().y > 0)
  {
    this->player.move(sf::Vector2f(0.f, -10.f));
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->player.getPosition().y < (window.getSize().y - this->player.getSize().y))
  {
    this->player.move(sf::Vector2f(0.f, 10.f));
  }
}

void Player::update(sf::RenderWindow& window)
{
  this->playerMovement(window);
}

void Player::render(sf::RenderWindow* window)
{
  window->draw(this->player);
}
