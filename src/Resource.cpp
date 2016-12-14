#include "Resource.h"

Resource::Resource(int x_position, int y_position, Resource::RType t):Entity(x_position, y_position){
	this->type = t;
	this->updateImg();
	//std::cout<<"at res "<<this->get_x_position()<<","<<this->get_y_position()<<std::endl;
}


void Resource::updateImg() {
	switch (this->get_resource_type()) {
	case Resource::RType::TREE:
		this->sprite.setTexture(ASSETHANDLER.TREETEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.TREEIMG.getSize().x/2, this->y_pos-ASSETHANDLER.TREEIMG.getSize().y );
		break;
	case Resource::RType::STONE:
		this->sprite.setTexture(ASSETHANDLER.STONETEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.STONEIMG.getSize().x/2, this->y_pos-ASSETHANDLER.STONEIMG.getSize().y );
		break;
	case Resource::RType::IRON:
		this->sprite.setTexture(ASSETHANDLER.IRONTEX, true);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.IRONIMG.getSize().x/2, this->y_pos-ASSETHANDLER.IRONIMG.getSize().y );
		break;

	}
}

