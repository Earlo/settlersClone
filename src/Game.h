#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
/*
#include "Tree.h"
#include "Stone.h"
#include "Iron.h"
#include "Settler.h"
*/
#include "Entity.h"
#include "../assets.h"

#include "../constants.h"

class Game {

public:
	Game(std::vector<Entity> bVector){

		entities = bVector;
	}

	void draw(sf::RenderWindow &window, sf::View view){
		for(unsigned int i = 0; i < entities.size(); i++){ // Draw the entities from buildings vector
			int x = entities[i].get_x_position();
			int y = entities[i].get_y_position();
			if ( x > view.getCenter().x-CAMCENTERX  && x < view.getCenter().x+CAMCENTERX
				&& y > view.getCenter().y-CAMCENTERY  && y < view.getCenter().y+CAMCENTERY){
				window.draw(entities[i].sprite);
			}
		}
	}

	std::vector<Entity>& get_entities(){return entities;}
	
private:
	std::vector<Entity> entities;

};
