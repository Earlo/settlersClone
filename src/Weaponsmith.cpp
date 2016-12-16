#include "Weaponsmith.h"

Weaponsmith::Weaponsmith(int x_position, int y_position,AssetHandler* ASSETHANDLER) : Building(x_position, y_position, ASSETHANDLER){
		this->required_iron = 1;
		this->required_wood = 1;
		this->required_stone = 1;
		this->pop_increase = 0;
		this->under_construction = true;
        	this->updateImg();
		}

void Weaponsmith::updateImg(){
	if(this->under_construction){
		this->sprite.setTexture(ASSETHANDLER->BUILDTEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER->BUILD.getSize().x/2, this->y_pos-ASSETHANDLER->BUILD.getSize().y );	
	}
	else{
		this->sprite.setTexture(ASSETHANDLER->WEPSMITHTEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER->WEPSMITHIMG.getSize().x/2, this->y_pos-ASSETHANDLER->WEPSMITHIMG.getSize().y );
	}
}
