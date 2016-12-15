#pragma once
#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"

class FamilyHouse : public Building {
public:
	
	FamilyHouse(int x_position, int y_position ) : Building(x_position, y_position){
		this->required_iron = 2;
		this->required_wood = 12;
		this->required_stone = 5;
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
	int health_points = 20;
	int size = 2;

};
