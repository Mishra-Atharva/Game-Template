#include "player.h"
#include <SFML/System/Vector2.hpp>

void Player::initVariables()
{
    this->health = 5;
    this->canJump = false;
}

void Player::initPlayer()
{
    this->player.setSize(sf::Vector2f(20.f, 20.f));
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

//PlayerCollision
void Player::platformCollision(Map& map)
{
    for(size_t i = 0; i < map.returnShape().size(); i++)
    {
        float enemy_x = map.returnShape()[i].getPosition().x;
        float enemy_y = map.returnShape()[i].getPosition().y;
        float e_height = 20.f;
        float e_width = 20.f;

        float player_x = this->player.getPosition().x;
        float player_y = this->player.getPosition().y;
        float p_height = 20.f;
        float p_width = 30.f;
        // Check if player is horizontally overlapping with the platform
        bool isOverlappingHorizontally = (player_x + p_width > enemy_x && player_x < enemy_x + e_width);
        
        if (isOverlappingHorizontally)
        {
            // Check if the player is landing on top of the platform
            if (player_y + p_height > enemy_y && player_y < enemy_y && this->physics.returnVelocity().y > 0)
            {
                this->physics.resetVelocityY();
                this->player.setPosition(player_x, enemy_y - p_height);
                this->canJump = true;
            }
            // Check if the player is hitting the bottom of the platform
            else if (player_y < enemy_y + e_height && player_y + p_height > enemy_y + e_height && this->physics.returnVelocity().y < 0)
            {
                this->physics.resetVelocityY();
                this->player.setPosition(player_x, enemy_y + e_height);
            }
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
