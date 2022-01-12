#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include"Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1250, 700), "Test Game");
    
    Player player;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            player.handleInput(event);
        }



        window.clear();

        sf::sleep(sf::milliseconds(15));

        player.update();
        player.render(window);
        window.display();
    }

    return 0;
}