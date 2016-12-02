#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tree.h"
#include "Stone.h"
#include "Iron.h"

class Game {

public:
	Game(std::vector<Tree> TreeVector, std::vector<Stone> StoneVector, std::vector<Iron> IronVector){
		Trees = TreeVector;
		Stones = StoneVector;
		Irons = IronVector;
	}

	void draw(sf::RenderWindow &window){
		for(unsigned int i = 0; i < Trees.size(); i++){ // Draw the trees from Trees vector 
			window.draw(Trees[i].sprite);
		}
		for(unsigned int i = 0; i < Stones.size(); i++){ // Draw the stones
			window.draw(Stones[i].sprite);
		}
		for(unsigned int i = 0; i < Irons.size(); i++){ // Draw the irons NOT WORKING?
			window.draw(Irons[i].sprite);
		}


	}

	std::vector<Tree> get_trees(){return Trees;}
	
	std::vector<Stone> get_stones(){return Stones;}
	std::vector<Iron> get_irons(){return Irons;}

private:
	std::vector<Tree> Trees;
	std::vector<Stone> Stones;
	std::vector<Iron> Irons;

};
