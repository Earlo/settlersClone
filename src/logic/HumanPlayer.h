#pragma once


#include "../Warehouse.h"

class HumanPlayer {

public:
	HumanPlayer(){
		all_wood = 0;
		all_stone = 0;
		all_iron = 0;
		builders = 0;
		woodcutters = 0;
		stoners = 0;
		ironers = 0;
		idlers = 0;
	
	}
	std::vector<Settler*> settlers;
	std::vector<Building*> buildings;
	std::vector<Warehouse*> warehouses;


	void update(sf::RenderWindow &window, sf::View view){
		for(unsigned int i = 0; i < settlers.size(); i++){ //draw
			int x = settlers[i]->get_x_position();
			int y = settlers[i]->get_y_position();
			if ( x > view.getCenter().x-CAMCENTERX  && x < view.getCenter().x+CAMCENTERX
				&& y > view.getCenter().y-CAMCENTERY  && y < view.getCenter().y+CAMCENTERY){
				window.draw(settlers[i]->sprite);
			}
		}
		
	}
	void play(){
		for(unsigned int i = 0; i < settlers.size(); i++){
			switch(settlers[i]->get_task()){
			case Settler::TType::BUILD:
				std::cout << buildings[0]->needed_resource() << std::endl;
				for(unsigned int b = 0; b < buildings.size(); b++){
				if(buildings[b]->get_construction_status() && settlers[i]->workPhase == 0){
					settlers[i]->set_nearest(warehouse_pos());
					settlers[i]->move(settlers[i]->get_nearest());
					settlers[i]->workPhase = 1;
				}
			
				if(settlers[i]->workPhase == 1 && settlers[i]->get_x_position() == warehouses[0]->get_x_position() && settlers[i]->get_y_position() == warehouses[0]->get_y_position()){
					if(buildings[b]->needed_resource() == 1 && warehouses[0]->get_wood() > 0){
						settlers[i]->workPhase = 2;
						std::cout << "takes wood" << std::endl;
						warehouses[0]->take_wood();
						settlers[i]->set_nearest(build_position(buildings[b]));
						settlers[i]->move(settlers[i]->get_nearest());
						
					}
					else if(buildings[b]->needed_resource() == 2 && warehouses[0]->get_stone() > 0){
						std::cout << "takes stone" << std::endl;							
						warehouses[0]->take_stone();
						settlers[i]->set_nearest(build_position(buildings[b]));
						settlers[i]->move(settlers[i]->get_nearest());
						settlers[i]->workPhase = 3;
						
					}
					else if(buildings[b]->needed_resource() == 3 && warehouses[0]->get_iron() > 0){
						std::cout << "takes iron" << std::endl;						
						warehouses[0]->take_iron();
						settlers[i]->set_nearest(build_position(buildings[b]));
						settlers[i]->move(settlers[i]->get_nearest());
						settlers[i]->workPhase = 4;
						
					}
					else{
						std::cout << warehouses[0]->get_wood() << std::endl;
						std::cout << warehouses[0]->get_stone() << std::endl;
						std::cout << warehouses[0]->get_iron() << std::endl;
						std::cout << "shit is empty" << std::endl;
						buildings[b]->complete_building();
						settlers[i]->workPhase = 0;
						settlers[i]->set_task(Settler::TType::IDLE);
						builders--;
						idlers++;
						settlers[i]->set_workclock(-300);
						
						
					}
						
					
					}
				
				}
				//GO TO BUILDING WITH WOOD
				if(settlers[i]->workPhase == 2 && settlers[i]->get_x_position() == buildings[0]->get_x_position() && settlers[i]->get_y_position() == buildings[0]->get_y_position()){
							std::cout << "brings wood to building" << std::endl;
							settlers[i]->workPhase = 5;
							buildings[0]->increase_current_wood();
							settlers[i]->set_nearest(warehouse_pos());
							settlers[i]->move(settlers[i]->get_nearest());
				}			

				//GO TO BUILDING WITH STONE
				if(settlers[i]->workPhase == 3 && settlers[i]->get_x_position() == buildings[0]->get_x_position() && settlers[i]->get_y_position() == buildings[0]->get_y_position()){
							settlers[i]->workPhase = 5;
							buildings[0]->increase_current_stone();
							settlers[i]->set_nearest(warehouse_pos());
							settlers[i]->move(settlers[i]->get_nearest());				
				}

				//GO TO BUILDING WITH IRON
				if(settlers[i]->workPhase == 4 && settlers[i]->get_x_position() == buildings[0]->get_x_position() && settlers[i]->get_y_position() == buildings[0]->get_y_position()){
							settlers[i]->workPhase = 5;
							buildings[0]->increase_current_iron();
							settlers[i]->set_nearest(warehouse_pos());
							settlers[i]->move(settlers[i]->get_nearest());				
				}
				//GO BACK TO WAREHOUSE
				if(settlers[i]->workPhase == 5 && settlers[i]->get_x_position() == warehouses[0]->get_x_position() && settlers[i]->get_y_position() == warehouses[0]->get_y_position()){
							settlers[i]->workPhase = 0;
							settlers[i]->set_task(Settler::TType::IDLE);
							builders--;
							idlers++;
							settlers[i]->set_workclock(-300);		
				}
				else{
					settlers[i]->move(settlers[i]->get_nearest());
				}
			
				
				
				break;
			case Settler::TType::GATHERW:
				if(settlers[i]->get_x_position() == settlers[i]->get_near_x() && settlers[i]->get_y_position() == settlers[i]->get_near_y()){
					if(settlers[i]->get_workclock() > 300){
						settlers[i]->set_nearest(warehouse_pos());
						settlers[i]->set_workclock(-300);
						settlers[i]->move(settlers[i]->get_nearest());
						settlers[i]->workPhase = 1;
					}
					else{settlers[i]->set_workclock(1);}
				}
				if( settlers[i]->workPhase == 1 && settlers[i]->get_x_position() == warehouses[0]->get_x_position() && settlers[i]->get_y_position() == warehouses[0]->get_y_position()){
					settlers[i]->workPhase = 0;
					settlers[i]->set_task(Settler::TType::IDLE);
					woodcutters--;
					idlers++;
					warehouses[0]->give_wood();					
					settlers[i]->set_workclock(-300);
				}
				else{settlers[i]->move(settlers[i]->get_nearest());}
				break;
			case Settler::TType::GATHERS:
				if(settlers[i]->get_x_position() == settlers[i]->get_near_x() && settlers[i]->get_y_position() == settlers[i]->get_near_y()){
					if(settlers[i]->get_workclock() > 300){
						settlers[i]->set_nearest(warehouse_pos());
						settlers[i]->set_workclock(-300);
						settlers[i]->move(settlers[i]->get_nearest());
						settlers[i]->workPhase = 1;
					}
					else{settlers[i]->set_workclock(1);}
				}
				if(settlers[i]->workPhase == 1 && settlers[i]->get_x_position() == warehouses[0]->get_x_position() && settlers[i]->get_y_position() == warehouses[0]->get_y_position()){
					settlers[i]->set_task(Settler::TType::IDLE);
					stoners--;
					idlers++;
					warehouses[0]->give_stone();
					settlers[i]->set_workclock(-300);
				}
				else{settlers[i]->move(settlers[i]->get_nearest());}
				break;
			case Settler::TType::GATHERI:
				if(settlers[i]->get_x_position() == settlers[i]->get_near_x() && settlers[i]->get_y_position() == settlers[i]->get_near_y()){
					if(settlers[i]->get_workclock() > 300){
						settlers[i]->set_nearest(warehouse_pos());
						settlers[i]->set_workclock(-300);
						settlers[i]->move(settlers[i]->get_nearest());
						settlers[i]->workPhase = 1;
					}
					else{settlers[i]->set_workclock(1);}
				}
				if(settlers[i]->workPhase == 1 && settlers[i]->get_x_position() == warehouses[0]->get_x_position() && settlers[i]->get_y_position() == warehouses[0]->get_y_position()){
					settlers[i]->set_task(Settler::TType::IDLE);
					ironers--;
					idlers++;
					warehouses[0]->give_iron();
					settlers[i]->set_workclock(-300);
					
				}
				else{settlers[i]->move(settlers[i]->get_nearest());}
				break;
			case Settler::TType::IDLE:
				break;			
			}
		}
	}

	void add_wh(Warehouse* wh){
		warehouses.push_back(wh);
	}

	void update_resources(){
		int wood = 0;
		int stone = 0;
		int iron = 0;

		if(warehouses.size() > 0){
			for(auto i : warehouses){
				wood += i->get_wood();
				stone += i->get_stone();
				iron += i->get_iron();
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

	void increase_woodcutters(SpatialHash* SHASH){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i]->get_task() == Settler::TType::IDLE){
				settlers[i]->set_task(Settler::TType::GATHERW);
				std::vector<int> v = settlers[i]->nearest(SHASH, Resource::RType::TREE);
				settlers[i]->workPhase = 0;
				settlers[i]->set_nearest(v);
				woodcutters++;
				idlers--;
				break;
			}
		}
	}

	void increase_stoners(SpatialHash* SHASH){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i]->get_task() == Settler::TType::IDLE){
				settlers[i]->set_task(Settler::TType::GATHERS);
				std::vector<int> v = settlers[i]->nearest(SHASH, Resource::RType::STONE);
				settlers[i]->workPhase = 0;
				settlers[i]->set_nearest(v);
				stoners++;
				idlers--;
				break;
			}
		}
	}

	void increase_ironers(SpatialHash* SHASH){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i]->get_task() == Settler::TType::IDLE){
				settlers[i]->set_task(Settler::TType::GATHERI);
				std::vector<int> v = settlers[i]->nearest(SHASH, Resource::RType::IRON);
				settlers[i]->workPhase = 0;
				settlers[i]->set_nearest(v);
				ironers++;
				idlers--;
				break;
			}
		}
	}

	void decrease_woodcutters(){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i]->get_task() == Settler::TType::GATHERW){
				settlers[i]->set_task(Settler::TType::IDLE);
				woodcutters--;
				idlers++;
				break;
			}
		}
	}

	void decrease_stoners(){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i]->get_task() == Settler::TType::GATHERS){
				settlers[i]->set_task(Settler::TType::IDLE);
				stoners--;
				idlers++;
				break;
			}
		}
	}

	void decrease_ironers(){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i]->get_task() == Settler::TType::GATHERI){
				settlers[i]->set_task(Settler::TType::IDLE);
				ironers--;
				idlers++;
				break;
			}
		}
	}
	void increase_builders(){
		for(unsigned int i = 0; i < settlers.size(); i++){
			if(settlers[i]->get_task() == Settler::TType::IDLE){
				settlers[i]->set_task(Settler::TType::BUILD);
				settlers[i]->workPhase = 0;
				builders++;
				idlers--;
				break;
			}
		}
	}
	void increase_idlers(){idlers++;}

	std::vector<int> warehouse_pos(){
		std::vector<int> v;
		v.push_back(warehouses[0]->get_x_position());
		v.push_back(warehouses[0]->get_y_position());
		return v;
	}
	std::vector<int> build_position(Building *b){
		std::vector<int> pos;
		pos.push_back(b->get_x_position());
		pos.push_back(b->get_y_position());
		return pos;
	}

private:

	int all_wood;
	int all_stone;
	int all_iron;

	unsigned int builders;
	unsigned int woodcutters;
	unsigned int stoners;
	unsigned int ironers;
	unsigned int idlers;

};