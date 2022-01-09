#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::E) {
                    std::cout << "EEEEEE" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::C) {

                    int r = std::rand() % 255;
                    int g = std::rand() % 255;
                    int b = std::rand() % 255;

                    shape.setFillColor(sf::Color(r, g, b));
                }
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}