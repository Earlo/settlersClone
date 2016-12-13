#pragma once
#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"

class FamilyHouse : public Building {
public:
	void make_new_settlers();
	FamilyHouse(int x_position, int y_position)
		:Building(x_position, y_position){

        this->updateImg();
		}

	void updateImg(){
		this->sprite.setTexture(ASSETHANDLER.FHOUSETEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.FHOUSEIMG.getSize().x/2, this->y_pos-ASSETHANDLER.FHOUSEIMG.getSize().y );
	}

private:
	int health_points = 20;
	int size = 2;
	int required_settlers = 2;
	int required_wood = 10;
	int required_stone = 2;
	int required_iron = 0;
};
