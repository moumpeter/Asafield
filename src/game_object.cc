#include "game_object.h"
#include <SFML/Graphics.hpp>

GameObject::GameObject(const std::string& file_path, float width, float height, sf::Vector2f pos)
    : file_path{file_path},  width{width}, height{height}, pos{pos}
    {
        if (!texture.loadFromFile(file_path))
        {
            throw std::runtime_error("Kunde inte ladda " + file_path);
        }
        sprite = std::make_unique<sf::Sprite>(texture);
        // learn about making custome hitboxes but a normal box for now.
        sf::Vector2u texture_size{texture.getSize()};
        float scale_x = width / texture_size.x;
        float scale_y = height / texture_size.y;
        sprite -> setScale({ scale_x, scale_y });
        sprite -> setOrigin({ texture_size.x / 2.f, texture_size.y / 2.f });
        sprite -> setPosition(pos);

    }

void GameObject::handle(const sf::Event& event)
{}

void GameObject::update(sf::Time delta)
{}

void GameObject::render(sf::RenderWindow& window)
{}

void GameObject::handle_collision() // this needs to be defined in children classes.
{}

bool GameObject::collides(GameObject*& other)
{
    return sprite -> getGlobalBounds()
        .findIntersection(other->sprite -> getGlobalBounds())
        .has_value(); // maybe needs to be global bounds
}
sf::Vector2f GameObject::get_pos()
{
    return pos;
}

