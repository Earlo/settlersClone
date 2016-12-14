#ifndef ENTITY
#define ENTITY

//include "Resource.h"
//#include "Settler.h"
#include <vector>

#include <SFML/Graphics.hpp>


class Entity {
public:
	sf::Sprite sprite;
	
	//Building(int x_position, int y_position) : x_pos(x_position), y_pos(y_position) { }
	Entity(int x_position, int y_position){
		this->x_pos = x_position;
		this->y_pos = y_position;
		this->free = true;
	}
	virtual ~Entity() {};
	
	int get_x_position() const { return x_pos; }
	int get_y_position() const { return y_pos; }
	void set_free(bool f){free = f;}
	bool is_free(){return free;}
	int get_size() const { return size; } // test
	
	
	virtual void updateImg() {};

protected:
	bool free;
	int size;
	int x_pos;
	int y_pos;
};

#endif
