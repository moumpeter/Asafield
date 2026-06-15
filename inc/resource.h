#ifndef RESOURCE_H
#define RESOURCE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Resource
{
public:
    static sf::Texture &get(const std::string &filename);
    static void clear();
    

private:
};
#endif