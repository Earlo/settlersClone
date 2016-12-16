#ifndef RESOURCE_H
#define RESOURCE_H

#include "Entity.h"

class Resource : public Entity{
public:
	
	enum class RType { TREE, STONE, IRON };
	
	Resource(int x_position, int y_position, Resource::RType t, AssetHandler* ASSETHANDLER);

	void updateImg();
	unsigned int get_resource_amount() { return resource_amount; }

	Resource::RType get_resource_type() { return type; }

	void take_resource();

private:
	Resource::RType type;
	unsigned int resource_amount = 5;

};

#endif
