#pragma once
#pragma once

#include <SFML/Graphics.hpp>


#include "Building.h"



class Iron : public Building {


public:

	//sf::Sprite sprite;

	Iron(int x_position, int y_position)
		:Building(x_position, y_position){

        this->updateImg();
		}

    //virtual ~Iron () {} // 1)

private:
	int health_points = 5;
	int size = 2;
	int required_settlers = 0;
	int required_wood = 0;
	int required_stone = 0;
	int required_iron = 0;
};
