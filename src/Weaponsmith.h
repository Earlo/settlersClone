#ifndef WEAPONSMITH_H
#define WEAPONSMITH_H
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"

#define max_weapons 5;

class Weaponsmith : public Building {
public:

	void make_weapon();
	void take_weapon();
	Weaponsmith(int x_position, int y_position);

	void updateImg();

private:

	unsigned int weapons;
	int required_settlers = 1;

};

#endif
