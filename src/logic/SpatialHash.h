#ifndef SHASH
#define SHAHS

#include "../../constants.h"

#include "../Tree.h"
#include "../Stone.h"
#include "../Iron.h"

#include "../mapGen/Map.h"

//#include ""
class SpatialHash{
private:

	
public:
	//north south east west
	//enum class DIR { N, S, E, W };

	std::vector<std::vector<double>> WEIGHT;

	//actually makes sense to have seperate hash for each, since looking for trees or stone is completely different task
    std::vector<std::vector<std::vector<Tree>>> trees;
    std::vector<std::vector<std::vector<Stone>>> stone;
    std::vector<std::vector<std::vector<Iron>>> iron;

	SpatialHash( ){
		for (unsigned int i = 0; i < HASHX; i++){
			trees.push_back( std::vector<std::vector<Tree>>() );
			stone.push_back( std::vector<std::vector<Stone>>() );
			iron.push_back( std::vector<std::vector<Iron>>() );
			WEIGHT.push_back( std::vector<double>() );
			for (unsigned int j = 0; j < HASHY; j++){
				trees[i].push_back( std::vector<Tree>() );
				stone[i].push_back( std::vector<Stone>() );
				iron[i].push_back( std::vector<Iron>() );
				WEIGHT[i].push_back( -1.f );
			}
		}
	}

	void initHash( Map m ){
		std::cout<<"happennen"<<std::endl;
		for (unsigned int i = 0; i < HASHX; i++){
			for (unsigned int j = 0; j < HASHY; j++){
				int bx = i*HASHRES;
				int by = j*HASHRES;
				int watercount = 0;
				for (unsigned int x = 0; x < HASHRES; x++){
					for (unsigned int y = 0; y < HASHRES; y++){
						switch(	m.at(bx+x,by+y).type() ){
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
	}
};

SpatialHash SHASH;


#endif


