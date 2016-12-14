#include "Castle.h"

Castle::Castle(int x_position, int y_position, HumanPlayer* p) : Building(x_position, y_position){
	for(unsigned int i = 0; i < 10; i++){
		Settler* s = new Settler(x_position, y_position);
		p->settlers.push_back(s);
		p->increase_idlers();

	}
	this->updateImg();
}

void Castle::updateImg(){
	this->sprite.setTexture(ASSETHANDLER.CASTLETEX, true);
	
	this->sprite.setPosition( this->x_pos-ASSETHANDLER.CASTLEIMG.getSize().x/2, this->y_pos-ASSETHANDLER.CASTLEIMG.getSize().y );
}
