#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SFML/Graphics.hpp>
/*
#include "Tree.h"
#include "Stone.h"
#include "Iron.h"
#include "Settler.h"
*/
#include "Entity.h"
#include "../assets.h"

#include "../constants.h"

class Game {

public:
	//Game(std::vector<Entity*>& bVector){
	Game();

	void draw(sf::RenderWindow &window, sf::View view);
	std::vector<Entity*>* get_entities(){return &entities;}

	std::vector<Entity*> entities;
private:

};

#endif
