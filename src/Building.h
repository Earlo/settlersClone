#ifndef BUILDING_H
#define BUILDING_H

#include "../constants.h"
#include "Entity.h"

class Building : public Entity {
public:

	Building(int x_position, int y_position, AssetHandler* ASSETHANDLER);
	
	void complete_building();
	
	//void add_settler(Settler sett) { settlers_inside.push_back(sett); }
	//unsigned int get_required_wood() const { return required_wood; }
	//unsigned int get_required_stone() const { return required_stone; }
	//unsigned int get_required_iron() const { return required_iron; }
	
	
	int needed_resource();
	void increase_current_wood(){current_wood++;}
	void increase_current_stone(){current_stone++;}
	void increase_current_iron(){current_iron++;}
	
	unsigned int get_current_wood(){return current_wood;}
	unsigned int get_current_stone(){return current_stone;}
	unsigned int get_current_iron(){return current_iron;}

	unsigned int get_required_wood(){return required_wood;}
	unsigned int get_required_stone(){return required_stone;}
	unsigned int get_required_iron(){return required_iron;}

	unsigned int get_total_wood(){return total_wood;}
	unsigned int get_total_stone(){return total_stone;}
	unsigned int get_total_iron(){return total_iron;}

	//unsigned int get_nof_inhabitants() const { return settlers_inside.size(); }
	
	bool get_construction_status() const { return under_construction; }

	unsigned int required_wood;
	unsigned int required_stone;
	unsigned int required_iron;

protected:
	
	unsigned int current_wood;
	unsigned int current_stone;
	unsigned int current_iron;

	unsigned int total_wood;
	unsigned int total_stone;
	unsigned int total_iron;

	//HumanPlayer* pl;
	unsigned int pop_increase = 0;

	unsigned int health_points;
	bool under_construction; // false if the building is constructed
};

#endif
