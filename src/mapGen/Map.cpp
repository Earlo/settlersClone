#include "Map.h"
#include <iostream>



std::default_random_engine generator = std::default_random_engine(time(NULL));
std::uniform_int_distribution<int> distribution = std::uniform_int_distribution<int>(1000000,9999999);
std::uniform_real_distribution<double> chance = std::uniform_real_distribution<double>(0,1.f);

Map::Map( Game* g, AssetHandler* ASSETHANDLER){
	this->IMG.create( WORLDX, WORLDY);

    std::cout << "doing a map of size " << WORLDX << "," << WORLDY << std::endl;
    //init three noise functions with different seeds
	PerlinNoise pn0(distribution(generator));
	PerlinNoise pn1(distribution(generator));
	PerlinNoise pn2(distribution(generator));
	
	PerlinNoise pnm(distribution(generator));
	
	//noise for wood and ore
	PerlinNoise pnW0(distribution(generator));
	PerlinNoise pnW1(distribution(generator));

	PerlinNoise pnO0(distribution(generator));

	double w0 = 60.0;
	double w1 = 30.0;
	double w2 = 15.0;

	double wm = 40.0;

	double wC = 30.0;
	double tw = w0+w1+w2+wC;//+wm;
	for (unsigned int i = 0; i < WORLDX; i++){
		terrain.push_back( std::vector<Tile>() );
		for (unsigned int j = 0; j < WORLDY; j++){
			double x = (double)j/((double)WORLDX) - 0.5;
			double y = (double)i/((double)WORLDY) - 0.5;
			// Typical Perlin noise
			double k = -10;
			// 4 10 30
			k += (w0*(2*(pn0.noise(6  * x, 6  * y, x*y) - 0.5)));
			k += (w1*(2*(pn1.noise(12 * x, 12 * y, x*y) - 0.5)));
			k += (w2*(2*(pn2.noise(36 * x, 36 * y, x*y) - 0.5)));
			double mountain = ( pnm.noise(20 * x, 20 * y, x*y) );
			k += 2*wm*pow(mountain,3);
			k += wC*( 1 - ( std::max(0.1,(2*x)*(2*x)) +std::max(0.1,(2*y)*(2*y))));
			k = std::min((k/tw),1.0)*255;

			terrain[i].push_back( Tile(i,j,(int)k) );
		}
	}

	for (unsigned int i = 0; i < WORLDX; i++){
		for (unsigned int j = 0; j < WORLDY; j++){
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


	for (unsigned int i = 0; i < WORLDX; i++){
		for (unsigned int j = 0; j < WORLDY; j++){
			double x = (double)j/((double)WORLDX) - 0.5;
			double y = (double)i/((double)WORLDY) - 0.5;


			if ( terrain[i][j].type() == Tile::Type::ROCK ){
				//int hval = ((terrain[i][j].z-100)/512.f);
				if (chance(generator) > 0.985){
					if (pnO0.noise(8  * x, 8  * y, x*y) > .50){
						Resource* reso = new Resource(i*DRAWSIZE,j*DRAWSIZE, Resource::RType::IRON, ASSETHANDLER);
						g->entities.push_back( reso  );
						resot.push_back( reso );
						//std::cout<<"at map "<<reso.get_x_position()<<","<<reso.get_y_position()<<std::endl;

					}
					else {
						Resource* reso = new Resource(i*DRAWSIZE,j*DRAWSIZE, Resource::RType::STONE, ASSETHANDLER);
					    g->entities.push_back( reso );
					    resot.push_back( reso );
					}
				}
			}
			else if ( terrain[i][j].type() == Tile::Type::DIRT ){
				double val = (pnW0.noise(10  * x, 8  * y, x*y) + pnW1.noise(8  * x, 10  * y, x*y))/2;
				if (val > .55){
					terrain[i][j].setType( Tile::Type::WOODS );
					if ( val > .55 + chance(generator) ) {
						Resource* reso = new Resource(i*DRAWSIZE,j*DRAWSIZE, Resource::RType::TREE, ASSETHANDLER);
						g->entities.push_back( reso );
						resot.push_back( reso );
					}					
				}
			}
		}
	}

	for (unsigned int i = 0; i < WORLDX; i++){
		for (unsigned int j = 0; j < WORLDY; j++){
			terrain[i][j].refreshShape();
		}
	}
	this->updateImg();
    /*
    for(unsigned int i = 0; i < g->entities.size(); i++){ // Draw the entities from buildings vector
        std::cout<<"at G.e "<<g->entities[i]->get_x_position()<<","<<g->entities[i]->get_y_position()<<std::endl;
        std::cout<<"at R-> "<<resot[i]->get_x_position()<<","<<resot[i]->get_y_position()<<std::endl;
}   
	*/
	//std::cout<<"at MAP "<<g->entities[15]->get_x_position()<<","<<g->entities[15]->get_y_position()<<std::endl;
    std::cout << "done" << std::endl;
}
Tile Map::at(int x, int y){
	return terrain[x][y];
}

std::vector<Tile> Map::nextTo(int x, int y){
	std::vector<Tile> ret;
	for ( int a = -1; a <= 1; a++){
		for ( int b = -1; b <= 1; b++){
			if ( a != 0 || b != 0){
				if( ((a+x) > 0) && ((a+x) < (int)WORLDX) && ((b+y) > 0) && ((b+y) < (int)WORLDY)){
					ret.push_back(this->at(a+x,b+y));
				}
			}
		}
	}
	return ret;
}

void Map::updateImg(){
	for (unsigned int i = 0; i < WORLDX; i++){
		for (unsigned int j = 0; j < WORLDY; j++){
        this->IMG.setPixel(i, j, this->at(i,j).shape.getFillColor());
    }
}
this->TEXTURE.loadFromImage(this->IMG);
this->TEXTURE.setSmooth(true);
	this->sprite.setTexture(this->TEXTURE, true);
	this->sprite.setScale( DRAWSIZE, DRAWSIZE);
}
