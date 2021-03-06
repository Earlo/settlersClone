#ifndef TILE
#define TILE


#include <SFML/Graphics.hpp>

class Tile{

public:

	sf::ConvexShape shape;

	enum class Type { DIRT, WOODS, WATER, SAND, ROCK, ORE };

	int x;
	int y;
	int z;

	Tile( int _x, int _y, int _z ){
		this->x = _x;
		this->y = _y;
		this->z = _z;
		if (this->z < 0){
			_type = Tile::Type::WATER;
		}
		else{
		    _type = Tile::Type::DIRT;
		}
		coords = {this->x, this->y, this->z};
	};
	std::vector<int> pos(){
		return coords;
	};
	Tile::Type type(){
		return _type;
	};
	void setType( Tile::Type t ){
		_type = t;
	};
	void refreshShape();
private:
    Tile::Type _type;
	std::vector<int> coords;

};

#endif



