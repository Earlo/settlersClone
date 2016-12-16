#include "Warehouse.h"

Warehouse::Warehouse(int x_position, int y_position, AssetHandler* ASSETHANDLER) : Building(x_position, y_position, ASSETHANDLER){
    	this->updateImg();
		this->wood = 12;
		this->stone = 5;
		this->iron = 2;
		this->weapon = 0;
		this->required_iron = 0;
		this->required_wood = 15;
		this->required_stone = 6;
		this->pop_increase = 0;
	}
void Warehouse::take_wood(){
	if(wood > 0){
		wood--;
	}	
}

void Warehouse::take_stone(){
	if(stone > 0){
		stone--;
	}
}

void Warehouse::take_iron(){
	if(iron > 0){
		iron--;
	}
}
void Warehouse::take_weapon(){
	if(weapon > 0){
		weapon--;
	}
}

void Warehouse::give_wood(){
	wood++;
}

void Warehouse::give_stone(){
	stone++;
}

void Warehouse::updateImg(){
	this->sprite.setTexture(ASSETHANDLER->WARETEX, true);
	this->sprite.setPosition( this->x_pos-ASSETHANDLER->WAREIMG.getSize().x/2, this->y_pos-ASSETHANDLER->WAREIMG.getSize().y );
}

void Warehouse::give_iron(){
	iron++;
}

void Warehouse::give_weapon(){
	weapon++;
}
