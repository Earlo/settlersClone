#ifndef CASTLE_H
#define CASTLE_H
#include "Building.h"

#include <SFML/Graphics.hpp>
#include "Settler.h"
#include "logic/HumanPlayer.h"


class Castle : public Building {
public:

	Castle(int x_position, int y_position, HumanPlayer* p, AssetHandler* ASSETHANDLER);

	void updateImg();

private:
	int health_points = 100;
	int size = 5;
};

#endif
