#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"


class Castle : public Building {
public:

	Castle(int x_position, int y_position)
		:Building(x_position, y_position){
        this->updateImg();
		}

	void updateImg(){
		this->sprite.setTexture(ASSETHANDLER.CASTLETEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.CASTLEIMG.getSize().x/2, this->y_pos-ASSETHANDLER.CASTLEIMG.getSize().y );
	}

private:
	int health_points = 100;
	int size = 5;
};
