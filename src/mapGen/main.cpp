
#include <iostream>
#include <SFML/Graphics.hpp>

//#include "Tile.h"
#include "Map.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape shape(10.f);
    //shape.setFillColor(sf::Color::Green);
    Map m = Map(500,500);

    std::cout<< m.w  <<","<< m.w<< std::endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        for ( unsigned int x = 0; x < m.w; x++){
            for ( unsigned int y = 0; y < m.h; y++){
                window.draw(m.at(x,y).shape);
            }
        }
        window.display();
    }

    return 0;
}
