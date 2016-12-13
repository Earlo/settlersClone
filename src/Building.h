#ifndef BUILDING
#define BUILDING

//include "Resource.h"
//#include "Entity.h"
#include "Settler.h"


//forward declaration
class Settler;


//should inherint something along line class Drawable or something(?)
class Building : public Entity {

public:
	
	//Building(int x_position, int y_position) : x_pos(x_position), y_pos(y_position) { }
	Building(int x_position, int y_position)
		:Entity(x_position, y_position){
	}
	
	//void add_settler(Settler sett) { settlers_inside.push_back(sett); }

	//unsigned int get_required_wood() const { return required_wood; }
	//unsigned int get_required_stone() const { return required_stone; }
	//unsigned int get_required_iron() const { return required_iron; }

	unsigned int get_nof_inhabitants() const { return settlers_inside.size(); }
	
	bool get_construction_status() const { return under_construction; }

protected:
	std::vector<Settler> settlers_inside;
	
	unsigned int required_settlers;
	unsigned int required_wood;
	unsigned int required_stone;
	unsigned int required_iron;

	unsigned int health_points;
	bool under_construction; // false if the building is constructed
};

#endif
