#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "static.h"
#include <SFML/Graphics.hpp>

class Obstacle : public Static
{
    public:
    //constructor
    Obstacle();

    //functions
    void handle(const sf::Event&) override;
    void update(sf::Time, std::vector<GameObject*>&) override;
    void render(sf::RenderWindow&) override;

};

#endif