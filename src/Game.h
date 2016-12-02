#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tree.h"

class Game {

public:
	Game(std::vector<Tree> TreeVector){
		Trees = TreeVector;
	}

	void draw(sf::RenderWindow &window){
		for(unsigned int i = 0; i < Trees.size(); i++){ // Draw the trees from Trees vector 
			window.draw(Trees[i].sprite);
		}

	}

	std::vector<Tree> get_trees(){return Trees;}
	

private:
	std::vector<Tree> Trees;

};
