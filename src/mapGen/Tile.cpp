
//#include <iostream>

#include "Tile.h"
#include "../../constants.h"
void Tile::refreshShape(){
	//std::cout<<"asd";
	this->shape.setPointCount(4);

	this->shape.setPoint(0, sf::Vector2f(DRAWSIZE*(x  ) ,DRAWSIZE*(y  )));
	this->shape.setPoint(1, sf::Vector2f(DRAWSIZE*(x-1), DRAWSIZE*(y  )));
	this->shape.setPoint(2, sf::Vector2f(DRAWSIZE*(x-1), DRAWSIZE*(y-1)));
	this->shape.setPoint(3, sf::Vector2f(DRAWSIZE*(x  ), DRAWSIZE*(y-1)));	
	/*
	shape.setPoint(0, sf::Vector2f(DRAWSIZE*(x  ) ,DRAWSIZE*(y  )));
	shape.setPoint(1, sf::Vector2f(DRAWSIZE*(x-1)+1, DRAWSIZE*(y  )));
	shape.setPoint(2, sf::Vector2f(DRAWSIZE*(x-1)+1, DRAWSIZE*(y-1)+1));
	shape.setPoint(3, sf::Vector2f(DRAWSIZE*(x  ), DRAWSIZE*(y-1)+1));
	*/
	switch(this->type()){
		case Tile::Type::DIRT:
			this->shape.setFillColor (sf::Color(91-z*30/100,231-z*127/100,77-z*20/100));
			break;
		case Tile::Type::WATER:
			this->shape.setFillColor (sf::Color(67+z/4,67+z/4,255+z));
			break;
		case Tile::Type::SAND:
			this->shape.setFillColor(sf::Color(255-z,255-z,51));
			break;
		case Tile::Type::ROCK:
			this->shape.setFillColor (sf::Color(127-z/2,127-z/2,127-z/2));
			break;
		case Tile::Type::WOODS:
			this->shape.setFillColor (sf::Color(0,127-z/2,0));
			break;
		case Tile::Type::ORE:
			this->shape.setFillColor (sf::Color(255-z,67-z/4,0));
			break;

		default : //shouldn't go here
			this->shape.setFillColor (sf::Color::Red);
			break;
	}
}

