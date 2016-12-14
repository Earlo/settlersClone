#pragma once
#include "SFML/Graphics.hpp"
#include "../assets.h"

#include "../constants.h"
#include "Game.h"
#include "logic/HumanPlayer.h"


class Menu
{
public:
	bool clickflag = false;

	Menu(HumanPlayer& p) {
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
		background.setTexture(&ASSETHANDLER.MENU_BACKGROUND_TEX, true);

		controlpanel.setSize(sf::Vector2f(180, 180));
		controlpanel.setTexture(&ASSETHANDLER.CONTROLPANELTEX, true);
		controlpanel.setPosition(10,10);

		button1.setSize(sf::Vector2f(85, 90));
		button1.setTexture(&ASSETHANDLER.FORTICONT, true);
		button1.setPosition(10,200);

		button2.setSize(sf::Vector2f(85, 90));
		button2.setTexture(&ASSETHANDLER.WSICONT, true);
		button2.setPosition(105,200);

		button3.setSize(sf::Vector2f(85, 90));
		button3.setTexture(&ASSETHANDLER.FHOUSEICONT, true);
		button3.setPosition(10,300);

		button4.setSize(sf::Vector2f(85, 90));
		button4.setTexture(&ASSETHANDLER.WAREICONT, true);
		button4.setPosition(105,300);

		infobox.setSize(sf::Vector2f(180, 190));
		infobox.setTexture(&ASSETHANDLER.INFOTEX, true);
		infobox.setPosition(10,400);
	};




	int button1_clicked(sf::Event event, int x, int y, bool& b1_pressed){
		if(x > 610 && x < 695 && y > 200 && y < 290){
			if(event.type == sf::Event::MouseButtonPressed &&
                           event.mouseButton.button == sf::Mouse::Left && b1_pressed == false) {return 1;}

		}
		else return 0;
	}

	int button2_clicked(sf::Event event, int x, int y, bool& b1_pressed){
		if(x > 705 && x < 790 && y > 200 && y < 290){
			if(event.type == sf::Event::MouseButtonPressed &&
                           event.mouseButton.button == sf::Mouse::Left && b1_pressed == false) {return 1;}
	        }
                else return 0;
        }
        int button3_clicked(sf::Event event, int x, int y, bool& b1_pressed){
		if(x > 610 && x < 695 && y > 300 && y < 390){
			if(event.type == sf::Event::MouseButtonPressed &&
                           event.mouseButton.button == sf::Mouse::Left && b1_pressed == false) {return 1;}
	        }
                else return 0;
        }
        int button4_clicked(sf::Event event, int x, int y, bool& b1_pressed){
		if(x > 705 && x < 790 && y > 300 && y < 390){
			if(event.type == sf::Event::MouseButtonPressed &&
                           event.mouseButton.button == sf::Mouse::Left && b1_pressed == false) {return 1;}
                }
                else return 0;
	}


	int increase_wood(sf::Event event, int x, int y){
		if(x > 705 && x < 720 && y > 35 && y < 52){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
				clickflag = true;
				std::cout << "WOOD INC" << std::endl;
				return 1;

			}
			else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				clickflag = false;		
			}
		}
	}
	int decrease_wood(sf::Event event, int x, int y){
		if(x > 728 && x < 744 && y > 35 && y < 52){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
				clickflag = true;
				std::cout << "WOOD DEC" << std::endl;
				return 1;
			}
			else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				clickflag = false;			
			}
		}
	}
	int increase_stone(sf::Event event, int x, int y){
		if(x > 705 && x < 720 && y > 71 && y < 88){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
				clickflag = true;
				std::cout << "STONE INC" << std::endl;
				return 1;
			}
			else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				clickflag = false;			
			}		
		}
	}
	int decrease_stone(sf::Event event, int x, int y){
		if(x > 728 && x < 744 && y > 71 && y < 88){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
				clickflag = true;
				std::cout << "STONE DEC" << std::endl;
				return 1;
			}
			else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				clickflag = false;			
			}
		}
	}
	int increase_iron(sf::Event event, int x, int y){
		if(x > 705 && x < 720 && y > 108 && y < 124){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
				clickflag = true;
				std::cout << "IRON INC" << std::endl;
				return 1;
			}
			else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				clickflag = false;			
			}
		}
	}
	int decrease_iron(sf::Event event, int x, int y){
		if(x > 728 && x < 744 && y > 108 && y < 124){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !clickflag){
				clickflag = true;
				std::cout << "IRON DEC" << std::endl;
				return 1;
			}
			else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				clickflag = false;			
			}
		}
	}

	void draw_info(sf::RenderWindow &window, bool b1, bool b2, bool b3, bool b4, HumanPlayer p){
		p.update_resources();
		int wood = p.get_wood();
		int stone = p.get_stone();
		int iron = p.get_iron();
		

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







	void drawmenu(sf::RenderWindow &window, bool b1, bool b2, bool b3, bool b4, HumanPlayer p){


		wood_amount.setString(std::to_string(p.get_woodcutters()));
		stone_amount.setString(std::to_string(p.get_stoners()));
		iron_amount.setString(std::to_string(p.get_ironers()));
		idle_amount.setString(std::to_string(p.get_idlers()));


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
	}

private:
	sf::Font font;
	sf::Text wood_amount;
	sf::Text iron_amount;
	sf::Text stone_amount;
	sf::Text idle_amount;
	sf::Text info_text;
	sf::Text req_wood;
	sf::Text req_stone;
	sf::Text req_iron;
	sf::RectangleShape background;
	sf::RectangleShape infobox;
	sf::RectangleShape controlpanel;
	sf::RectangleShape button1;
	sf::RectangleShape button2;
	sf::RectangleShape button3;
	sf::RectangleShape button4;
};

