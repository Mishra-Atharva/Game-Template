#pragma once
#include <SFML/Graphics.hpp>

class Physics
{
private:
    sf::Vector2f velocity; //(x, y)
    float velocityMax; //max speed x
    float velocityMaxY; //max speed y-direction
    float velocityMin; //min speed
    float acceleration; //added speed
    float gravity; //Gravity i wonder what it could be
    float drag; //Slow down speed

    void initPhysics();

public:
    Physics();

    const sf::Vector2f& returnVelocity() const;
    void movement(const float dirX, const float dirY);
    void jump();
    void updatePhysics();
    void resetVelocityY();
    void resetVelocityX();

    void update();
};
