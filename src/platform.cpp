#include "platform.h"

void Platform::initPlatform()
{
  this->box.setSize(sf::Vector2f(400.f, 20.f));
  this->box.setFillColor(sf::Color::Green);
  this->box.setPosition(sf::Vector2f(20.f, 400.f));
}

Platform::Platform()
{
  this->initPlatform();
}

const sf::RectangleShape& Platform::getShape() const
{
  return this->box;
}

void Platform::render(sf::RenderWindow* window)
{
  window->draw(this->box);
}
