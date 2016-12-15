#ifndef MAP
#define MAP

#include <random>
#include <time.h>
#include <math.h>

#include <SFML/Graphics.hpp>

#include "../../constants.h"
#include "../../assets.h"
#include "../Resource.h"
#include "../Game.h"
#include "Tile.h"
#include "perlin/PerlinNoise.h"

/*
using std::default_random_engine; 
using std::uniform_int_distribution;
using std::uniform_real_distribution;
*/
/*
extern std::default_random_engine 	generator(time(NULL));
extern std::uniform_int_distribution<int> distribution(1000000,9999999);
extern std::uniform_real_distribution<double> chance(0,1.f);
*/
extern std::default_random_engine generator;
extern std::uniform_int_distribution<int> distribution;
extern std::uniform_real_distribution<double> chance;

class Map{

public:
    std::vector<Resource*> resot;	
	sf::Sprite sprite;

	Map( Game* g, AssetHandler* ASSETHANDLER);
	
	Tile at(int x, int y);

	std::vector<Tile> nextTo(int x, int y);
	void updateImg();

private:
	std::vector<std::vector<Tile>> terrain;
	sf::Image IMG;
	sf::Image PASSABLE;
	sf::Texture TEXTURE;

};

#endif
