#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"

#define max_weapons 5;

class Weaponsmith : public Building {
public:

	void make_weapon();
	void take_weapon();
	Weaponsmith(int x_position, int y_position) : Building(x_position, y_position){
		this->required_iron = 15;
		this->required_wood = 2;
		this->required_stone = 10;
		this->under_construction = true;
        	this->updateImg();
		}

	void updateImg(){
		if(this->under_construction){
			this->sprite.setTexture(ASSETHANDLER.BUILDTEX, true);
			this->sprite.setPosition( this->x_pos-ASSETHANDLER.BUILD.getSize().x/2, this->y_pos-ASSETHANDLER.BUILD.getSize().y );	
		}
		else{
			this->sprite.setTexture(ASSETHANDLER.FHOUSETEX, true);
			this->sprite.setPosition( this->x_pos-ASSETHANDLER.FHOUSEIMG.getSize().x/2, this->y_pos-ASSETHANDLER.FHOUSEIMG.getSize().y );
		}
	}

private:

	unsigned int weapons;
	int required_settlers = 1;

};
