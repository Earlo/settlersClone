#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"


class Fortress : public Building {
public:

	Fortress(int x_position, int y_position) : Building(x_position, y_position){
        	this->updateImg();
	}
	~Fortress(){}
	
	void take_damage(int damage){
		health_points -= damage;
		if(health_points <= 0){
			delete(this);		
		}
	}
	void repair(){
		if(health_points < 100 && settlers_inside.size() > 0){
			health_points++;
		}
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
