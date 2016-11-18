class Tile{
private:
	static const int x;
	static const int y;
	static const int z;
	std::vector<int> coords;
public:
	Tile( int x, int y, int z ){
		x = x;
		y = y;
		z = z;
		coords = {x, y, z};
	};
	std::vector<int> pos(){
		return coords;
	};
};