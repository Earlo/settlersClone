#include "Entity.h"

Entity::Entity(int x_position, int y_position, AssetHandler* ASSETHANDLER){
	this->x_pos = x_position;
	this->y_pos = y_position;
	this->hp = 2;
	this->ASSETHANDLER = ASSETHANDLER;
	this->free = true;
}
