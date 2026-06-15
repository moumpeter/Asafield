#include "enemy.h"
#include <iostream>

BirdEnemy::BirdEnemy(const std::string& file_path, float width, float height, sf::Vector2f pos, float speed,float radius)
    :Enemy{file_path, width, height, pos, speed}, radius{radius}, timer{}, direction{1}, start_pos{}
    {
        start_pos = pos;
        sf::Vector2u texture_size{texture.getSize()};
        float scale_x = width / texture_size.x;
        float scale_y = height / texture_size.y;
        sprite->setScale({ scale_x * -1, scale_y });
    }

void BirdEnemy::handle(const sf::Event& event)
{}

void BirdEnemy::update(sf::Time delta)
{
    movement(delta);
    sprite -> setPosition(pos);
    animation(delta);
    
    //std::cout<<"Current Pos: "<< pos.x << std::endl;
}

void BirdEnemy::render(sf::RenderWindow& window)
{
    window.draw(*sprite);
}

void BirdEnemy::animation(sf::Time delta)
{
    if(timer <= 0.25)
    {
        if (!texture.loadFromFile("textures/Bird/Bird_1.png"))
        {
            throw std::runtime_error("Kunde inte ladda textures/Bird_1.png ");
        }
    }
    if (timer > 0.5)
    {
        if (!texture.loadFromFile("textures/Bird/Bird_2.png"))
        {
            throw std::runtime_error("Kunde inte ladda textures/Bird/Bird_2.png");
        }
    }
    if (timer > 0.75)
    {
        if (!texture.loadFromFile("textures/Bird/Bird_3.png"))
        {
            throw std::runtime_error("Kunde inte ladda textures/Bird_3.png");
        }
    }
    if (timer > 1)
    {
        if (!texture.loadFromFile("textures/Bird/Bird_4.png"))
        {
            throw std::runtime_error("Kunde inte ladda textures/Bird/Bird_4.png");
        }
    }
    if(timer >= 1.25)
    {
        timer = 0;
    }
    timer += delta.asSeconds();
    

}
void BirdEnemy::movement(sf::Time delta)
{
    sf::Vector2u texture_size{texture.getSize()};
    float scale_x = width / texture_size.x;
    float scale_y = height / texture_size.y;
    sf::Vector2f old_pos{pos};
    float distance{delta.asSeconds()*speed};    
    
    if(pos.x >= start_pos.x + radius)
    {
        direction = -1;
        sprite->setScale({ scale_x, scale_y });
    }
    
    if(pos.x<= start_pos.x - radius)
    {
        direction = 1;
        sprite->setScale({ scale_x * -1, scale_y });
    }
    
    pos.x += distance*direction;

    //std::cout<< "Old Position: " <<old_pos.x <<std::endl;
    
    
}