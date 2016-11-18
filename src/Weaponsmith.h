#pragma once
#include "Building.h"

class Weaponsmith : public Building {
public:
	void build_weapon();
	void take_weapon();

private:
	int size = 5;

};