#include "Menu.h"

Menu::Menu(AssetHandler* ASSETHANDLER, SpatialHash* SHASH) {

	this->ASSETHANDLER = ASSETHANDLER;
	this->SHASH = SHASH;

	if(!font.loadFromFile("fonts/atwriter.ttf")){
		std::cout << "error" << std::endl;
	}
    	info_text.setFont(font);
	info_text.setCharacterSize(20);
	info_text.setColor(sf::Color::White);
	info_text.setPosition(15, 420);

	req_wood.setFont(font);
	req_wood.setCharacterSize(20);
	req_wood.setColor(sf::Color::White);
	req_wood.setPosition(30, 460);

	req_stone.setFont(font);
	req_stone.setCharacterSize(20);
	req_stone.setColor(sf::Color::White);
	req_stone.setPosition(30, 500);

	req_iron.setFont(font);
	req_iron.setCharacterSize(20);
	req_iron.setColor(sf::Color::White);
	req_iron.setPosition(30, 540);

	wood_amount.setFont(font);
	wood_amount.setCharacterSize(20);
	wood_amount.setColor(sf::Color::White);
	wood_amount.setPosition(75, 30);

	stone_amount.setFont(font);
	stone_amount.setCharacterSize(20);
	stone_amount.setColor(sf::Color::White);
	stone_amount.setPosition(75, 67);

	iron_amount.setFont(font);
	iron_amount.setCharacterSize(20);
	iron_amount.setColor(sf::Color::White);
	iron_amount.setPosition(75, 103);

	idle_amount.setFont(font);
	idle_amount.setCharacterSize(20);
	idle_amount.setColor(sf::Color::White);
	idle_amount.setPosition(75, 133);

	background.setSize(sf::Vector2f(200, 800));
	background.setTexture(&ASSETHANDLER->MENU_BACKGROUND_TEX, true);

	controlpanel.setSize(sf::Vector2f(180, 180));
	controlpanel.setTexture(&ASSETHANDLER->CONTROLPANELTEX, true);
	controlpanel.setPosition(10,10);

	button1.setSize(sf::Vector2f(85, 90));
	button1.setTexture(&ASSETHANDLER->FORTICONT, true);
	button1.setPosition(10,200);

	button2.setSize(sf::Vector2f(85, 90));
	button2.setTexture(&ASSETHANDLER->WSICONT, true);
	button2.setPosition(105,200);

	button3.setSize(sf::Vector2f(85, 90));
	button3.setTexture(&ASSETHANDLER->FHOUSEICONT, true);
	button3.setPosition(10,300);

	button4.setSize(sf::Vector2f(85, 90));
	button4.setTexture(&ASSETHANDLER->WAREICONT, true);
	button4.setPosition(105,300);

	build.setSize(sf::Vector2f(40, 40));
	build.setTexture(&ASSETHANDLER->BUILDICONT, true);
	build.setPosition(105,132);

	infobox.setSize(sf::Vector2f(180, 190));
	infobox.setTexture(&ASSETHANDLER->INFOTEX, true);
	infobox.setPosition(10,400);
}




int Menu::button1_clicked(sf::Event event, int x, int y){
	if(x > 610 && x < 695 && y > 200 && y < 290){
		if(event.type == sf::Event::MouseButtonPressed &&
                   event.mouseButton.button == sf::Mouse::Left && b1 == false) {
			return 1;
		}
		return 0;

	}
	else return 0;
}

int Menu::button2_clicked(sf::Event event, int x, int y){
	if(x > 705 && x < 790 && y > 200 && y < 290){
		if(event.type == sf::Event::MouseButtonPressed &&
                   event.mouseButton.button == sf::Mouse::Left && b1 == false) {
			return 1;
		}
		return 0;
        }
        else return 0;
}
int Menu::button3_clicked(sf::Event event, int x, int y){
	if(x > 610 && x < 695 && y > 300 && y < 390){
		if(event.type == sf::Event::MouseButtonPressed &&
                   event.mouseButton.button == sf::Mouse::Left && b1 == false) {
			return 1;
		}
		return 0;
        }
        else return 0;
}
int Menu::button4_clicked(sf::Event event, int x, int y){
	if(x > 705 && x < 790 && y > 300 && y < 390){
		if(event.type == sf::Event::MouseButtonPressed &&
                   event.mouseButton.button == sf::Mouse::Left && b1 == false) {
			return 1;
			}
		return 0;
        }
        else return 0;
}


int Menu::increase_wood(sf::Event event, int x, int y){
	if(x > 705 && x < 720 && y > 35 && y < 52){
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
			clickflag = true;
			//std::cout << "WOOD INC" << std::endl;
			return 1;

		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			clickflag = false;
			return 0;		
		}
		return 0;
	}
	return 0;
}
int Menu::decrease_wood(sf::Event event, int x, int y){
	if(x > 728 && x < 744 && y > 35 && y < 52){
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
			clickflag = true;
			//std::cout << "WOOD DEC" << std::endl;
			return 1;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			clickflag = false;
			return 0;			
		}
		return 0;
	}
	return 0;
}
int Menu::increase_stone(sf::Event event, int x, int y){
	if(x > 705 && x < 720 && y > 71 && y < 88){
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
			clickflag = true;
			//std::cout << "STONE INC" << std::endl;
			return 1;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			clickflag = false;
			return 0;			
		}		
		return 0;
	}
	return 0;
}
int Menu::decrease_stone(sf::Event event, int x, int y){
	if(x > 728 && x < 744 && y > 71 && y < 88){
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
			clickflag = true;
			//std::cout << "STONE DEC" << std::endl;
			return 1;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			clickflag = false;
			return 0;		
		}
		return 0;
	}
	return 0;
}
int Menu::increase_iron(sf::Event event, int x, int y){
	if(x > 705 && x < 720 && y > 108 && y < 124){
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
			clickflag = true;
			//std::cout << "IRON INC" << std::endl;
			return 1;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			clickflag = false;
			return 0;			
		}
		return 0;
	}
	return 0;
}
int Menu::decrease_iron(sf::Event event, int x, int y){
	if(x > 728 && x < 744 && y > 108 && y < 124){
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
			clickflag = true;
			//std::cout << "IRON DEC" << std::endl;
			return 1;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			clickflag = false;
			return 0;			
		}
		return 0;
	}
	return 0;
}
int Menu::increase_build(sf::Event event, int x, int y){
	if(x > 705 && x < 745 && y > 132 && y < 172){
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
			//std::cout << "testing building" << std::endl;
			clickflag = true;
			return 1;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			clickflag = false;
			return 0;			
		}
		return 0;
	}
	return 0;
}

void Menu::update(sf::Event event, int mouseX, int mouseY, int camX, int camY, Map* m, HumanPlayer* p, std::vector<Entity*>* v){

	//FORTRESS BUTTON
	if( this->button1_clicked(event, mouseX, mouseY) == 1 && checker % 2 == 0){ // checker prevents many build buttons being clicked

	                b1 = true;
	                checker++;
    	}

	if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b1 == true){
	                if(m->at((mouseX+camX)/DRAWSIZE, (mouseY+camY)/DRAWSIZE).type() == Tile::Type::DIRT){
				if(p->buildings.size() == 0){
					Fortress* f = new Fortress(mouseX + camX, mouseY + camY, ASSETHANDLER);
					p->buildings.insert(p->buildings.begin(),f);
					v->push_back(f);
					b1 = false;
					checker++;
				}
				
				if(!p->buildings[0]->get_construction_status()){
					Fortress* f = new Fortress(mouseX + camX, mouseY + camY, ASSETHANDLER);
					p->buildings.insert(p->buildings.begin(),f);
					v->push_back(f);
					b1 = false;
					checker++;
				}
	                }
		}
	}

    	//WEAPONSMITH BUTTON
    	if(this->button2_clicked(event, mouseX, mouseY) == 1 && checker % 2 == 0){
    		        //std::cout << "wepsmith" << std::endl;
	                    b2 = true;
	                    checker++;
    	}

	if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b2 == true){
	                if(m->at((mouseX+camX)/DRAWSIZE, (mouseY+camY)/DRAWSIZE).type() == Tile::Type::DIRT){
				if(p->buildings.size() == 0){
					Weaponsmith* ws = new Weaponsmith(mouseX + camX, mouseY + camY, ASSETHANDLER);
					p->buildings.insert(p->buildings.begin(),ws);
					v->push_back(ws);
					b2 = false;
					checker++;
				}
				else if(!p->buildings[0]->get_construction_status()){		                
					Weaponsmith* ws = new Weaponsmith(mouseX + camX, mouseY + camY, ASSETHANDLER);
					p->buildings.insert(p->buildings.begin(),ws);
					v->push_back(ws);
					b2 = false;
					checker++;
				}
	                }
		}
	}

    	//FAMILYHOUSE BUTTON
    	if(this->button3_clicked(event, mouseX, mouseY) == 1 && checker % 2 == 0){
    		        //std::cout << "fam house" << std::endl;
	                    b3 = true;
	                    checker++;
    	}

	if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){ // is mouse on button check
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b3 == true){
	                if(m->at((mouseX+camX)/DRAWSIZE, (mouseY+camY)/DRAWSIZE).type() == Tile::Type::DIRT){
				if(p->buildings.size() == 0){
					FamilyHouse* fhouse = new FamilyHouse(mouseX + camX, mouseY + camY, p, ASSETHANDLER);
					p->buildings.insert(p->buildings.begin(), fhouse);
					v->push_back(fhouse);
					b3 = false;
					checker++;
				}
				if(!p->buildings[0]->get_construction_status()){	
					FamilyHouse* fhouse = new FamilyHouse(mouseX + camX, mouseY + camY, p, ASSETHANDLER);
					p->buildings.insert(p->buildings.begin(), fhouse);
					v->push_back(fhouse);
					b3 = false;
					checker++;
				}
	        	}
		}
	}

	//WAREHOUSE BUTTON
	if( this->button4_clicked(event, mouseX, mouseY) == 1 && checker % 2 == 0){
			//std::cout << "ware" << std::endl;
	                b4 = true;
	                checker++;
	    }


	if(mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600){ // Checking if mouse is on map
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && b4 == true){
	                if(m->at((mouseX+camX)/DRAWSIZE, (mouseY+camY)/DRAWSIZE).type() == Tile::Type::DIRT){
				if(p->buildings.size() == 0){
					Warehouse* ware = new Warehouse(mouseX + camX, mouseY + camY, ASSETHANDLER);
					p->buildings.insert(p->buildings.begin(),ware);
					p->add_wh(ware);
					v->push_back(ware);
					b4 = false;
					checker++;
				}
				if(!p->buildings[0]->get_construction_status()){	
					Warehouse* ware = new Warehouse(mouseX + camX, mouseY + camY, ASSETHANDLER);
					p->buildings.insert(p->buildings.begin(),ware);
					p->add_wh(ware);
					v->push_back(ware);
					b4 = false;
					checker++;
				}
	                
	                }
		}
	}
	if(mouseX > 600 && mouseX < 800 && mouseY > 400 && mouseY < 600){
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
			if(b1 || b2 || b3 || b4){
				b1 = false;
				b2 = false;
				b3 = false;
				b4 = false;
				checker++;		
			}
		}		
	}


/*if(mouseX > 610 && mouseX < 790 && mouseY > 200 && mouseY < 390){
		if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
			if(b1 || b2 || b3 || b4){
				b1 = false;
				b2 = false;
				b3 = false;
				b4 = false;
				checker++;		
			}			
		}
	}*/

	//RESOURCE INCREASE/DECREASE BUTTON CHECKS
	if(this->increase_wood(event, mouseX, mouseY) == 1){
		p->increase_woodcutters(SHASH);
	}
	if(this->increase_stone(event, mouseX, mouseY) == 1){
		p->increase_stoners(SHASH);
	}
	if(this->increase_iron(event, mouseX, mouseY) == 1){
		p->increase_ironers(SHASH);
	}
	if(this->decrease_wood(event, mouseX, mouseY) == 1){
		p->decrease_woodcutters();
	}
	if(this->decrease_stone(event, mouseX, mouseY) == 1){
		p->decrease_stoners();
	}
	if(this->decrease_iron(event, mouseX, mouseY) == 1){
		p->decrease_ironers();
	}
	if(this->increase_build(event, mouseX, mouseY) == 1){
		p->increase_builders();
	}
}

bool Menu::startClick(sf::Event event, int mouseX, int mouseY, int camX, int camY, Map* m, HumanPlayer* p, std::vector<Entity*>* v){
	//CASTLE SPAWN
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && m->at((mouseX+camX)/DRAWSIZE, (mouseY+camY)/DRAWSIZE).type() == Tile::Type::DIRT && mouseX > 0 && mouseX < 600 && mouseY > 0 && mouseY < 600) {
        //int xpx = (pos.x + camX)/DRAWSIZE;
        //int ypx = (pos.y + camY)/DRAWSIZE;
        /*
        std::cout << xpx << ","<< ypx << " -> ";
        std::cout << (xpx)/HASHRES << ";"<< (ypx)/HASHRES << std::endl;
        std::cout<<SHASH.WEIGHT[(xpx)/HASHRES][(ypx)/HASHRES]<<std::endl;
        */
        Castle* C = new Castle(mouseX + camX, mouseY + camY, p, ASSETHANDLER);
		Warehouse* W = new Warehouse(mouseX + camX + ASSETHANDLER->CASTLEIMG.getSize().x/2 + ASSETHANDLER->WAREIMG.getSize().x/2, mouseY + camY, ASSETHANDLER);
		p->add_wh( W );


        //p->tasks.push_back( );

        v->push_back( C );
    	v->push_back( W );
	    //v = setl0.nearest(SHASH, Resource::RType::TREE);
        //initted = true;
	    return true;
    }
return false;
}
void Menu::draw_info(sf::RenderWindow &window, bool b1, bool b2, bool b3, bool b4, HumanPlayer* p){
	p->update_resources();
	int wood = p->get_wood();
	int stone = p->get_stone();
	int iron = p->get_iron();
	

	if(b1){
		info_text.setString("Fortress");
		req_wood.setString("Wood : " + std::to_string(wood) + " / " + std::to_string(FORT_W));
		req_stone.setString("Stone : " + std::to_string(stone) + " / " + std::to_string(FORT_S));
		req_iron.setString("Iron : " + std::to_string(iron) + " / " + std::to_string(FORT_I));
	}
	else if(b2){
		info_text.setString("Weaponsmith");
		req_wood.setString("Wood : " + std::to_string(wood) + " / " + std::to_string(WEP_W));
		req_stone.setString("Stone : " + std::to_string(stone) + " / " + std::to_string(WEP_S));
		req_iron.setString("Iron : " + std::to_string(iron) + " / " + std::to_string(WEP_I));
	}
	else if(b3){
		info_text.setString("Familyhouse");
		req_wood.setString("Wood : " + std::to_string(wood) + " / " + std::to_string(FAMILY_W));
		req_stone.setString("Stone : " + std::to_string(stone) + " / " + std::to_string(FAMILY_S));
		req_iron.setString("Iron : " + std::to_string(iron) + " / " + std::to_string(FAMILY_I));
	}
	else if(b4){
		info_text.setString("Warehouse");
		req_wood.setString("Wood : " + std::to_string(wood) + " / " + std::to_string(WARE_W));
		req_stone.setString("Stone : " + std::to_string(stone) + " / " + std::to_string(WARE_S));
		req_iron.setString("Iron : " + std::to_string(iron) + " / " + std::to_string(WARE_I));
	}
	window.draw(info_text);
	window.draw(req_wood);
	window.draw(req_stone);
	window.draw(req_iron);
}

void Menu::drawmenu(sf::RenderWindow &window, HumanPlayer* p){

	wood_amount.setString(std::to_string(p->get_woodcutters()));
	stone_amount.setString(std::to_string(p->get_stoners()));
	iron_amount.setString(std::to_string(p->get_ironers()));
	idle_amount.setString(std::to_string(p->get_idlers()));


	window.draw(background);
	window.draw(infobox);
	if(b1 || b2 || b3 || b4){
		draw_info(window, b1 ,b2 ,b3, b4, p);
	}
	window.draw(controlpanel);
	window.draw(button1);
	window.draw(button2);
	window.draw(button3);
	window.draw(button4);
	window.draw(wood_amount);
	window.draw(iron_amount);
	window.draw(stone_amount);
	window.draw(idle_amount);
	window.draw(build);
}
