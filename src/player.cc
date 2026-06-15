#include "player.h"

Player::Player(const std::string& file_path, float width, float height, sf::Vector2f pos, float speed)
    :Dynamic{file_path, width, height, pos, speed}, timer{}
    {}

void Player::handle(const sf::Event& event)
{

}

void Player::update(sf::Time delta)
{

    // TODO: implement gravity.

    movement(delta);
    sprite -> setPosition(pos);
    animation(delta);
    
}

void Player::render(sf::RenderWindow& window)
{
    window.draw(*sprite);
}

void Player::movement(sf::Time delta)
{
    sf::Vector2u texture_size{texture.getSize()};
    float scale_x = width / texture_size.x;
    float scale_y = height / texture_size.y;
    float distance{delta.asSeconds()*speed};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        pos.x += distance;
        sprite->setScale({ scale_x, scale_y });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        
        sprite->setScale({ scale_x * -1, scale_y });
        pos.x -= distance;

    }
}
void Player::animation(sf::Time delta)
{
    if(timer <= 0.25/2)
    {
        if (!texture.loadFromFile("textures/Character_idle1.png"))
        {
            throw std::runtime_error("Kunde inte ladda textures/Character.png ");
        }
    }
    if (timer > 0.5/2)
    {
        if (!texture.loadFromFile("textures/Character_idle2.png"))
        {
            throw std::runtime_error("Kunde inte ladda textures/Character_idle2.png");
        }
    }
    if(timer >= 0.75/2)
    {
        timer = 0;
    }
    timer += delta.asSeconds();

}
