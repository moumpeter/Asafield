#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <stack>
#include <stdexcept>
#include <vector>
#include "game_object.h"
#include "player.h"
#include "enemy.h"

class State
{
    public:
    virtual ~State() = default;
    virtual int handle(sf::Event event, std::stack<State*>& states) = 0;
    virtual void update(sf::Time delta) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

class GameState : public State
{
    public:
    GameState();
    ~GameState();
    int handle(sf::Event event, std::stack<State*>& states) override;
    void update(sf::Time delta) override;
    void render(sf::RenderWindow& window) override;
    private:
    GameObject* p1;
    sf::View view;

    // shouldn't need any of these except gameobjects
    /*std::vector<GameObject*> gameobjects;
    std::vector<GameObject*> new_objects;
    std::vector<GameObject*> projectiles;
    GameObject* player;
    */
    std::vector<GameObject*> gameobjects;
};

class MenuState : public State
{
   public:
    MenuState();
    int handle(sf::Event event, std::stack<State*>& states) override;
    void update(sf::Time delta) override;
    void render(sf::RenderWindow& window) override;

   private:
    std::vector<sf::Text> textobjects;
    sf::Font font;
    //     sf::Text text;
    //     float elapsed_time;
};
    
#endif

