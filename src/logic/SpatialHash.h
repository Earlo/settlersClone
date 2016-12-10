#include "../../constants.h"

class SpatialHash{
private:
	std::vector<std::vector<Tile>> terrain;



	//TODO make some sense in the way w and h are defined
	//unsigned int _w;
	//unsigned int _h;
public:


    //TODO make some more sensible way to store stuff drawn on screen
    std::vector<Building> stuff;


	unsigned int w;
	unsigned int h;

	SpatialHash( unsigned int _w, unsigned int _h ){
		this->w = _w;
		this->h = _h;
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

	void updateImg(){
		for (unsigned int i = 0; i < this->w; i++){
			for (unsigned int j = 0; j < this->h; j++){
                this->IMG.setPixel(i, j, this->at(i,j).shape.getFillColor());
            }
        }
        this->TEXTURE.loadFromImage(this->IMG);
        this->TEXTURE.setSmooth(true);
		this->sprite.setTexture(this->TEXTURE, true);
		this->sprite.setScale( DRAWSIZE, DRAWSIZE);
	}

};
