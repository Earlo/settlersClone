#include "Tile.h"

class Map{
private:
	std::vector<std::vector<Tile>> terrain;
public:
	Map( unsigned int x, unsigned int y ){
	    std::cout << "doing a map of size " << x << "," << y << std::endl;

		for (unsigned int i = 0; i < x; i++){
			terrain.push_back( std::vector<Tile>() );
			for (unsigned int j = 0; j < y; j++){
				terrain[i].push_back( Tile(i,j,0) );
			}
		}
	    std::cout << "done" << std::endl;

	};
	Tile at(int x, int y){
		return terrain[x][y];
	};
};