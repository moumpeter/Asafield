#ifndef NPC_H
#define NPC_H
#include "dynamic.h"
#include <SFML/Graphics.hpp>

class NPC: public Dynamic
{
    public:
    // constructor
    NPC();

    // functions
    void handle(const sf::Event&) override;
    void update(sf::Time, std::vector<GameObject*>&) override;
    void render(sf::RenderWindow&) override;
    
};

#endif