
#include <iostream>
#include <SFML/Graphics.hpp>

//#include "Tile.h"
#include "src/mapGen/Map.h"
#include "constants.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(SCREENX, SCREENY), "SFML works!");
    sf::View view1(sf::FloatRect(0, 0, VIEWX, VIEWY));
    window.setView(view1);
    
    int camX = 0;
    int camY = 0;
    Map m = Map(WORLDX,WORLDY);

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
            camX = std::min(std::max(0,camX-MOVSPEED),SCROLLX);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            camX = std::min(std::max(0,camX+MOVSPEED),SCROLLX);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            camY = std::min(std::max(0,camY-MOVSPEED),SCROLLY);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            camY = std::min(std::max(0,camY+MOVSPEED),SCROLLY);
        }
        view1.setCenter (camX + CAMCENTERX, camY + CAMCENTERY);
        window.clear();
        
        window.draw(m.sprite);

        window.setView(view1);
        window.display();
    }

    return 0;
}
