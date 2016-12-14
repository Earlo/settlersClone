#ifndef MAP
#define MAP


#include <random>
#include <time.h>
#include <math.h>

#include <SFML/Graphics.hpp>
//#include <SFML/Image.hpp>

#include "perlin/PerlinNoise.h"
#include "Tile.h"

#include "../Resource.h"
#include "../Game.h"

#include "../../constants.h"

std::default_random_engine generator(time(NULL));
std::uniform_int_distribution<int> distribution(1000000,9999999);
std::uniform_real_distribution<double> chance(0,1.f);

class Map{
private:
	std::vector<std::vector<Tile>> terrain;
	sf::Image IMG;
	sf::Image PASSABLE;
	sf::Texture TEXTURE;



	//TODO make some sense in the way w and h are defined
	//unsigned int _w;
	//unsigned int _h;
public:


    //TODO make some more sensible way to store g->entities drawn on screen
    //std::vector<Entity*> stuff;
    std::vector<Resource*> resot;
	
	sf::Sprite sprite;
	unsigned int w;
	unsigned int h;

	Map( unsigned int _w, unsigned int _h, Game* g);
	
	Tile at(int x, int y);

	std::vector<Tile> nextTo(int x, int y);
	void updateImg();

};

#endif
