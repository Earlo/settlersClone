#ifndef SHASH_H
#define SHAHS_H
#include <iostream>
#include <math.h>

#include "../../constants.h"
#include "../Resource.h"
#include "../mapGen/Map.h"


//#include ""
class SpatialHash{
private:

	
public:
	//north south east west
	//enum class DIR { N, S, E, W };

	std::vector<std::vector<double>> WEIGHT;

	//actually makes sense to have seperate hash for each, since looking for trees or stone is completely different task
    std::vector<std::vector<std::vector<Resource*>>> trees;
    std::vector<std::vector<std::vector<Resource*>>> stone;
    std::vector<std::vector<std::vector<Resource*>>> iron;

	SpatialHash( );

	void initHash( Map *m );
};

#endif


