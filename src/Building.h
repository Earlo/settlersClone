#include "Resource.h"
#include "Settler.h"

class Building {

public:
	
	Building(int x_position, int y_position) : x_pos(x_position), y_pos(y_position) { }

	int get_x_position() const { return x_pos; }
	int get_y_position() const { return y_pos; }
	int get_size() const { return size; } // test
	void add_settler(){}

	unsigned int get_required_wood() const { return required_wood; }
	unsigned int get_required_stone() const { return required_stone; }
	unsigned int get_required_iron() const { return required_iron; }

	unsigned int get_nof_inhabitants() const { return nof_inhabitants; } // Return true if the building has a settler.
	bool get_construction_status() const { return under_construction; }

protected:
	vector<Settler> settlers_inside;
	unsigned int required_settlers;
	unsigned int required_wood;
	unsigned int required_stone;
	unsigned int required_iron;

	unsigned int health_points;
	int size; //Size of the building
	int x_pos;
	int y_pos;
	bool under_construction; // false if the building is constructed
};


#endif  // SRC_BUILDING_H_