
#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/mapGen/Map.h"

#include "src/logic/SpatialHash.h"

#include "constants.h"
#include "src/Game.h"

//TODO DO THIS SOMEWHERE ELSE
#include "src/Entity.h"
#include "src/Settler.h"
#include "src/Fortress.h"
#include "src/Warehouse.h"
#include "src/Weaponsmith.h"
#include "src/Castle.h"
#include "src/FamilyHouse.h"
#include "src/Menu.h"
#include "src/logic/HumanPlayer.h"


//MOVE TO OTHER PLACE
bool sortByY (Entity i,Entity j) { return (i.get_y_position()<j.get_y_position()); }


int main(){

    sf::RenderWindow window(sf::VideoMode(SCREENX, SCREENY), "SFML works!");
    sf::View view1(sf::FloatRect(0, 0, VIEWX, VIEWY));
    view1.setViewport(sf::FloatRect(0, 0, .75f, 1));

    sf::View menuView(sf::FloatRect(0,0,800-VIEWX,VIEWY));
    menuView.setViewport(sf::FloatRect(.75f, 0, 0.25f, 1));
    Menu menu;
    window.setFramerateLimit(60);
    

    bool initted = false;

    int camX = 0;
    int camY = 0;

    int mouseX;
    int mouseY;

    bool game_started = false;

    //buttonchecks
    bool b1_pressed = false;
    bool b2_pressed = false;
    bool b3_pressed = false;
    bool b4_pressed = false;

    Map m = Map(WORLDX,WORLDY);
    HumanPlayer p = HumanPlayer();
    //TODO dont sort here
    std::sort (m.stuff.begin(), m.stuff.end(), sortByY);

    Game g = Game(m.stuff);
    int wood = g.get_woodcutters();
    std::vector<Entity>& entities = g.get_entities();
    
    SHASH.initHash( m );

    //just testing
    //sf::Clock clock;
    //float lastTime = clock.getElapsedTime().asSeconds();
    //float currentTime = clock.getElapsedTime().asSeconds();
    //float fps = 1.0;

    while (window.isOpen())
    {	
	std::cout << wood << std::endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
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

	//FORTRESS BUTTON
        if(menu.button1_clicked(event, mouseX, mouseY, b1_pressed) == 1 && game_started == true){
		        std::cout << "yolololo" << std::endl;
                        b1_pressed = true;
	}
        

        if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){
	        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b1_pressed == true){
                        if(m.at(mouseX/DRAWSIZE, mouseY/DRAWSIZE).type() == Tile::Type::DIRT){
		        sf::Vector2i pos(mouseX,mouseY);
                        Fortress fort(pos.x + camX, pos.y + camY);
                        entities.push_back(fort);
                        b1_pressed = false;
                        }
	        }
        }         
	
	//WEAPONSMITH BUTTON
	if(menu.button2_clicked(event, mouseX, mouseY, b2_pressed) == 1 && game_started == true){
		        std::cout << "wepsmith" << std::endl;
                        b2_pressed = true;
	}
        
        if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){
	        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b2_pressed == true){
                        if(m.at(mouseX/DRAWSIZE, mouseY/DRAWSIZE).type() == Tile::Type::DIRT){
		        sf::Vector2i pos(mouseX,mouseY);
                        Weaponsmith ws(pos.x + camX, pos.y + camY);
                        entities.push_back(ws);
                        b2_pressed = false;
                        }
	        }
        }

	//FAMILYHOUSE BUTTON
	if(menu.button3_clicked(event, mouseX, mouseY, b3_pressed) == 1 && game_started == true){
		        std::cout << "fam house" << std::endl;
                        b3_pressed = true;
	}
        
        if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){ // is mouse on button check
	        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b3_pressed == true){
                        if(m.at(mouseX/DRAWSIZE, mouseY/DRAWSIZE).type() == Tile::Type::DIRT){
		        sf::Vector2i pos(mouseX,mouseY);
                        FamilyHouse fhouse(pos.x + camX, pos.y + camY);
                        entities.push_back(fhouse);
                        b3_pressed = false;
                        }
	        }
        }

	//WAREHOUSE BUTTON
	if(menu.button4_clicked(event, mouseX, mouseY, b4_pressed) == 1 && game_started == true){
		        std::cout << "ware" << std::endl;
                        b4_pressed = true;
	}
        

        if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){ // is mouse on button check
	        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b4_pressed == true){
                        if(m.at(mouseX/DRAWSIZE, mouseY/DRAWSIZE).type() == Tile::Type::DIRT){
		        sf::Vector2i pos(mouseX,mouseY);
                        Warehouse ware(pos.x + camX, pos.y + camY);
                        entities.push_back(ware);
                        b4_pressed = false;
                        }
	        }
        }
	
	//WOOD CUTTING INCREASE
	if(menu.increase1(event, mouseX, mouseY) == 1 && game_started == true){
		g.increase_woodcutters(wood);
	}


	//CASTLE SPAWN
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && m.at(mouseX/DRAWSIZE, mouseY/DRAWSIZE).type() == Tile::Type::DIRT && game_started == false && !initted) {

            sf::Vector2i pos = sf::Mouse::getPosition(window);
            

            //int xpx = (pos.x + camX)/DRAWSIZE;
            //int ypx = (pos.y + camY)/DRAWSIZE;
            /*
            std::cout << xpx << ","<< ypx << " -> ";
            std::cout << (xpx)/HASHRES << ";"<< (ypx)/HASHRES << std::endl;
            std::cout<<SHASH.WEIGHT[(xpx)/HASHRES][(ypx)/HASHRES]<<std::endl;
            */
        	
            Castle castle(pos.x + camX, pos.y + camY);
            Settler setl0(pos.x + camX, pos.y + camY + 10);
            Settler setl1(pos.x + camX, pos.y + camY + 10);
            p.settlers.push_back(setl0);
            p.settlers.push_back(setl1);
            //p.tasks.push_back( );

            entities.push_back(castle);
            entities.push_back(setl0);
            entities.push_back(setl1);
            initted = true;
	    g.set_control();
	    game_started = true;        

        }

        view1.setCenter (camX + CAMCENTERX, camY + CAMCENTERY);

        window.clear();

        window.setView(menuView);
        menu.drawmenu(window);

        window.setView(view1);
        window.draw(m.sprite); //Draw terrain
        g.draw(window,view1); //Draw objects
        window.display();

    
        //currentTime = clock.getElapsedTime().asSeconds();
        //fps = 1.f / (currentTime - lastTime);

       
        //currentTime = clock.getElapsedTime().asSeconds();
        //fps = 1.f / (currentTime - lastTime);

        //window.setTitle(std::to_string(fps));
        //lastTime = currentTime;
        //std::cout<<fps<<std::endl;

    }

    return 0;
}
