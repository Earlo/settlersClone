#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "SpatialHash.h"
#include "../Warehouse.h"
#include "../Settler.h"

class HumanPlayer {
public:
	HumanPlayer();
	std::vector<Settler*> settlers;
	std::vector<Building*> buildings;
	std::vector<Warehouse*> warehouses;


	void update(sf::RenderWindow &window, sf::View view);
	void play(SpatialHash* SHASH, Map* m);
	void add_wh(Warehouse* wh);
	void update_resources();
	
	int get_wood(){return all_wood;}
	int get_stone(){return all_stone;}
	int get_iron(){return all_iron;}

	unsigned int get_woodcutters(){return woodcutters;}
	unsigned int get_stoners(){return stoners;}
	unsigned int get_ironers(){return ironers;}
	unsigned int get_idlers(){return idlers;}
								//BUTTON TO MAKE IDLE SETTLERS GATHER TREE
	void increase_woodcutters(SpatialHash* SHASH);
								//BUTTON TO MAKE IDLE SETTLERS GATHER STONE
	void increase_stoners(SpatialHash* SHASH);
								//BUTTON TO MAKE IDLE SETTLERS GATHER IRON
	void increase_ironers(SpatialHash* SHASH);
								//BUTTON TO MAKE WOOD GATHERING SETTLERS IDLE
	void decrease_woodcutters();
								//BUTTON TO MAKE STONE GATHERING SETTLERS IDLE
	void decrease_stoners();
								//BUTTON TO MAKE IRON GATHERING SETTLERS IDLE
	void decrease_ironers();
	
	void increase_builders();
	void increase_idlers(){idlers++;}

	std::vector<int> warehouse_pos();
	std::vector<int> build_position(Building *b);

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

#endif
