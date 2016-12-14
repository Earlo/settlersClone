#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"


class Warehouse : public Building {
public:
	Warehouse(int x_position, int y_position);
	void take_wood();

	void take_stone();
	void take_iron();
	void take_weapon();

	void give_wood();

	void give_stone();

	void give_iron();
	void give_weapon();
	int get_wood(){return wood;}
	int get_stone(){return stone;}
	int get_iron(){return iron;}
	int get_weapons(){return weapon;}

	void updateImg();

private:
	int health_points = 100;
	int size = 5;
	unsigned int wood;
	unsigned int stone;
	unsigned int iron;
	unsigned int weapon;

};

#endif
