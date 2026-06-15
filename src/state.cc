
#include "state.h"
#include "game_object.h"

GameState::GameState()
{  
    
    // magic numbers as of right now need to use json to fix this. 
    p1 = new Player{"textures/Character.png", 64*4, 64*4, {200, 200}, 200};
    /*  TODO: Need to make a camera follow player.
    sf::Vector2u screen_size{ sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height};
    sf::Vector2f screen_size_f{screen_size};
    view(p1 -> get_pos(), screen_size_f);
    //player1View.setViewport(sf::FloatRect({0.f, 0.f}, {0.5f, 1.f}));
    */

    
   
   
   
    //gameobjects.push_back(p1);
    //gameobjects.push_back(new Player{{500,600}});
}

GameState::~GameState()
{
    
    /*while (!gameobjects.empty())
    {
        delete gameobjects.back();
        gameobjects.pop_back();
    }
   
        */
    delete p1;

}
int GameState::handle(sf::Event event, std::stack<State*>& states)
{
    if (const auto* keyEvent = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyEvent->code == sf::Keyboard::Key::Escape)
        {
            states.pop();
        }
    }

    return 0;
}

void GameState::update(sf::Time delta)
{
    p1->update(delta);
    //std::vector<GameObject*> new_objects{};
    /*player -> update(delta, new_objects);
    for (auto object : projectiles)
    {
        object->update(delta, new_objects);

    }
    //for (auto object: new_objects)
    //{
    //    object -> update(delta, new_objects);
    //}
    for (auto enemy: gameobjects)
    {
        
        enemy -> update(delta, new_objects);
        
    }
    */

    // TODO: Kolla kollisioner
    // for ()
    // {
    // }

    // Döda objekt, loopar baklänges för att undvika index-problem
    /*for (unsigned int i = projectiles.size(); i-- > 0;)
    {
        if (projectiles[i]->is_dead() ||(projectiles[i] -> get_pos().y <0))
        {
            delete projectiles[i];
            projectiles.erase(projectiles.begin() + i);
        }
    }*/

    // Lägg till nya objekt sist
    /*for (auto new_object : new_objects)
    {
        // Lägg till det nya objektet
        projectiles.push_back(new_object);
    }*/
   
}

void GameState::render(sf::RenderWindow& window)
{
   /* player -> render(window);
    for (auto projectile : projectiles)
    {
        projectile->render(window);
    }
     
    for(auto enemy: gameobjects)
    {
        enemy -> render(window);
    }
    
    */
   p1 -> render(window);
   //window.setView(view);
}



MenuState::MenuState()
    : textobjects{}, font{}
    // : font{}, text{}, elapsed_time{0.0f}
{

    if (!font.openFromFile("assets/font.ttf"))
    {
        throw std::runtime_error{ "Kan inte öppna: font.ttf" };
    }

    sf::Text text(font, "Press <Enter> to start!", 30);
    auto mode = sf::VideoMode::getDesktopMode();

    sf::FloatRect bounds = text.getLocalBounds();

    text.setOrigin({ bounds.position.x + bounds.size.x / 2.f, bounds.position.y + bounds.size.y / 2.f });
    text.setPosition({mode.size.x / 2.f, mode.size.y / 2.f});

    // Pusha texten för att rendera den
    textobjects.push_back(text);
}

int MenuState::handle(sf::Event event, std::stack<State*>& states)
{
    if (const auto* keyEvent = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyEvent -> code == sf::Keyboard::Key::Enter)
        {
            states.push(new GameState());
        }
    }
    return 0;
    
}

void MenuState::update(sf::Time delta)
{
}

void MenuState::render(sf::RenderWindow& window)
{
    for (const auto& text : textobjects)
    {
        window.draw(text);
    }
}