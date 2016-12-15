
#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/mapGen/Map.h"

#include "src/logic/SpatialHash.h"

#include "constants.h"
#include "src/Game.h"

//TODO DO THIS SOMEWHERE ELSE
#include "src/Settler.h"

/*
#include "src/Fortress.h"
#include "src/Warehouse.h"
#include "src/Weaponsmith.h"
#include "src/Castle.h"
#include "src/FamilyHouse.h"
*/
#include "src/Menu.h"

#include "src/logic/HumanPlayer.h"


//MOVE TO OTHER PLACE
bool sortByY (Entity* i,Entity* j) { return (i->get_y_position()<j->get_y_position()); }


int main(){

    sf::RenderWindow window(sf::VideoMode(SCREENX, SCREENY), "The Settlers");

    sf::View view1(sf::FloatRect(0, 0, VIEWX, VIEWY));
    view1.setViewport(sf::FloatRect(0, 0, VIEWPORTW, 1));

    sf::View menuView(sf::FloatRect(0,0,800-VIEWX,VIEWY));
    menuView.setViewport(sf::FloatRect(VIEWPORTW, 0, MENUPOWRTW, 1));

    window.setFramerateLimit(60);

    int camX = 0;
    int camY = 0;
    int mouseX;
    int mouseY;

    bool game_started = false;

    //buttonchecks
    /*bool b1_pressed = false;
    bool b2_pressed = false;
    bool b3_pressed = false;
    bool b4_pressed = false;
    */

    Game g;
    std::cout<<g.entities.size()<<" entities"<<std::endl;
    Map m = Map(WORLDX,WORLDY, &g);
    std::cout<<g.entities.size()<<" entities"<<std::endl;
    std::cout<<"at MAI "<<g.entities[1]->get_x_position()<<","<<g.entities[1]->get_y_position()<<std::endl;
    std::cout<<"at MAI "<<g.entities[2]->get_x_position()<<","<<g.entities[2]->get_y_position()<<std::endl;

    /*
    for(unsigned int i = 0; i < g.entities.size(); i++){ // Draw the entities from buildings vector
        std::cout<<"at ASD "<<g.entities[i]->get_x_position()<<","<<g.entities[i]->get_y_position()<<std::endl;
        //std::cout<<"at man "<<x<<","<<y<<std::endl;
        }
    */
    //TODO dont sort here
    //std::sort (m.stuff.begin(), m.stuff.end(), sortByY);
    HumanPlayer p;
    Menu menu;

    SHASH.initHash( &m );

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        if (event.type == sf::Event::MouseMoved) {
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
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


        if(!game_started){
            game_started = menu.startClick(event, mouseX, mouseY, camX, camY, &m, &p, g.get_entities());
        }
        else{
            menu.update( event, mouseX, mouseY, camX, camY, &m, &p, g.get_entities());
            p.play(&SHASH);
        }
        view1.setCenter (camX + CAMCENTERX, camY + CAMCENTERY);

        window.clear();

        window.setView(menuView);
        menu.drawmenu(window, &p);

        window.setView(view1);
        window.draw(m.sprite);  //Draw terrain
        g.draw(window,view1);   //Draw objects
        p.update(window,view1); //draw plauer
        window.display();


        //currentTime = clock.getElapsedTime().asSeconds();
        //fps = 1.f / (currentTime - lastTime);


        //currentTime = clock.getElapsedTime().asSeconds();
        //fps = 1.f / (currentTime - lastTime);

        //window.setTitle(std::to_string(fps));
        //lastTime = currentTime;
        //std::cout<<fps<<std::endl;
	   //std::cout << p.get_idlers() << std::endl;
    }
    return 0;
}
