#pragma once
#include "SFML/Graphics.hpp"
#include "../assets.h"

#include "../constants.h"

class Menu
{
public:
	Menu() {};

	void drawmenu(sf::RenderWindow &window){
    		background.setSize(sf::Vector2f(200, 800));
		background.setTexture(&ASSETHANDLER.MENU_BACKGROUND_TEX, true);

		infobox.setSize(sf::Vector2f(180, 200));
		infobox.setFillColor(sf::Color::Blue);
		infobox.setPosition(10,390);

		button1.setSize(sf::Vector2f(180, 80));
		button1.setFillColor(sf::Color::Green);
		button1.setPosition(10,300);

		button2.setSize(sf::Vector2f(180, 80));
		button2.setFillColor(sf::Color::Green);
		button2.setPosition(10,210);

		infobox2.setSize(sf::Vector2f(180, 190));
		infobox2.setFillColor(sf::Color::Blue);
		infobox2.setPosition(10,10);

		window.draw(background);
		window.draw(infobox);
		window.draw(infobox2);
		window.draw(button1);
		window.draw(button2);
	}


private:
	sf::RectangleShape background;
	sf::RectangleShape infobox;
	sf::RectangleShape infobox2;
	sf::RectangleShape button1;
	sf::RectangleShape button2;
};
