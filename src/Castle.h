#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"
#include "Settler.h"
#include "logic/HumanPlayer.h"


class Castle : public Building {
public:

	Castle(int x_position, int y_position, HumanPlayer& p) : Building(x_position, y_position){
		for(unsigned int i = 0; i < 10; i++){
			Settler settler(x_position, y_position);
			p.add_to_idle(settler);
			std::cout << "hmm" << std::endl;
		}
        	this->updateImg();
	}
	/*bool is_on_land(int x_pos, int y_pos, Map m){
		unsigned int checker = 0;
		for(unsigned int i = y_pos; i < (y_pos + ASSETHANDLER.CASTLEIMG.getSize().y); i++){
			for(unsigned int j = x_pos; j < (x_pos + ASSETHANDLER.CASTLEIMG.getSize().x); j++){
				if(m.at(i/DRAWSIZE, j/DRAWSIZE).type() == Tile::Type::DIRT){
					checker++;
				}
			}
		}
		if(checker == (x_pos*y_pos){ return true; }
		else return false;
	}*/

	void updateImg(){
		this->sprite.setTexture(ASSETHANDLER.CASTLETEX, true);
		
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.CASTLEIMG.getSize().x/2, this->y_pos-ASSETHANDLER.CASTLEIMG.getSize().y );
	}

private:
	int health_points = 100;
	int size = 5;
};
