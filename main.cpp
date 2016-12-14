
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

    window.setFramerateLimit(60);


    bool initted = false;

    int camX = 0;
    int camY = 0;
    int checker = 0;
    int mouseX;
    int mouseY;

    bool game_started = false;

    //buttonchecks
    bool b1_pressed = false;
    bool b2_pressed = false;
    bool b3_pressed = false;
    bool b4_pressed = false;
    bool button_pressed = false;
    //warehouse vector


    Map m = Map(WORLDX,WORLDY);

    //TODO dont sort here
    std::sort (m.stuff.begin(), m.stuff.end(), sortByY);

    Game g = Game(m.stuff);
    Menu menu(g);
    std::vector<Entity>& entities = g.get_entities();

    SHASH.initHash( m );

    HumanPlayer p;

    //just testing
    //sf::Clock clock;
    //float lastTime = clock.getElapsedTime().asSeconds();
    //float currentTime = clock.getElapsedTime().asSeconds();
    //float fps = 1.0;

    while (window.isOpen())
    {
	//std::cout << wood << std::endl;
	//wood++;
	//std::cout << mouseX << std::endl;
	//std::cout << mouseY << std::endl;
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
        if(game_started == true && menu.button1_clicked(event, mouseX, mouseY, b1_pressed) == 1 && checker % 2 == 0){ // checker prevents many buttons being clicked to build multiple buildings
		        std::cout << "yolololo" << std::endl;
                        b1_pressed = true;
                        checker++;

	}


        if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){
	        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b1_pressed == true){
                        if(m.at(mouseX/DRAWSIZE, mouseY/DRAWSIZE).type() == Tile::Type::DIRT){
		        sf::Vector2i pos(mouseX,mouseY);
                        Fortress fort(pos.x + camX, pos.y + camY);
                        entities.push_back(fort);
                        b1_pressed = false;
                        checker++;
                        }
	        }
        }

	//WEAPONSMITH BUTTON
	if(game_started == true && menu.button2_clicked(event, mouseX, mouseY, b2_pressed) == 1 && checker % 2 == 0){
		        std::cout << "wepsmith" << std::endl;
                        b2_pressed = true;
                        checker++;
	}

        if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){
	        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b2_pressed == true){
                        if(m.at(mouseX/DRAWSIZE, mouseY/DRAWSIZE).type() == Tile::Type::DIRT){
		        sf::Vector2i pos(mouseX,mouseY);
                        Weaponsmith ws(pos.x + camX, pos.y + camY);
                        entities.push_back(ws);
                        b2_pressed = false;
                        checker++;
                        }
	        }
        }

	//FAMILYHOUSE BUTTON
	if(game_started == true && menu.button3_clicked(event, mouseX, mouseY, b3_pressed) == 1 && checker % 2 == 0){
		        std::cout << "fam house" << std::endl;
                        b3_pressed = true;
                        checker++;
	}

        if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){ // is mouse on button check
	        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b3_pressed == true){
                        if(m.at(mouseX/DRAWSIZE, mouseY/DRAWSIZE).type() == Tile::Type::DIRT){
		        sf::Vector2i pos(mouseX,mouseY);
                        FamilyHouse fhouse(pos.x + camX, pos.y + camY);
                        entities.push_back(fhouse);
                        b3_pressed = false;
                        checker++;
                        }
	        }
        }

	//WAREHOUSE BUTTON
	if(game_started == true && menu.button4_clicked(event, mouseX, mouseY, b4_pressed) == 1 && checker % 2 == 0){
		        std::cout << "ware" << std::endl;
                        b4_pressed = true;
                        checker++;
	}


        if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){ // Checking if mouse is on map
	        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b4_pressed == true){
                        if(m.at(mouseX/DRAWSIZE, mouseY/DRAWSIZE).type() == Tile::Type::DIRT){
		        sf::Vector2i pos(mouseX,mouseY);
                        Warehouse ware(pos.x + camX, pos.y + camY);
			p.add_wh(ware);
                        entities.push_back(ware);
                        b4_pressed = false;
                        checker++;
                        }
	        }
        }

	/*if(mouseX > 610 && mouseX < 790 && mouseY > 200 && mouseY < 390){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
				if(b1_pressed || b2_pressed || b3_pressed || b4_pressed){
					b1_pressed = false;
					b2_pressed = false;
					b3_pressed = false;
					b4_pressed = false;
					checker++;		
				}			
			}
		}*/

	//RESOURCE INCREASE/DECREASE BUTTON CHECKS
	if(menu.increase_wood(event, mouseX, mouseY) == 1 && game_started == true){
		g.increase_woodcutters();
	}
	if(menu.increase_stone(event, mouseX, mouseY) == 1 && game_started == true){
		g.increase_stoners();
	}
	if(menu.increase_iron(event, mouseX, mouseY) == 1 && game_started == true){
		g.increase_ironers();
	}
	if(menu.decrease_wood(event, mouseX, mouseY) == 1 && game_started == true){
		g.decrease_woodcutters();
	}
	if(menu.decrease_stone(event, mouseX, mouseY) == 1 && game_started == true){
		g.decrease_stoners();
	}
	if(menu.decrease_iron(event, mouseX, mouseY) == 1 && game_started == true){
		g.decrease_ironers();
	}
	button_pressed = false;

	//CASTLE SPAWN
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && m.at(mouseX/DRAWSIZE, mouseY/DRAWSIZE).type() == Tile::Type::DIRT && m.at((mouseX + ASSETHANDLER.CASTLEIMG.getSize().x/2)/DRAWSIZE, (mouseY+ASSETHANDLER.WAREIMG.getSize().x/2)/DRAWSIZE).type() == Tile::Type::DIRT && game_started == false && !initted && mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600) {

		sf::Vector2i pos = sf::Mouse::getPosition(window);

		//int xpx = (pos.x + camX)/DRAWSIZE;
		//int ypx = (pos.y + camY)/DRAWSIZE;
		/*
		std::cout << xpx << ","<< ypx << " -> ";
		std::cout << (xpx)/HASHRES << ";"<< (ypx)/HASHRES << std::endl;
		std::cout<<SHASH.WEIGHT[(xpx)/HASHRES][(ypx)/HASHRES]<<std::endl;
		*/
		Castle castle(pos.x + camX, pos.y + camY);
		Warehouse whouse(pos.x + camX + ASSETHANDLER.CASTLEIMG.getSize().x/2 + ASSETHANDLER.WAREIMG.getSize().x/2, pos.y + camY);
		p.add_wh(whouse);
		Settler setl0(pos.x + camX, pos.y + camY + 10);
		Settler setl1(pos.x + camX, pos.y + camY + 10);
		p.settlers.push_back(setl0);
		p.settlers.push_back(setl1);
		//p.tasks.push_back( );
		entities.push_back(castle);
		entities.push_back(whouse);
		entities.push_back(setl0);
		entities.push_back(setl1);
		initted = true;
		game_started = true;

        }

        view1.setCenter (camX + CAMCENTERX, camY + CAMCENTERY);
        window.clear();

        window.setView(menuView);
        menu.drawmenu(window, g, b1_pressed, b2_pressed, b3_pressed, b4_pressed, p);

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

