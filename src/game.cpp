#include "game.h"

void Game::initVariables()
{
  
}

void Game::initWindow()
{
  this->videoMode = sf::VideoMode(600, 600);
  this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
  this->window->setFramerateLimit(60);
}
Game::Game() : player()
{
  this->initVariables();
  this->initWindow();
}

Game::~Game()
{
  delete this->window;
}

void Game::pollEvents()
{
  while(this->window->pollEvent(this->ev))
  {
    switch(this->ev.type)
    {
      case sf::Event::Closed:
        {
          this->window->close();
          break;
        }
      case sf::Event::KeyPressed:
        if(this->ev.key.code == sf::Keyboard::Escape)
        {
          this->window->close();
          break;
        }
    }
  }
}

const bool Game::isRunning() const
{
  return this->window->isOpen();
}

void Game::update()
{
  this->pollEvents();
  this->player.update(*this->window);
}

void Game::render()
{
  this->window->clear();
  this->player.render(this->window);
  this->window->display();
}
