#pragma once

#include "Player.h"

class HumanPlayer : public Player {

public:
	HumanPlayer(){
		all_wood = 0;
		all_stone = 0;
		all_iron = 0;	
	}

	/*update_resources(std::vector<Warehouse> whouses){
		for(auto i : whouses){
			all_wood += i.get_wood();
			all_iron += i.get_stone();
			all_stone += i.get_iron();
		}
	}*/

private:
	int all_wood;
	int all_stone;
	int all_iron;
};
