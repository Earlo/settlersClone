#include "Resource.h"

class Building {

public:
	
	Building(int x_position, int y_position) : x_pos(x_position), y_pos(y_position) { }

	int get_x_position() const { return x_pos; }
	int get_y_position() const { return y_pos; }
	int get_size() const { return size; }

	Resource get_required_wood() const { return required_wood; }
	Resource get_required_stone() const { return required_stone; }
	Resource get_required_iron() const { return required_iron; }

	unsigned int get_nof_inhabitants() const { return nof_inhabitants; } // Return true if the building has a settler.
	bool get_construction_status() const { return under_construction; }

protected:
	Resource required_wood;
	Resource required_stone;
	Resource required_iron;

	unsigned int nof_inhabitants; //Number of settlers inside the building.
	int size; //Size of the building
	int x_pos;
	int y_pos;
	bool under_construction; // false if the building is constructed
};


#endif  // SRC_BUILDING_H_