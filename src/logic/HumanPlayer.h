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

	unsigned int get_woodcutters(){return woodcutters.size();}
	unsigned int get_stoners(){return stoners.size();}
	unsigned int get_ironers(){return ironers.size();}
	unsigned int get_idlers(){return idle.size();}

	void increase_woodcutters(){
		if(idle.size() > 0){
			woodcutters.push_back(idle[0]);
			idle.erase(idle.begin());
		}
	}

	void increase_stoners(){
		if(idle.size() > 0){
			stoners.push_back(idle[0]);
			idle.erase(idle.begin());
		}
	}

	void increase_ironers(){
		if(idle.size() > 0){
			ironers.push_back(idle[0]);
			idle.erase(idle.begin());
		}
	}

	void decrease_woodcutters(){
		if(woodcutters.size() > 0){
			idle.push_back(woodcutters[0]);
			woodcutters.erase(woodcutters.begin());
		}
	}
	void decrease_stoners(){
		if(stoners.size() > 0){
			idle.push_back(stoners[0]);
			stoners.erase(stoners.begin());
		}
	}
	void decrease_ironers(){
		if(ironers.size() > 0){
			idle.push_back(ironers[0]);
			ironers.erase(ironers.begin());
		}
	}
	void add_to_idle(Settler sett){
		idle.push_back(sett);
	}

private:
	std::vector<Warehouse> warehouses;
	int all_wood;
	int all_stone;
	int all_iron;

	std::vector<Settler> woodcutters;
	std::vector<Settler> stoners;
	std::vector<Settler> ironers;
	std::vector<Settler> idle;
};
