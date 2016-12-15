#include "Settler.h"

//has been forward declared
#include "logic/SpatialHash.h"

Settler::Settler(int x_position, int y_position, AssetHandler* ASSETHANDLER ):Entity(x_position, y_position, ASSETHANDLER){
	this->task = Settler::TType::IDLE;
	this->updateImg();
	this->workclock = 0;
}

void Settler::updateImg(){
	this->sprite.setTexture(ASSETHANDLER->SETTLERTEX, true);
	this->sprite.setPosition( this->x_pos-ASSETHANDLER->SETTLERIMG.getSize().x/2, this->y_pos-ASSETHANDLER->SETTLERIMG.getSize().y );
}

std::vector<int> Settler::nearest(SpatialHash* SHASH, Resource::RType t){
	int x = this->get_x_position()/ENTHASH;
	int y = this->get_y_position()/ENTHASH;
	int targetX;
	int targetY;
	int targetNUM;
	

	double matka = 10000;
	bool done = false;
	std::vector<int> v;
	for(int dis = 0;dis < HASHX; dis++){
		for(int i = x - dis; i <= (x + dis); i++){
			for(int j = y - dis; j <= (y + dis); j++){
				if( i >= 0 && j >= 0 && i <= HASHX -1 && j <= HASHY -1){
				switch (t) {
					case Resource::RType::TREE:
					for(unsigned int a = 0; a < SHASH->trees[i][j].size(); a++){
						if(SHASH->trees[i][j][a]->is_free()){
							double tang  = sqrt(pow(SHASH->trees[i][j][a]->get_x_position() - x, 2) + pow(SHASH->trees[i][j][a]->get_y_position() - y, 2));
							if(matka > tang){
								matka = tang;
								targetX = SHASH->trees[i][j][a]->get_x_position();
								targetY = SHASH->trees[i][j][a]->get_y_position();
								targetNUM = a;
								done = true;
							}
						}
					}
					if(done){
						v.push_back(targetX);
						v.push_back(targetY);
						v.push_back(targetNUM);
						SHASH->trees[targetX/ENTHASH][targetY/ENTHASH][targetNUM]->set_free(false);
						//std::cout<< SHASH->trees[targetX/ENTHASH][targetY/ENTHASH][targetNUM]->is_free()<<std::endl;
						return v;
					}
					break;
					case Resource::RType::STONE:
						for(unsigned int a = 0; a < SHASH->stone[i][j].size(); a++){
							if(SHASH->stone[i][j][a]->is_free()){
								double tang  = sqrt(pow(SHASH->stone[i][j][a]->get_x_position() - x, 2) + pow(SHASH->stone[i][j][a]->get_y_position() - y, 2));
								if(matka > tang){
									matka = tang;
									targetX = SHASH->stone[i][j][a]->get_x_position();
									targetY = SHASH->stone[i][j][a]->get_y_position();
									targetNUM = a;
								}
							}
						}
						if(matka != 10000){
							v.push_back(targetX);
							v.push_back(targetY);
							v.push_back(targetNUM);
							SHASH->stone[targetX/ENTHASH][targetY/ENTHASH][targetNUM]->set_free(false);
							return v;
						}
						break;
					case Resource::RType::IRON:
						for(unsigned int a = 0; a < SHASH->iron[i][j].size(); a++){
							if(SHASH->iron[i][j][a]->is_free()){
								double tang  = sqrt(pow(SHASH->iron[i][j][a]->get_x_position() - x, 2) + pow(SHASH->iron[i][j][a]->get_y_position() - y, 2));
								if(matka > tang){
									matka = tang;
									targetX = SHASH->iron[i][j][a]->get_x_position();
									targetY = SHASH->iron[i][j][a]->get_y_position();
									targetNUM = a;
								}
							}
						}
						if(matka != 10000){
							v.push_back(targetX);
							v.push_back(targetY);
							v.push_back(targetNUM);
							SHASH->iron[targetX/ENTHASH][targetY/ENTHASH][targetNUM]->set_free(false);
							return v;
						}
						break;
					}	
				}
			}
		}

	}
	return std::vector<int> (-1);
}

void Settler::move(std::vector<int> t, Map* m){
	int targetX = t[0];
	int targetY = t[1];
	//double matka = 10000;
	int x = this->x_pos;
	int y = this->y_pos;
	int dx;
	int dy;

	/*for(int i = x -1; i <= x +1; i++){
		for(int j = y -1; j <= y +1; j++){
			if(i >= 0 && j >= 0){//ei rajojen ulkopuolella
				if(m->at(i/DRAWSIZE,j/DRAWSIZE).type() != Tile::Type::WATER){
					double dis = sqrt(pow(targetX - x, 2) + pow(targetY - y, 2));
					if(matka > dis){
						matka = dis;
						nextX = i;
						nextY = j;		
					}
				}		
			}
		}
	}
*/
//int dx = targetX - x;//(targetX - x)/abs(targetX - x);
//int dy = targetY - y;//(targetY - y)/abs(targetY - y);
	if(targetX - x == 0){
	    dx = 0;
	}
	else{
	    dx = (int)((targetX - x)/abs(targetX - x));
	}
	if(targetY - y == 0){
	    dy = 0;
	}
	else{
	    dy = (int)((targetY - y)/abs(targetY - y));
	}

	this->x_pos += dx;//(int)(acos(dx)*STLSPEED);
	this->y_pos += dy;//(int)(asin(dx)*STLSPEED);
	if( m->at(this->x_pos / DRAWSIZE,this->y_pos/DRAWSIZE).z < 0 ){
        this->sprite.setTexture(ASSETHANDLER->SETTLERWTEX, true);
	}
	else{
        this->sprite.setTexture(ASSETHANDLER->SETTLERTEX, true);
	}

	this->sprite.setPosition( this->x_pos-ASSETHANDLER->SETTLERIMG.getSize().x/2, this->y_pos-ASSETHANDLER->SETTLERIMG.getSize().y );
}
