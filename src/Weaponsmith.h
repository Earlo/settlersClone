#pragma once
#include "Building.h"
#include "Weapon.h"

#define max_weapons 5;

class Weaponsmith : public Building {
public:
	void make_weapon();
	void take_weapon();

private:
	int size = 3;
	unsigned int weapons;
	unsigned int max_inhabitants = 1;
};