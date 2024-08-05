#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
#include "map.h"

class Game
{
private:

    sf::CircleShape spawnLine;
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event ev;

    void initVariables();
    void initWindow();

    //Classes
    Player player;
    Map map;

public:
    Game();
    virtual ~Game();
    const bool isRunning() const;

    void pollEvents();

    void update();
    void render();
};
