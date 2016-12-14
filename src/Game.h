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

	int& get_woodcutters(){return woodcutters;}
	int& get_stoners(){return stoners;}
	int& get_ironers(){return ironers;}
	int& get_idlers(){return idle;}

	void increase_woodcutters(){
		if(idle > 0){
			
			woodcutters += 1;
			idle -= 1;
		}
	}

	void increase_stoners(){
		if(idle > 0){
			
			stoners += 1;
			idle -= 1;
		}
	}

	void increase_ironers(){
		if(idle > 0){
			
			ironers += 1;
			idle -= 1;
		}
	}

	void decrease_woodcutters(){
		if(woodcutters > 0){
			std::cout << woodcutters << std::endl;
			woodcutters -= 1;
			idle += 1;
		}
	}
	void decrease_stoners(){
		if(stoners > 0){
		
			stoners -= 1;
			idle += 1;
		}
	}
	void decrease_ironers(){
		if(ironers > 0){
			ironers -= 1;
			idle += 1;
		}
	}

	std::vector<Entity>& get_entities(){return entities;}

	
private:
	std::vector<Entity> entities;
	int woodcutters = 0;
	int stoners = 0;
	int ironers = 0;
	int idle = 10;

};
