#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"


class Fortress : public Building {
public:

	Fortress(int x_position, int y_position) : Building(x_position, y_position){
        	this->updateImg();
	}
	/*~Fortress(){}
	
	take_damage(){
		health_points -= 10;
		if(health_points < 0){
					
		}
	}*/
	void repair(){
		
	}

	void updateImg(){
		this->sprite.setTexture(ASSETHANDLER.FORTRESSTEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.FORTRESSIMG.getSize().x/2, this->y_pos-ASSETHANDLER.FORTRESSIMG.getSize().y );
	}

private:
	int health_points = 100;
	int size = 5;
	int required_settlers = 5;
};
