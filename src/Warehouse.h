#pragma once
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"


class Warehouse : public Building {
public:
	Warehouse(int x_position, int y_position) : Building(x_position, y_position){
        	this->updateImg();
		wood = 5;
		stone = 5;
		iron = 5;
		weapon = 0;	
	}
	void take_wood(){
		if(wood > 0){
			wood--;
		}	
	}

	void take_stone(){
		if(stone > 0){
			stone--;
		}
	}

	void take_iron(){
		if(iron > 0){
			iron--;
		}
	}
	void take_weapon(){
		if(weapon > 0){
			weapon--;
		}
	}

	void give_wood(){
		wood++;
	}

	void give_stone(){
		stone++;
	}

	void give_iron(){
		iron++;
	}

	void give_weapon(){
		weapon++;
	}

	int get_wood(){return wood;}
	int get_stone(){return stone;}
	int get_iron(){return iron;}
	int get_weapons(){return weapon;}

	void updateImg(){
		this->sprite.setTexture(ASSETHANDLER.WARETEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.WAREIMG.getSize().x/2, this->y_pos-ASSETHANDLER.WAREIMG.getSize().y );
	}

private:
	int health_points = 100;
	int size = 5;
	unsigned int wood;
	unsigned int stone;
	unsigned int iron;
	unsigned int weapon;

};
