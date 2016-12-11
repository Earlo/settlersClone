
#include <iostream>
#include <SFML/Graphics.hpp>

//#include "Tile.h"
#include "src/mapGen/Map.h"
#include "src/logic/SpatialHash.h"


#include "constants.h"
#include "src/Game.h"

//TODO DO THIS SOMEWHERE ELSE
#include "src/Entity.h"
#include "src/Settler.h"
#include "src/Fortress.h"

#include "src/logic/HumanPlayer.h"

bool sortByY (Entity i,Entity j) { return (i.get_y_position()<j.get_y_position()); }


int main()
{

    sf::RenderWindow window(sf::VideoMode(SCREENX, SCREENY), "SFML works!");
    sf::View view1(sf::FloatRect(0, 0, VIEWX, VIEWY));
    window.setView(view1);
    window.setFramerateLimit(60);
    

    bool initted = false;

    int camX = 0;
    int camY = 0;
    Map m = Map(WORLDX,WORLDY);
    HumanPlayer p = HumanPlayer();
    //TODO dont sort here
    std::sort (m.stuff.begin(), m.stuff.end(), sortByY);

    Game g = Game(m.stuff);

    SHASH.initHash( m );

    //just testing
    //sf::Clock clock;
    //float lastTime = clock.getElapsedTime().asSeconds();
    //float currentTime = clock.getElapsedTime().asSeconds();
    //float fps = 1.0;

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
	    
        if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left && !initted) {
            
           
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            

            //int xpx = (pos.x + camX)/DRAWSIZE;
            //int ypx = (pos.y + camY)/DRAWSIZE;
            /*
            std::cout << xpx << ","<< ypx << " -> ";
            std::cout << (xpx)/HASHRES << ";"<< (ypx)/HASHRES << std::endl;
            std::cout<<SHASH.WEIGHT[(xpx)/HASHRES][(ypx)/HASHRES]<<std::endl;
            */
        	
            Fortress fortress(pos.x + camX, pos.y + camY);
            Settler setl0(pos.x + camX, pos.y + camY + 10);
            Settler setl1(pos.x + camX, pos.y + camY + 10);
            p.settlers.push_back(setl0);
            p.settlers.push_back(setl1);
            //p.tasks.push_back( );

    		std::vector<Entity>& builds = g.get_entities();
            builds.push_back(fortress);
            builds.push_back(setl0);
            builds.push_back(setl1);

            initted = true;
            
            }
        window.clear();
        //Draw terrain
        window.draw(m.sprite);
	    //Draw objects
    	g.draw(window,view1);
        window.setView(view1);
        window.display();
    
        //currentTime = clock.getElapsedTime().asSeconds();
        //fps = 1.f / (currentTime - lastTime);
        //window.setTitle(std::to_string(fps));
        //lastTime = currentTime;
        //std::cout<<fps<<std::endl;

    }

    return 0;
}
