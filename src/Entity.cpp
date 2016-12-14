#include "Entity.h"

Entity::Entity(int x_position, int y_position){
	this->x_pos = x_position;
	this->y_pos = y_position;
	this->hp = 2;
	//std::cout<<"at ent "<<this->get_x_position()<<","<<this->get_y_position()<<std::endl;

	this->free = true;
}
