#ifndef PLAYER_H
#define PLAYER_H

#include "dynamic.h"
#include <SFML/Graphics.hpp>

class Player: public Dynamic
{
    public:
    //constructors
    Player(const std::string& file_path, float width, float height, sf::Vector2f pos, float speed);

    //functions
    void handle(const sf::Event& event) override;
    void update(sf::Time delta) override;
    void render(sf::RenderWindow& window) override;
    void movement(sf::Time delta) override;
    void animation(sf::Time delta) override;

    private:
    float timer;

};

#endif