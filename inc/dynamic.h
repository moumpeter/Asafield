#ifndef DYNAMIC_H
#define DYNAMIC_H
#include <SFML/Graphics.hpp>
#include "game_object.h"

class Dynamic : public GameObject
{
    public:

    //constructors
    Dynamic(const std::string& file_path, float width, float height, sf::Vector2f pos, float speed);

    //destructors
    virtual ~Dynamic() = default;

    //functions

    virtual void movement(sf::Time delta) = 0;
    virtual void animation(sf::Time delta) = 0;


    //virtual void animation(); // maybe needs to be a class with a vector of textures as argument
    // which can be read from json file

    protected:
    float speed;
    
};

#endif