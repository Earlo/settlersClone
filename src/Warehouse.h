#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"


class Warehouse : public Building {
public:
	
	Warehouse(int x_position, int y_position)
		:Building(x_position, y_position){
        this->updateImg();
		}

	void updateImg(){
		this->sprite.setTexture(ASSETHANDLER.WARETEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.WAREIMG.getSize().x/2, this->y_pos-ASSETHANDLER.WAREIMG.getSize().y );
	}

private:
	int health_points = 100;
	int size = 5;
	int required_settlers = 5;
	int required_stone = 10;
	int required_wood = 5;
	int required_iron = 2;

};
