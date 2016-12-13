#pragma once
#include "SFML/Graphics.hpp"
#include "../assets.h"

#include "../constants.h"
#include "Game.h"


class Menu
{
public:
	Menu(Game g) {
		if(!font.loadFromFile("fonts/atwriter.ttf")){
			std::cout << "error" << std::endl;
		}

		wood_amount.setFont(font);
		wood_amount.setString(std::to_string(g.get_woodcutters()));
		wood_amount.setCharacterSize(20);
		wood_amount.setColor(sf::Color::White);
		wood_amount.setPosition(75, 30);

		stone_amount.setFont(font);
		stone_amount.setString(std::to_string(g.get_stoners()));
		stone_amount.setCharacterSize(20);
		stone_amount.setColor(sf::Color::White);
		stone_amount.setPosition(75, 67);

		iron_amount.setFont(font);
		iron_amount.setString(std::to_string(g.get_ironers()));
		iron_amount.setCharacterSize(20);
		iron_amount.setColor(sf::Color::White);
		iron_amount.setPosition(75, 103);

		idle_amount.setFont(font);
		idle_amount.setString(std::to_string(g.get_idlers()));
		idle_amount.setCharacterSize(20);
		idle_amount.setColor(sf::Color::White);
		idle_amount.setPosition(75, 133);

		background.setSize(sf::Vector2f(200, 800));
		background.setTexture(&ASSETHANDLER.MENU_BACKGROUND_TEX, true);

		infobox2.setSize(sf::Vector2f(180, 180));
		infobox2.setTexture(&ASSETHANDLER.CONTROLPANELTEX, true);
		infobox2.setPosition(10,10);

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
	int increase_wood(sf::Event event, int x, int y, bool& pressed){
		if(x > 705 && x < 720 && y > 35 && y < 52){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
				pressed = true;
				std::cout << "WOOD INC" << std::endl;
				return 1;
			
			}		
		}
	}
	int decrease_wood(sf::Event event, int x, int y){
		if(x > 728 && x < 744 && y > 35 && y < 52){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
				std::cout << "WOOD DEC" << std::endl;
				return 1;
			
			}		
		}
	}
	int increase_stone(sf::Event event, int x, int y){
		if(x > 705 && x < 720 && y > 71 && y < 88){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
				std::cout << "STONE INC" << std::endl;
				return 1;
			
			}		
		}
	}
	int decrease_stone(sf::Event event, int x, int y){
		if(x > 728 && x < 744 && y > 71 && y < 88){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
				std::cout << "STONE DEC" << std::endl;
				return 1;
			
			}		
		}
	}
	int increase_iron(sf::Event event, int x, int y){
		if(x > 705 && x < 720 && y > 108 && y < 124){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
				std::cout << "IRON INC" << std::endl;
				return 1;
			
			}		
		}
	}
	int decrease_iron(sf::Event event, int x, int y){
		if(x > 728 && x < 744 && y > 108 && y < 124){
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
				std::cout << "IRON DEC" << std::endl;
				return 1;
			
			}		
		}
	}	

	void drawmenu(sf::RenderWindow &window, Game g){
		wood_amount.setString(std::to_string(g.get_woodcutters()));
		stone_amount.setString(std::to_string(g.get_stoners()));
		iron_amount.setString(std::to_string(g.get_ironers()));
		idle_amount.setString(std::to_string(g.get_idlers()));
		

		window.draw(background);
		window.draw(infobox);
		window.draw(infobox2);
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
	sf::RectangleShape background;
	sf::RectangleShape infobox;
	sf::RectangleShape infobox2;
	sf::RectangleShape button1;
	sf::RectangleShape button2;
	sf::RectangleShape button3;
	sf::RectangleShape button4;
};
