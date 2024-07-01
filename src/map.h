#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Map
{
private:
  sf::RectangleShape box;
  std::vector<sf::RectangleShape> layout;
  std::vector<int> map;
  std::vector<int> newMap;

  void initVariables();
  void initBox();
  void initLayout();

public:
  Map();

  const std::vector<sf::RectangleShape>& returnShape() const;
  void update();
  void render(sf::RenderWindow* window);
};
