#pragma once

#include <SFML/Graphics.hpp>

#include "../Settler.h"

#include "../../constants.h"

class Player {
public:
	std::vector<Settler> settlers;
	//std::vector<Task> tasks;

	void update(sf::RenderWindow &window, sf::View view){
		for (unsigned int i = 0; i < settlers.size(); i++){
			int x = settlers[i].get_x_position();
			int y = settlers[i].get_y_position();
			if ( x > view.getCenter().x-CAMCENTERX  && x < view.getCenter().x+CAMCENTERX
				&& y > view.getCenter().y-CAMCENTERY  && y < view.getCenter().y+CAMCENTERY){
				window.draw(settlers[i].sprite);
			}
		}
	}
private:
	
};
