#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"

#define max_weapons 5;

class Weaponsmith : public Building {
public:
	const static int required_stone = 8;
	const static int required_wood = 2;
	const static int required_iron = 8;

	void make_weapon();
	void take_weapon();
	Weaponsmith(int x_position, int y_position)
		:Building(x_position, y_position){

        this->updateImg();
		}

	void updateImg(){
		this->sprite.setTexture(ASSETHANDLER.WEPSMITHTEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.WEPSMITHIMG.getSize().x/2, this->y_pos-ASSETHANDLER.WEPSMITHIMG.getSize().y );
	}

private:
	int health_points = 30;
	int size = 3;
	unsigned int weapons;
	int required_settlers = 1;

};
