#pragma once
#include "SFML/Graphics.hpp"
#include "../assets.h"

#include "../constants.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu();

	void draw(sf::RenderWindow &window);
		sf::RectangleShape rectangle;
    		rectangle.setSize(sf::Vector2i(200, 800));
    		rectangle.setFillColor(sf::Color::Red);
		window.draw(rectangle);

	


	void drawmenu(sf::RenderWindow &window){
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
		window.draw(menu[i]);
		}
	}

private:
	int height = 600;
	int width = 160;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
