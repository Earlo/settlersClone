#ifndef BUILDING
#define BUILDING

//include "Resource.h"
//#include "Entity.h"
#include "Settler.h"
#include "../constants.h"

//forward declaration
class Settler;


//should inherint something along line class Drawable or something(?)
class Building : public Entity {

public:
	
	//Building(int x_position, int y_position) : x_pos(x_position), y_pos(y_position) { }
	Building(int x_position, int y_position)
		:Entity(x_position, y_position){
	this->current_wood = 0;
	this->current_stone = 0;
	this->current_iron = 0;
	}
	
	void complete_building(){
		this->under_construction = false;
	}
	
	//void add_settler(Settler sett) { settlers_inside.push_back(sett); }

	//unsigned int get_required_wood() const { return required_wood; }
	//unsigned int get_required_stone() const { return required_stone; }
	//unsigned int get_required_iron() const { return required_iron; }
	
	
	int needed_resource(){
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
	void increase_current_wood(){current_wood++;}
	void increase_current_stone(){current_stone++;}
	void increase_current_iron(){current_iron++;}
	
	unsigned int get_current_wood(){return current_wood;}
	unsigned int get_current_stone(){return current_stone;}
	unsigned int get_current_iron(){return current_iron;}
	
	unsigned int get_nof_inhabitants() const { return settlers_inside.size(); }
	
	bool get_construction_status() const { return under_construction; }

protected:
	std::vector<Settler> settlers_inside;
	
	unsigned int current_wood;
	unsigned int current_stone;
	unsigned int current_iron;

	unsigned int required_iron;
	unsigned int required_wood;
	unsigned int required_stone;

	unsigned int health_points;
	bool under_construction; // false if the building is constructed
};

#endif
