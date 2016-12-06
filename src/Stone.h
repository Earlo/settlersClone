#pragma once
#pragma once

#include <SFML/Graphics.hpp>


#include "Building.h"



class Stone : public Building {


public:

	//sf::Sprite sprite;

	Stone(int x_position, int y_position)
		:Building(x_position, y_position){

        this->updateImg();
		}

	void updateImg(){
		this->sprite.setTexture(ASSETHANDLER.STONETEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.STONEIMG.getSize().x/2, this->y_pos-ASSETHANDLER.STONEIMG.getSize().y );
	}

    //virtual ~Stone () {} // 1)

private:

	int health_points = 5;
	int size = 2;
	int required_settlers = 0;
	int required_wood = 0;
	int required_stone = 0;
	int required_iron = 0;
};
