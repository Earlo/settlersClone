#ifndef WEAPONSMITH_H
#define WEAPONSMITH_H


#include "Building.h"
#include "../assets.h"

#define max_weapons 5;

class Weaponsmith : public Building {
public:

	void make_weapon();
	void take_weapon();
	Weaponsmith(int x_position, int y_position, AssetHandler* ASSETHANDLER);

	void updateImg();

private:

	unsigned int weapons;
	int required_settlers = 1;

};

#endif
