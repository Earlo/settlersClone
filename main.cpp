
#include <iostream>
#include <SFML/Graphics.hpp>

//#include "Tile.h"
#include "src/mapGen/Map.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::View view1(sf::FloatRect(0, 0, 600, 600));
    window.setView(view1);
    
    int camX = 0;
    int camY = 0;
    
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
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            camX = std::min(std::max(0,camX-1),500*16);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            camX = std::min(std::max(0,camX+1),500*16);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            camY = std::min(std::max(0,camY-1),500*16);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            camY = std::min(std::max(0,camY+1),500*16);
        }
        view1.setCenter (camX + 300, camY + 300);
        window.clear();

        for ( unsigned int x = 0; x < (600/16)+3; x++){
            for ( unsigned int y = 0; y < (600/16)+3; y++){
                int dx = x + camX/16;
                int dy = y + camY/16;
                if( dx > 0 && dx < 500 && dy > 0 && dy < 500){
                    window.draw(m.at(dx,dy).shape);
                }
            }
        }
        window.setView(view1);
        window.display();
    }

    return 0;
}
