#pragma once
#pragma once

#include <SFML/Graphics.hpp>


#include "Building.h"



class Iron : public Building {


public:

	//sf::Sprite sprite;

	Iron(int x_position, int y_position)
		:Building(x_position, y_position){

        this->updateImg();
		}

	void updateImg(){

        this->IMG.loadFromFile("sprites/Iron.png");
        this->TEXTURE.loadFromImage(this->IMG);
		this->sprite.setTexture(this->TEXTURE, true);
		this->sprite.setScale( 1, 1);

		this->sprite.setPosition( this->x_pos-8, this->y_pos-22 );
	}

    //virtual ~Iron () {} // 1)

private:
	
	sf::Image IMG;
	sf::Texture TEXTURE;
	int health_points = 5;
	int size = 2;
	int required_settlers = 0;
	int required_wood = 0;
	int required_stone = 0;
	int required_iron = 0;
};
