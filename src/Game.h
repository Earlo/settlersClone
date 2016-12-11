#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tree.h"
#include "Stone.h"
#include "Iron.h"

#include "../assets.h"

#include "../constants.h"

class Game {

public:
	Game(std::vector<Building> bVector){

		buildings = bVector;
	}

	void draw(sf::RenderWindow &window, sf::View view){
		for(unsigned int i = 0; i < buildings.size(); i++){ // Draw the buildings from buildings vector
			int x = buildings[i].get_x_position();
			int y = buildings[i].get_y_position();
			if ( x > view.getCenter().x-CAMCENTERX  && x < view.getCenter().x+CAMCENTERX
				&& y > view.getCenter().y-CAMCENTERY  && y < view.getCenter().y+CAMCENTERY){
				window.draw(buildings[i].sprite);
			}
		}

	}

	std::vector<Building>& get_buildings(){return buildings;}
	
private:
	std::vector<Building> buildings;
};
