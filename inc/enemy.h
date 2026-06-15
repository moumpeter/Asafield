#ifndef ENEMY_H
#define ENEMY_H
#include "dynamic.h"
#include <SFML/Graphics.hpp>
class Enemy: public Dynamic
{
    public:
    //constructors
    Enemy(const std::string& file_path, float width, float height, sf::Vector2f pos, float speed);


    //functions


};
class BirdEnemy
    : public Enemy
{
public:
    //constructors
    BirdEnemy(const std::string& file_path, float width, float height, sf::Vector2f pos, float speed, float radius);

    // functions
    void handle(const sf::Event&) override;
    void update(sf::Time) override;
    void render(sf::RenderWindow&) override;
    void animation(sf::Time) override;
    void movement(sf::Time) override;

private:
    float radius;
    float timer;
    float direction;
    sf::Vector2f start_pos;

};

#endif