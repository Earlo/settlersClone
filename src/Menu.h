#pragma once
#include "SFML/Graphics.hpp"
#include "../assets.h"

#include "../constants.h"

class Menu
{
public:
	Menu() {};

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


	void drawmenu(sf::RenderWindow &window){
    		background.setSize(sf::Vector2f(200, 800));
		background.setTexture(&ASSETHANDLER.MENU_BACKGROUND_TEX, true);

		infobox2.setSize(sf::Vector2f(180, 180));
		infobox2.setFillColor(sf::Color::Blue);
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
		infobox.setFillColor(sf::Color::Blue);
		infobox.setPosition(10,400);

		window.draw(background);
		window.draw(infobox);
		window.draw(infobox2);
		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.draw(button4);
	}


private:
	sf::RectangleShape background;
	sf::RectangleShape infobox;
	sf::RectangleShape infobox2;
	sf::RectangleShape button1;
	sf::RectangleShape button2;
	sf::RectangleShape button3;
	sf::RectangleShape button4;
};
