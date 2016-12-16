#ifndef FORTRESS_H
#define FORTRESS_H

#include "../assets.h"
#include "Building.h"


class Fortress : public Building {
public:

	Fortress(int x_position, int y_position, AssetHandler* ASSETHANDLER);
	~Fortress(){}
	
	void take_damage(int damage);
	void repair();

	void updateImg();

private:
	int health_points = 100;
	int size = 5;
	int required_settlers = 5;
};

#endif
