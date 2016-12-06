
#include <iostream>
#include <SFML/Graphics.hpp>

//#include "Tile.h"
#include "src/mapGen/Map.h"


#include "constants.h"
#include "src/Game.h"

//TODO DO THIS SOMEWHERE ELSE
#include "src/Building.h"

bool sortByY (Building i,Building j) { return (i.get_y_position()<j.get_y_position()); }


int main()
{

    sf::RenderWindow window(sf::VideoMode(SCREENX, SCREENY), "SFML works!");
    sf::View view1(sf::FloatRect(0, 0, VIEWX, VIEWY));
    window.setView(view1);
    window.setFramerateLimit(60);
    
    int camX = 0;
    int camY = 0;
    Map m = Map(WORLDX,WORLDY);

    //TODO dont sort here
    std::sort (m.stuff.begin(), m.stuff.end(), sortByY);

    std::cout<< m.w  <<","<< m.w<< std::endl;

    Game g = Game(m.stuff);

    //just testing
    sf::Clock clock;
    float lastTime = clock.getElapsedTime().asSeconds();
    float currentTime = clock.getElapsedTime().asSeconds();
    float fps = 1.0;

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
        //Draw terrain
        window.draw(m.sprite);
	    //Draw objects
    	g.draw(window,view1);
        window.setView(view1);
        window.display();
    
        currentTime = clock.getElapsedTime().asSeconds();
        fps = 1.f / (currentTime - lastTime);
        //window.setTitle(std::to_string(fps));
        lastTime = currentTime;
        //std::cout<<fps<<std::endl;

    }

    return 0;
}
