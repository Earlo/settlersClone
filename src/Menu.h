#pragma once
#include "SFML/Graphics.hpp"
#include "../assets.h"

#include "../constants.h"

class Menu
{
public:
	Menu() {};

	void drawmenu(sf::RenderWindow &window){
    		rectangle.setSize(sf::Vector2f(200, 800));
    		rectangle.setFillColor(sf::Color::Red);
		window.draw(rectangle);
	}


private:
	sf::RectangleShape rectangle;
};
