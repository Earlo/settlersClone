#pragma once
#include "Building.h"
#include "Weapon.h"

#define max_weapons 5;

class Weaponsmith : public Building {
public:
	void make_weapon();
	void take_weapon();

private:
	health_points = 30;
	size = 3;
	unsigned int weapons;
	required_settlers = 1;
	required_wood = 2;
	required_stone = 10;
	required_iron = 5;
};