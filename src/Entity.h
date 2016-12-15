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
		this->hp = 2;
		//std::cout<<"at ent "<<this->get_x_position()<<","<<this->get_y_position()<<std::endl;

		this->free = true;
	}
	virtual ~Entity() {};
	
	int get_x_position() const { return x_pos; }
	int get_y_position() const { return y_pos; }
	void set_free(bool f){free = f;}
	bool is_free(){return free;}
	int get_size() const { return size; } // test
	
	
	virtual void updateImg() {};
	
	int get_hp(){return hp;}
	void minus_hp(){hp--;}
	bool check_hp(){
		if(hp < 0){
			return true;		
		}
		return false;
	}

protected:
	bool free;
	int size;
	int hp;
	int x_pos = 0;
	int y_pos = 0;
};

#endif
