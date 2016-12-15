#include "Building.h"

Building::Building(int x_position, int y_position, AssetHandler* ASSETHANDLER) : Entity(x_position, y_position, ASSETHANDLER){
	this->current_wood = 0;
	this->current_stone = 0;
	this->current_iron = 0;
}

void Building::complete_building(){
	this->under_construction = false;
	this->updateImg();
}
int Building::needed_resource(){
	if((required_wood - current_wood) > 0){
		return 1;		
	}
	else if((required_stone - current_stone) > 0){
		return 2;		
	}
	else if((required_iron - current_iron) > 0){
		return 3;		
	}

	else{ 
		this->complete_building();
		return 0;
	}
}
