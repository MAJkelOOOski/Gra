#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ground.h"
#include "Player.h"
#include "Auta.h"
#include "Background.h"
#include "Respawn.h"


#define width 1500
#define height 1100
#define startpos 1000;

Background SetBackground(sf::Texture &tekstura, sf::Texture &finish)
{
   auto init = Background::init(tekstura,finish, sf::Vector2f(width, height), 
        100, TypeOfGround::asphalt, sf::Vector2f(0, 0));
    Background background(init, sf::Vector2f(0,0));
    background.SetInOrder();
    return background;
}

Respawn SetRespawn(sf::Texture& tekstura, sf::Vector2f pos)
{
    std::vector<sf::Texture*> g;
    g.emplace_back(new sf::Texture(tekstura));
    g.emplace_back(new sf::Texture(tekstura));

    auto init = Respawn::init(g, sf::Vector2f(width, height), pos);

    Respawn respawn(init, sf::Vector2f(0, 0));
    return respawn;
}


int main() 
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Crossyroad");
    sf::Event event;
    window.setFramerateLimit(60);

    sf::Texture grass;
    grass.loadFromFile("Assets/grass.png");

    sf::Texture road;
    road.loadFromFile("Assets/road.png");
    Background b1 = SetBackground(road, grass);

    sf::Texture texplayer;
    texplayer.loadFromFile("Assets/Auto1.png");
    Player player(texplayer, sf::Vector2f(750, 1050));

    Respawn respawn = SetRespawn(texplayer, sf::Vector2f(0, 0));

    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            player.Control(event);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        b1.Draw(window);
        player.draw(window);
        respawn.Draw(window);
        

        // end the current frame
        window.display();
    }
    

    return 0;
}