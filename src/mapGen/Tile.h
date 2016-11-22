//dunno if we should have all drawing stuff done in one place, but I am doing something here as a test anyway
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
		//this->z = 200;
		//std::cout<<"set";							
		//std::cout<<"set "<<this->x<<","<<this->y<<","<<this->z<<";"<<std::endl;

	};
	void refreshShape();
private:
    Tile::Type _type;
	std::vector<int> coords;

};




