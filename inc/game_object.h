#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class GameObject
{
public:
    //constructors
    GameObject(const std::string& file_path, float width, float height, sf::Vector2f pos);

    //destructors
    virtual ~GameObject() = default;

    //functions
    virtual void handle(const sf::Event& event);
    virtual void update(sf::Time delta);
    virtual void render(sf::RenderWindow& window);
    virtual bool collides(GameObject*& other); // dont know if this should be a reference or not and possibly a const.
    virtual void handle_collision();
    sf::Vector2f get_pos();
protected:
    const std::string file_path;
    sf::Texture texture;    
    std::unique_ptr<sf::Sprite> sprite;    
    float width;
    float height;
    sf::Vector2f pos;

};

#endif
