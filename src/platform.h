#pragma once
#include <SFML/Graphics.hpp>

class Platform
{
private:
  sf::RectangleShape box;
  
  void initPlatform();

public:
  Platform();
  
  const sf::RectangleShape& getShape() const;

  void render(sf::RenderWindow* window);
};
