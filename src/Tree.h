#pragma once
#pragma once

#include <SFML/Graphics.hpp>


#include "Entity.h"

#include "../assets.h"


class Tree : public Entity {
public:

	Tree(int x_position, int y_position)
		:Entity(x_position, y_position){

        this->updateImg();
		}

	void updateImg(){
		this->sprite.setTexture(ASSETHANDLER.TREETEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.TREEIMG.getSize().x/2, this->y_pos-ASSETHANDLER.TREEIMG.getSize().y );
	}

    //virtual ~Tree () {} // 1)

private:
	int health_points = 5;
	int size = 2;
	int required_settlers = 0;
	int required_wood = 0;
	int required_stone = 0;
	int required_iron = 0;
};
