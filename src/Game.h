#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

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
