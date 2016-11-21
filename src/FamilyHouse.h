#pragma once
#pragma once
#include "Building.h"

class FamilyHouse : public Building {
public:
	void make_new_settlers();

private:
	health_points = 20;
	size = 2;
	required_settlers = 2;
	required_wood = 10;
	required_stone = 2;
	required_iron = 0;
};