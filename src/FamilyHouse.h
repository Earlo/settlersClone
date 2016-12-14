#pragma once
#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"

class FamilyHouse : public Building {
public:
	
	FamilyHouse(int x_position, int y_position) : Building(x_position, y_position){
		for(unsigned int i = 0; i < 2; i++){
			Settler settler(x_position, y_position);
			settlers_inside.push_back(settler);
		}
        	this->updateImg();
	}

	void updateImg(){
		this->sprite.setTexture(ASSETHANDLER.FHOUSETEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.FHOUSEIMG.getSize().x/2, this->y_pos-ASSETHANDLER.FHOUSEIMG.getSize().y );
	}

private:
	int health_points = 20;
	int size = 2;

};
