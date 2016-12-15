#include "FamilyHouse.h"

FamilyHouse::FamilyHouse(int x_position, int y_position, HumanPlayer* p, AssetHandler* ASSETHANDLER) : Building(x_position, y_position, ASSETHANDLER){
	this->required_iron = 2;
	this->required_wood = 12;
	this->required_stone = 5;
	this->pop_increase = 4;
	this->under_construction = true;
	this->pl = p;
this->updateImg();
}

void FamilyHouse::updateImg(){
		
	if(this->under_construction){
		this->sprite.setTexture(ASSETHANDLER->BUILDTEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER->BUILD.getSize().x/2, this->y_pos-ASSETHANDLER->BUILD.getSize().y );	
	}
	else{
		this->sprite.setTexture(ASSETHANDLER->FHOUSETEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER->FHOUSEIMG.getSize().x/2, this->y_pos-ASSETHANDLER->FHOUSEIMG.getSize().y );
		for(unsigned int i = 0; i < 4; i++){
			Settler* s = new Settler(this->get_x_position(), this->get_y_position(), ASSETHANDLER );
			pl->settlers.push_back(s);
			pl->increase_idlers();
		}

	}
}
