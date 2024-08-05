#include "physics.h"

void Physics::initPhysics()
{
    this->velocityMax = 9.f;
    this->velocityMin = 1.f;
    this->velocityMaxY = 25.f;
    this->acceleration = 3.f;
    this->gravity = 2.f;
    this->drag = 0.73f;
}

Physics::Physics()
{
    this->initPhysics();
}

const sf::Vector2f& Physics::returnVelocity() const
{
    return this->velocity;
}

void Physics::movement(const float dirX, const float dirY)
{
    this->velocity.x += dirX * this->acceleration;

    if(std::abs(this->velocity.x) > this->velocityMax)
    {
        this->velocity.x = this->velocityMax * ((this->velocity.x < 0) ? -1.f : 1.f);
    }
}

void Physics::jump()
{
    this->velocity.y = -250.f;
}

void Physics::updatePhysics()
{
    this->velocity.y += 1.f * this->gravity;

    if(std::abs(this->velocity.y) > this->velocityMaxY)
    {
        this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0) ? -1.f : 1.f);
    }

    this->velocity *= this->drag;

    if(std::abs(this->velocity.x) < this->velocityMin)
    {
        this->velocity.x = 0.f;
    }

    if(std::abs(this->velocity.y) < this->velocityMin)
    {
        this->velocity.y = 0.f;
    }
}

void Physics::resetVelocityY()
{
    this->velocity.y = 0.f;
}

void Physics::resetVelocityX()
{
    this->velocity.x = 0.f;
}

void Physics::update()
{
    this->updatePhysics();
}
