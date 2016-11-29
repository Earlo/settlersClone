#include <random>
#include <time.h>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "perlin/PerlinNoise.h"
#include "Tile.h"
#include "../../constants.h"


std::default_random_engine generator(time(NULL));
std::uniform_int_distribution<int> distribution(1000000,9999999);

class Map{
private:
	std::vector<std::vector<Tile>> terrain;
	sf::Image IMG;
	//TODO make some sense in the way w and h are defined
	//unsigned int _w;
	//unsigned int _h;
public:

	unsigned int w;
	unsigned int h;

	Map( unsigned int _w, unsigned int _h ){
		this->w = _w;
		this->h = _h;
		this->IMG.create (_w*, unsigned int height, const Color &color=Color(0, 0, 0))
	    std::cout << "doing a map of size " << _w << "," << _h << std::endl;
	    //init three noise functions with different seeds
		PerlinNoise pn0(distribution(generator));
		PerlinNoise pn1(distribution(generator));
		PerlinNoise pn2(distribution(generator));
		
		PerlinNoise pnm(distribution(generator));
		//noise for wood and ore
		PerlinNoise pnW0(distribution(generator));
		PerlinNoise pnW1(distribution(generator));

		PerlinNoise pnO(distribution(generator));

		double w0 = 80.0;
		double w1 = 30.0;
		double w2 = 10.0;
		//double wm = 40.0;

		double wC = 30.0;
		double tw = w0+w1+w2+wC;//+wm;
		for (unsigned int i = 0; i < _w; i++){
			terrain.push_back( std::vector<Tile>() );
			for (unsigned int j = 0; j < _h; j++){
				double x = (double)j/((double)w) - 0.5;
				double y = (double)i/((double)h) - 0.5;
				// Typical Perlin noise
				double k = 0;
				// 4 10 30
				k += (w0*(2*(pn0.noise(6  * x, 6  * y, x*y) - 0.5)));
				k += (w1*(2*(pn1.noise(12 * x, 12 * y, x*y) - 0.5)));
				k += (w2*(2*(pn2.noise(36 * x, 36 * y, x*y) - 0.5)));
				//double mountain = ( pnm.noise(20 * x, 20 * y, x*y) );
				//k += 2*wm*pow(mountain,3);
				k += wC*( 1 - ( std::max(0.1,(2*x)*(2*x)) +std::max(0.1,(2*y)*(2*y))));
				k = std::min((k/tw),1.0)*255;

				terrain[i].push_back( Tile(i,j,(int)k) );
			}
		}

		for (unsigned int i = 0; i < _w; i++){
			for (unsigned int j = 0; j < _h; j++){
				if (terrain[i][j].z >= 100){
						terrain[i][j].setType( Tile::Type::ROCK );
					}
				if (terrain[i][j].z >= 0){
				    std::vector<Tile> v = nextTo(i,j);
					for( unsigned int n = 0; n < v.size(); n++){
						if( v[n].type() == Tile::Type::WATER ){
							terrain[i][j].setType( Tile::Type::SAND );
						}
					}	
				}
			}
		}


		for (unsigned int i = 0; i < _w; i++){
			for (unsigned int j = 0; j < _h; j++){
				double x = (double)j/((double)w) - 0.5;
				double y = (double)i/((double)h) - 0.5;
				if ( terrain[i][j].type() == Tile::Type::ROCK ){
					if ( pnO.noise(8  * x, 8  * y, x*y) > 0.4){
						terrain[i][j].setType( Tile::Type::ORE );
					}
				}
				if ( terrain[i][j].type() == Tile::Type::DIRT ){
					double val = (pnW0.noise(10  * x, 8  * y, x*y) + pnW1.noise(8  * x, 10  * y, x*y))/2;
					if ( val  > 0.55){
						terrain[i][j].setType( Tile::Type::WOODS );
					}					
				}
			}
		}

	
		for (unsigned int i = 0; i < _w; i++){
			for (unsigned int j = 0; j < _h; j++){
				terrain[i][j].refreshShape();
			}
		}

	    std::cout << "done" << std::endl;
	};
	
	Tile at(int x, int y){
		return terrain[x][y];
	};



	std::vector<Tile> nextTo(int x, int y){
		std::vector<Tile> ret;
		for ( int a = -1; a <= 1; a++){
			for ( int b = -1; b <= 1; b++){
				if ( a != 0 || b != 0){
					if( ((a+x) > 0) && ((a+x) < (int)w) && ((b+y) > 0) && ((b+y) < (int)h)){
						ret.push_back(this->at(a+x,b+y));
					}
				}
			}
		}
		return ret;
	};

};