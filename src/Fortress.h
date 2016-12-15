#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"


class Fortress : public Building {
public:

	Fortress(int x_position, int y_position) : Building(x_position, y_position){
        	this->updateImg();
		this->required_iron = 10;
		this->required_wood = 4;
		this->required_stone = 20;
		this->pop_increase = 0;
		this->under_construction = true;
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
	int health_points = 100;
	int size = 5;
	int required_settlers = 5;
};
