#pragma once
#pragma once
#include "Building.h"

class FamilyHouse : public Building {
public:
	void make_new_settlers();

private:
	int size = 2;
	unsigned int max_inhabitants = 6;
};