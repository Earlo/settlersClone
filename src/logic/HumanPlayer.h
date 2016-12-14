#pragma once


#include "../Warehouse.h"

class HumanPlayer {

public:
	HumanPlayer(){
		all_wood = 0;
		all_stone = 0;
		all_iron = 0;
		woodcutters = 0;
		stoners = 0;
		ironers = 0;
		idlers = 0;
	
	}
	std::vector<Settler> settlers;

	void update(sf::RenderWindow &window, sf::View view){
		for(unsigned int i = 0; i < settlers.size(); i++){ //draw
			int x = settlers[i].get_x_position();
			int y = settlers[i].get_y_position();
			if ( x > view.getCenter().x-CAMCENTERX  && x < view.getCenter().x+CAMCENTERX
				&& y > view.getCenter().y-CAMCENTERY  && y < view.getCenter().y+CAMCENTERY){
				window.draw(settlers[i].sprite);
			}
		}
		
	}
	void play(){
		for(unsigned int i = 0; i < settlers.size(); i++){
			switch(settlers[i].get_task()){
			case Settler::TType::BUILD: //vielä kesken
				break;
			case Settler::TType::GATHERW:
				settlers[i].move(settlers[i].get_nearest());
				break;
			case Settler::TType::GATHERS:
				settlers[i].move(settlers[i].get_nearest());
				break;
			case Settler::TType::GATHERI:
				settlers[i].move(settlers[i].get_nearest());
				break;
			case Settler::TType::IDLE:
				break;			
			}
		}
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

	unsigned int get_woodcutters(){return woodcutters;}
	unsigned int get_stoners(){return stoners;}
	unsigned int get_ironers(){return ironers;}
	unsigned int get_idlers(){return idlers;}

	void increase_woodcutters(SpatialHash SHASH){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i].get_task() == Settler::TType::IDLE){
				settlers[i].set_task(Settler::TType::GATHERW);
				std::vector<int> v = settlers[i].nearest(SHASH, Resource::RType::TREE);
				settlers[i].set_nearest(v);
				woodcutters++;
				idlers--;
				break;
			}
		}
	}

	void increase_stoners(SpatialHash SHASH){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i].get_task() == Settler::TType::IDLE){
				settlers[i].set_task(Settler::TType::GATHERS);
				std::vector<int> v = settlers[i].nearest(SHASH, Resource::RType::STONE);
				settlers[i].set_nearest(v);
				stoners++;
				idlers--;
				break;
			}
		}
	}

	void increase_ironers(SpatialHash SHASH){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i].get_task() == Settler::TType::IDLE){
				settlers[i].set_task(Settler::TType::GATHERI);
				std::vector<int> v = settlers[i].nearest(SHASH, Resource::RType::IRON);
				settlers[i].set_nearest(v);
				ironers++;
				idlers--;
				break;
			}
		}
	}

	void decrease_woodcutters(){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i].get_task() == Settler::TType::GATHERW){
				settlers[i].set_task(Settler::TType::IDLE);
				woodcutters--;
				idlers++;
				break;
			}
		}
	}

	void decrease_stoners(){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i].get_task() == Settler::TType::GATHERS){
				settlers[i].set_task(Settler::TType::IDLE);
				stoners--;
				idlers++;
				break;
			}
		}
	}

	void decrease_ironers(){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i].get_task() == Settler::TType::GATHERI){
				settlers[i].set_task(Settler::TType::IDLE);
				ironers--;
				idlers++;
				break;
			}
		}
	}
	void increase_idlers(){idlers++;}

private:
	std::vector<Warehouse> warehouses;
	int all_wood;
	int all_stone;
	int all_iron;

	unsigned int woodcutters;
	unsigned int stoners;
	unsigned int ironers;
	unsigned int idlers;

};
