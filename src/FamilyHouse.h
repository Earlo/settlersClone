#ifndef FAMILYHOUSE_H
#define FAMILYHOUSE_H

#include <SFML/Graphics.hpp>
#include "../assets.h"
#include "Building.h"
#include "Settler.h"
#include "logic/HumanPlayer.h"

class FamilyHouse : public Building {
public:
	
	FamilyHouse(int x_position, int y_position, HumanPlayer* p, AssetHandler* ASSETHANDLER);

	void updateImg();

private:
	HumanPlayer* pl;
	int size = 2;
};

#endif
