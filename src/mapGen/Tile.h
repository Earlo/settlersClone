//dunno if we should have all drawing stuff done in one place, but I am doing something here as a test anyway
#include <SFML/Graphics.hpp>
int DRAWSIZE = 8;
class Tile{
private:
	enum class Type { DIRT, WATER, SAND };
    Tile::Type _type;
	std::vector<int> coords;

public:

	sf::ConvexShape shape;

	static const int x;
	static const int y;
	static const int z;

	Tile( int x, int y, int z ){
		if (z < 0){
			_type = Tile::Type::WATER;
		}
		else{
		    _type = Tile::Type::DIRT;
		}

	    //TODO do in seperate func later, from here
		shape.setPointCount(4);

	    shape.setPoint(0, sf::Vector2f(DRAWSIZE*(x  ) ,DRAWSIZE*(y  )));
		shape.setPoint(1, sf::Vector2f(DRAWSIZE*(x-1)+1, DRAWSIZE*(y  )));
		shape.setPoint(2, sf::Vector2f(DRAWSIZE*(x-1)+1, DRAWSIZE*(y-1)+1));
		shape.setPoint(3, sf::Vector2f(DRAWSIZE*(x  ), DRAWSIZE*(y-1)+1));

		switch(_type){
			case Tile::Type::DIRT:
				shape.setFillColor (sf::Color(67-z/2,200-z,67-z/2));
				break;
			case Tile::Type::WATER:
				shape.setFillColor (sf::Color(67+z/2,67+z/2,200+z));
				break;
			default : //shouldn't go here
				shape.setFillColor (sf::Color::Red);
				break;
		}
		//to here
		coords = {x, y, z};
	};
	
	void refreshShape();

	std::vector<int> pos(){
		return coords;
	};

	Tile::Type type(){
		return _type;
	}



};


