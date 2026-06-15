#ifndef ENEMY_H
#define ENEMY_H
#include "dynamic.h"
#include <SFML/Graphics.hpp>
class Enemy: public Dynamic
{
    public:
    //constructors
    Enemy();


    //functions
    void handle(const sf::Event&) override;
    void update(sf::Time, std::vector<GameObject*>&) override;
    void render(sf::RenderWindow&) override;


};

#endif