#ifndef FAMILYHOUSE_H
#define FAMILYHOUSE_H
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "../assets.h"

class FamilyHouse : public Building {
public:
	
	FamilyHouse(int x_position, int y_position, HumanPlayer* p);

	void updateImg();

private:
	HumanPlayer* pl;
	int size = 2;

};

#endif
