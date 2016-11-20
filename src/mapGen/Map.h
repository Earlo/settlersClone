#include <random>
#include <time.h>
#include "Tile.h"

#include "perlin/PerlinNoise.h"


std::default_random_engine generator(time(NULL));
std::uniform_int_distribution<int> distribution(1000000,9999999);

class Map{
private:
	std::vector<std::vector<Tile>> terrain;
	//TODO make some sense in the way w and h are defined
	//unsigned int _w;
	//unsigned int _h;
public:

	unsigned int w;
	unsigned int h;

	//static const unsigned int w;
	//static const unsigned int h;

	Map( unsigned int _w, unsigned int _h ){

		w = _w;
		h = _h;



	    std::cout << "doing a map of size " << _w << "," << _h << std::endl;
    	unsigned int seed = distribution(generator);
		PerlinNoise pn(seed);

		for (unsigned int i = 0; i < _w; i++){
			terrain.push_back( std::vector<Tile>() );
			for (unsigned int j = 0; j < _h; j++){

				double x = (double)j/((double)w);
				double y = (double)i/((double)h);
				// Typical Perlin noise
				int k = (int)(255*pn.noise(5 * x*y, 5 * y*x, x*0.8))-127;

				terrain[i].push_back( Tile(i,j,k) );
			}
		}
	    std::cout << "done" << std::endl;

	};
	Tile at(int x, int y){
		return terrain[x][y];
	};

};