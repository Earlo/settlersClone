#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(){
	all_wood = 0;
	all_stone = 0;
	all_iron = 0;
	builders = 0;
	woodcutters = 0;
	stoners = 0;
	ironers = 0;
	idlers = 0;

}


void HumanPlayer::update(sf::RenderWindow &window, sf::View view){
	for(unsigned int i = 0; i < settlers.size(); i++){ //draw
		int x = settlers[i]->get_x_position();
		int y = settlers[i]->get_y_position();
		if ( x > view.getCenter().x-CAMCENTERX  && x < view.getCenter().x+CAMCENTERX
			&& y > view.getCenter().y-CAMCENTERY  && y < view.getCenter().y+CAMCENTERY){
			window.draw(settlers[i]->sprite);
		}
	}
	
}
void HumanPlayer::play(SpatialHash* SHASH, Map* m){
	for(unsigned int i = 0; i < settlers.size(); i++){
		switch(settlers[i]->get_task()){
		case Settler::TType::BUILD:
			//std::cout<< buildings[0].get_x_position() <<std::endl;
			if ( buildings[0]->needed_resource() == 0 ){
				settlers[i]->workPhase = 0;
				settlers[i]->set_task(Settler::TType::IDLE);
				builders--;
				idlers++;
				settlers[i]->set_workclock(-300);
				break;
			}			
			if(buildings[0]->get_construction_status() && settlers[i]->workPhase == 0){ //workPhase is used to determine the part of the job that the settler is doing.
				settlers[i]->set_nearest(warehouse_pos());
				settlers[i]->move(settlers[i]->get_nearest(), m);
				settlers[i]->workPhase = 1;
			}
			if(settlers[i]->workPhase == 1 && settlers[i]->get_x_position() == warehouses[0]->get_x_position() && settlers[i]->get_y_position() == warehouses[0]->get_y_position()){
			
					if(buildings[0]->needed_resource() == 1 && warehouses[0]->get_wood() > 0){
						warehouses[0]->take_wood();
						settlers[i]->set_nearest(build_position(buildings[0]));
						settlers[i]->move(settlers[i]->get_nearest(), m);
						buildings[0]->required_wood -= 1;
						settlers[i]->workPhase = 2;
					}
					else if(buildings[0]->needed_resource() == 2 && warehouses[0]->get_stone() > 0){
						//std::cout << "takes stone" << std::endl;							
						warehouses[0]->take_stone();
						settlers[i]->set_nearest(build_position(buildings[0]));
						settlers[i]->move(settlers[i]->get_nearest(), m);
						buildings[0]->required_stone -= 1;
						settlers[i]->workPhase = 3;
					
					}
					else if(buildings[0]->needed_resource() == 3 && warehouses[0]->get_iron() > 0){
						//std::cout << "takes iron" << std::endl;						
						warehouses[0]->take_iron();
						settlers[i]->set_nearest(build_position(buildings[0]));
						settlers[i]->move(settlers[i]->get_nearest(), m);
						buildings[0]->required_iron -= 1;
						settlers[i]->workPhase = 4;
					}
					else{
						//no resource
						settlers[i]->workPhase = 0;
						settlers[i]->set_task(Settler::TType::IDLE);
						builders--;
						idlers++;
						settlers[i]->set_workclock(-300);
						break;
					}
					
				
			}
			//GO TO BUILDING WITH WOOD
			if(settlers[i]->workPhase == 2 && settlers[i]->get_x_position() == buildings[0]->get_x_position() && settlers[i]->get_y_position() == buildings[0]->get_y_position()){
						//std::cout << "brings wood to building" << std::endl;
						settlers[i]->workPhase = 5;
						buildings[0]->increase_current_wood();
						settlers[i]->set_nearest(warehouse_pos());
						settlers[i]->move(settlers[i]->get_nearest(), m);
			}			

			//GO TO BUILDING WITH STONE
			if(settlers[i]->workPhase == 3 && settlers[i]->get_x_position() == buildings[0]->get_x_position() && settlers[i]->get_y_position() == buildings[0]->get_y_position()){
						settlers[i]->workPhase = 5;
						buildings[0]->increase_current_stone();
						settlers[i]->set_nearest(warehouse_pos());
						settlers[i]->move(settlers[i]->get_nearest(), m);				
			}

			//GO TO BUILDING WITH IRON
			if(settlers[i]->workPhase == 4 && settlers[i]->get_x_position() == buildings[0]->get_x_position() && settlers[i]->get_y_position() == buildings[0]->get_y_position()){
						settlers[i]->workPhase = 5;
						buildings[0]->increase_current_iron();
						settlers[i]->set_nearest(warehouse_pos());
						settlers[i]->move(settlers[i]->get_nearest(), m);				
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
				settlers[i]->move(settlers[i]->get_nearest(), m);
			}
		
			
			
			break;

		case Settler::TType::GATHERW:

			//GO TO TREE WAIT 5 SEC AND TAKE 1 TREE
			if(settlers[i]->get_x_position() == settlers[i]->get_near_x() && settlers[i]->get_y_position() == settlers[i]->get_near_y()){
				if(settlers[i]->get_workclock() > 300){
					settlers[i]->set_nearest(warehouse_pos());
					settlers[i]->set_workclock(-300);
			SHASH->trees[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->minus_hp();
			//MINUS HP AND SET TREE SO IT CANT BE ACCESSED ANYMORE
			if(SHASH->trees[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->check_hp()){
				SHASH->trees[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->set_free(false);
				//delete(SHASH->trees[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]);
				//SHASH->trees[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH].erase(
				//	SHASH->trees[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH].begin() +settlers[i]->get_near_a());
			}	
			else{SHASH->trees[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->set_free(true);}
					settlers[i]->move(settlers[i]->get_nearest(), m);
					settlers[i]->workPhase = 1;
				}
				else{settlers[i]->set_workclock(1);}
			}
			//MAKE SETTLERS WORK CONSTANTLY
			if( settlers[i]->workPhase == 1 && settlers[i]->get_x_position() == warehouses[0]->get_x_position() && settlers[i]->get_y_position() == warehouses[0]->get_y_position()){
				warehouses[0]->give_wood();
				settlers[i]->set_task(Settler::TType::GATHERW);
				std::vector<int> v = settlers[i]->nearest(SHASH, Resource::RType::TREE);
				settlers[i]->workPhase = 0;
				settlers[i]->set_nearest(v);				
				settlers[i]->set_workclock(-300);
			}
			//MOVE SETTLERS
			else{settlers[i]->move(settlers[i]->get_nearest(), m);}
			break;

		case Settler::TType::GATHERS:

			//GO TO STONE WAIT 5 SEC AND TAKE 1 STONE
			if(settlers[i]->get_x_position() == settlers[i]->get_near_x() && settlers[i]->get_y_position() == settlers[i]->get_near_y()){
				if(settlers[i]->get_workclock() > 300){
					settlers[i]->set_nearest(warehouse_pos());
					settlers[i]->set_workclock(-300);
			SHASH->stone[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->minus_hp();
			//MINUS HP AND SET STONE SO IT CANT BE ACCESSED ANYMORE
			if(SHASH->stone[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->check_hp()){
				SHASH->stone[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->set_free(false);
				//delete(SHASH->stone[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]);
			}
			else{SHASH->stone[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->set_free(true);}
					settlers[i]->move(settlers[i]->get_nearest(), m);
					settlers[i]->workPhase = 1;
				}
				else{settlers[i]->set_workclock(1);}
			}
			//MAKE SETTLERS WORK CONSTANTLY
			if(settlers[i]->workPhase == 1 && settlers[i]->get_x_position() == warehouses[0]->get_x_position() && settlers[i]->get_y_position() == warehouses[0]->get_y_position()){
				warehouses[0]->give_stone();
				settlers[i]->set_task(Settler::TType::GATHERS);
				std::vector<int> v = settlers[i]->nearest(SHASH, Resource::RType::STONE);
				settlers[i]->workPhase = 0;
				settlers[i]->set_nearest(v);
				settlers[i]->set_workclock(-300);
			}
			//MOVE SETTLERS
			else{settlers[i]->move(settlers[i]->get_nearest(), m);}
			break;

		case Settler::TType::GATHERI:

			//GO TO IRON WAIT 5 SEC AND TAKE 1 IRON
			if(settlers[i]->get_x_position() == settlers[i]->get_near_x() && settlers[i]->get_y_position() == settlers[i]->get_near_y()){
				if(settlers[i]->get_workclock() > 300){
					settlers[i]->set_nearest(warehouse_pos());
					settlers[i]->set_workclock(-300);
			SHASH->iron[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->minus_hp();
			//MINUS HP AND SET IRON SO IT CANT BE ACCESSED ANYMORE
			if(SHASH->iron[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->check_hp()){
				SHASH->iron[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->set_free(false);
				//delete(SHASH->iron[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]);
			}
			else{SHASH->iron[settlers[i]->get_x_position()/ENTHASH][settlers[i]->get_y_position()/ENTHASH][settlers[i]->get_near_a()]->set_free(true);}
					settlers[i]->move(settlers[i]->get_nearest(), m);
					settlers[i]->workPhase = 1;
				}
				else{settlers[i]->set_workclock(1);}
			}
			//MAKE SETTLERS WORK CONSTANTLY
			if(settlers[i]->workPhase == 1 && settlers[i]->get_x_position() == warehouses[0]->get_x_position() && settlers[i]->get_y_position() == warehouses[0]->get_y_position()){
				warehouses[0]->give_iron();
				settlers[i]->set_task(Settler::TType::GATHERI);
				std::vector<int> v = settlers[i]->nearest(SHASH, Resource::RType::IRON);
				settlers[i]->workPhase = 0;
				settlers[i]->set_nearest(v);
				settlers[i]->set_workclock(-300);
				
			}
			//MOVE SETTLERS
			else{settlers[i]->move(settlers[i]->get_nearest(), m);}
			break;
		case Settler::TType::IDLE:
			break;			
		}
	}
}

void HumanPlayer::add_wh(Warehouse* wh){
	warehouses.push_back(wh);
}

void HumanPlayer::update_resources(){
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

							//BUTTON TO MAKE IDLE SETTLERS GATHER TREE
void HumanPlayer::increase_woodcutters(SpatialHash* SHASH){
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
							//BUTTON TO MAKE IDLE SETTLERS GATHER STONE
void HumanPlayer::increase_stoners(SpatialHash* SHASH){
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
							//BUTTON TO MAKE IDLE SETTLERS GATHER IRON
void HumanPlayer::increase_ironers(SpatialHash* SHASH){
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
							//BUTTON TO MAKE WOOD GATHERING SETTLERS IDLE
void HumanPlayer::decrease_woodcutters(){
	for(unsigned int i = 0; i < settlers.size(); i++){
		if(settlers[i]->get_task() == Settler::TType::GATHERW){
			settlers[i]->set_task(Settler::TType::IDLE);
			woodcutters--;
			idlers++;
			break;
		}
	}
}
							//BUTTON TO MAKE STONE GATHERING SETTLERS IDLE
void HumanPlayer::decrease_stoners(){
	for(unsigned int i = 0; i < settlers.size(); i++){
		if(settlers[i]->get_task() == Settler::TType::GATHERS){
			settlers[i]->set_task(Settler::TType::IDLE);
			stoners--;
			idlers++;
			break;
		}
	}
}
							//BUTTON TO MAKE IRON GATHERING SETTLERS IDLE
void HumanPlayer::decrease_ironers(){
	for(unsigned int i = 0; i < settlers.size(); i++){
		if(settlers[i]->get_task() == Settler::TType::GATHERI){
			settlers[i]->set_task(Settler::TType::IDLE);
			ironers--;
			idlers++;
			break;
		}
	}
}
void HumanPlayer::increase_builders(){
	if(buildings.size() > 0){ //check if there are any buildings to build
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
}


std::vector<int> HumanPlayer::warehouse_pos(){ // MOVE FUNCTION IN SETTLERS TAKE VECTOR<INT> SO THIS MUST BE DONE, NOT TOO SMART
	std::vector<int> v;
	v.push_back(warehouses[0]->get_x_position());
	v.push_back(warehouses[0]->get_y_position());
	return v;
}
std::vector<int> HumanPlayer::build_position(Building *b){ // MOVE FUNCTION IN SETTLERS TAKE VECTOR<INT> SO THIS MUST BE DONE, NOT TOO SMART
	std::vector<int> pos;
	pos.push_back(b->get_x_position());
	pos.push_back(b->get_y_position());
	return pos;
}

