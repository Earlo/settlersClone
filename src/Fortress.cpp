#include "Fortress.h"

Fortress::Fortress(int x_position, int y_position, AssetHandler* ASSETHANDLER) : Building(x_position, y_position, ASSETHANDLER){
	this->under_construction = true;
	this->updateImg();
	this->required_iron = 10;
	this->required_wood = 4;
	this->required_stone = 20;

	this->total_iron = 10;
	this->total_wood = 4;
	this->total_stone = 20;


	this->pop_increase = 0;
}

void Fortress::take_damage(int damage){
	health_points -= damage;
	if(health_points <= 0){
		delete(this);		
	}
}

void Fortress::repair(){
	//if(health_points < 100 && settlers_inside.size() > 0){
	if(health_points < 100){
		health_points++;
	}
}

void Fortress::updateImg(){
	if(this->under_construction){
		this->sprite.setTexture(ASSETHANDLER->BUILDTEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER->BUILD.getSize().x/2, this->y_pos-ASSETHANDLER->BUILD.getSize().y );	
	}
	else{
		this->sprite.setTexture(ASSETHANDLER->FORTRESSTEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER->FORTRESSIMG.getSize().x/2, this->y_pos-ASSETHANDLER->FORTRESSIMG.getSize().y );
	}
}
