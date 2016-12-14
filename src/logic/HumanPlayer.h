#pragma once

#include "Player.h"
#include "../Warehouse.h"

class HumanPlayer : public Player {

public:
	HumanPlayer(){
		all_wood = 0;
		all_stone = 0;
		all_iron = 0;	
	}
	void add_wh(Warehouse wh){
		warehouses.push_back(wh);
	}

	void update_resources(){
		int wood = 0;
		int stone = 0;
		int iron = 0;

		if(warehouses.size() > 0){
			for(auto i : warehouses){
				wood += i.get_wood();
				stone += i.get_stone();
				iron += i.get_iron();
			}
		}
		
		all_wood = wood;
		all_stone = stone;
		all_iron = iron;
	}
	
	int get_wood(){return all_wood;}
	int get_stone(){return all_stone;}
	int get_iron(){return all_iron;}

private:
	std::vector<Warehouse> warehouses;
	int all_wood;
	int all_stone;
	int all_iron;
};
