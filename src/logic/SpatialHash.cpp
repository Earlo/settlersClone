#include "SpatialHash.h"

SpatialHash::SpatialHash( ){
	for (unsigned int i = 0; i < HASHX; i++){
		trees.push_back( std::vector<std::vector<Resource*>>() );
		stone.push_back( std::vector<std::vector<Resource*>>() );
		iron.push_back( std::vector<std::vector<Resource*>>() );
		WEIGHT.push_back( std::vector<double>() );
		for (unsigned int j = 0; j < HASHY; j++){
			trees[i].push_back( std::vector<Resource*>() );
			stone[i].push_back( std::vector<Resource*>() );
			iron[i].push_back( std::vector<Resource*>() );
			WEIGHT[i].push_back( -1.f );
		}
	}
}

void SpatialHash::initHash( Map *m ){
	std::cout<<"happennen"<<std::endl;
	for (unsigned int i = 0; i < HASHX; i++){
		for (unsigned int j = 0; j < HASHY; j++){
			int bx = i*HASHRES;
			int by = j*HASHRES;
			int watercount = 0;
			for (unsigned int x = 0; x < HASHRES; x++){
				for (unsigned int y = 0; y < HASHRES; y++){
					switch(	m->at(bx+x,by+y).type() ){
						case Tile::Type::WATER:
							watercount+=1;
							break;
						default : 
							break;
					}
				}
			}
			//THIS IS SO FUCKING STUPID 
			//but there isn't time to make anything proper here
			//fuck this course :D

			//WEIGHT[i][j] = BASECOST + (MAXCOST-BASECOST) * ( (double)watercount / ((double)HASHRES*HASHRES) );
            
            //std::cout << i << ","<< i << " -> " << WEIGHT[i][j] <<std::endl;

			if (watercount < HASHRES){
				WEIGHT[i][j] = BASECOST;
			}
			else{
				WEIGHT[i][j] = BASECOST + (MAXCOST-BASECOST) * ( (double)watercount / ((double)HASHRES*HASHRES) );
			}
		}
	}
	/*
	for (unsigned int i = 0; i < HASHX; i++){
		for (unsigned int j = 0; j < HASHY; j++){
			if (WEIGHT[i][j] != 1;){
				//actually do something sensible here
			}
		}
	}
	*/
	for(unsigned int i = 0; i < m->resot.size(); i++){
		//std::cout << m->resot[i]->get_x_position()/ENTHASH<<"    "<< m->resot[i]->get_y_position()/ENTHASH <<"    "<< i << "    "<< m->resot.size()<< "     " << m->resot.size() << std::endl;
		switch (m->resot[i]->get_resource_type()) {
			case Resource::RType::TREE:
				trees[floor(m->resot[i]->get_x_position()/ENTHASH)][floor(m->resot[i]->get_y_position()/ENTHASH)].push_back(m->resot[i]);
				break;
			case Resource::RType::STONE:
				stone[floor(m->resot[i]->get_x_position()/ENTHASH)][floor(m->resot[i]->get_y_position()/ENTHASH)].push_back(m->resot[i]);
				break;
			case Resource::RType::IRON:
				iron[floor(m->resot[i]->get_x_position()/ENTHASH)][floor(m->resot[i]->get_y_position()/ENTHASH)].push_back(
					m->resot[i]);
				break;

		}
	}
	//std::cout << "END" << std::endl;

}
