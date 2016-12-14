#ifndef SETTLER
#define SETTLER

#include "Item.h"
#include "Resource.h"
#include "Building.h"
//#include "Game.h"
//#include "logic/SpatialHash.h"
#include "math.h"
//#include "logic/SpatialHash.h"

#include "../constants.h"
//#include "Entity.h"
//#include "../assets.h"

//#include "logic/Task.h"

//forward declaration
//class Building;
//class Resource;

class Settler : public Entity {
public:
    //Settler(Game g);

    enum class TType { BUILD, GATHERW, GATHERS, GATHERI, IDLE };

    Settler::TType current_task;

    Settler(int x_position, int y_position )
        :Entity(x_position, y_position){

        //Task current_task(Settler::TType::IDLE);
        //Task t(Task::TType::IDLE);
        this->current_task = Settler::TType::IDLE;
        this->updateImg();
        }

    void updateImg(){
        this->sprite.setTexture(ASSETHANDLER.SETTLERTEX, true);
        this->sprite.setPosition( this->x_pos-ASSETHANDLER.SETTLERIMG.getSize().x/2, this->y_pos-ASSETHANDLER.SETTLERIMG.getSize().y );
    }

    void update(){
        switch (this->current_task) {
        case Settler::TType::GATHERW:
            if (this->target.size() == 0){
                break;
            }
            else{
                //this->gather();
                break;
            }
            break;
        case Settler::TType::GATHERS:
            break;
        case Settler::TType::GATHERI:
            break;
	case Settler::TType::BUILD:
	    break;
	case Settler::TType::IDLE:
	    break;
        }
    }

	std::vector<int> nearest(SpatialHash SHASH, Resource::RType t){
		int x = this->get_x_position()/ENTHASH;
		int y = this->get_y_position()/ENTHASH;
		int targetX;
		int targetY;
		int targetNUM;
		double matka = 10000;
		std::vector<int> v;

		switch (t) {
		case Resource::RType::TREE:
			for(int dis = 0;dis < HASHX; dis++){
				for(int i = x - dis; i <= (x + dis); i++){
					for(int j = y - dis; j <= (y + dis); j++){
						if((x-dis) >= 0 && (y-dis) >= 0 && (x+dis) <= HASHX -1 && (y+dis) <= HASHY -1){
							for(unsigned int a = 0; a < SHASH.trees[i][j].size(); a++){
								double tang  = sqrt(pow(SHASH.trees[i][j][a].get_x_position() - x, 2) + pow(SHASH.trees[i][j][a].get_y_position() - y, 2));
								if(matka > tang){
									matka = tang;
									targetX = SHASH.trees[i][j][a].get_x_position();
									
									targetY = SHASH.trees[i][j][a].get_y_position();
									targetNUM = a;
								}
							}
						}	
					}
				}
				if(matka != 10000){
					v.push_back(targetX);
					v.push_back(targetY);
					v.push_back(targetNUM);
					return v;
				}
			}
			break;

		case Resource::RType::STONE:
			for(int dis = 0;dis < HASHX; dis++){
				for(int i = x - dis; i <= (x + dis); i++){
					for(int j = y - dis; j <= (y + dis); j++){
						if((x-dis) >= 0 && (y-dis) >= 0 && (x+dis) <= HASHX -1 && (y+dis) <= HASHY -1){
							for(unsigned int a = 0; a < SHASH.stone[i][j].size(); a++){
								double tang  = sqrt(pow(SHASH.stone[i][j][a].get_x_position() - x, 2) + pow(SHASH.stone[i][j][a].get_y_position() - y, 2));
								if(matka > tang){
									matka = tang;
									targetX = SHASH.stone[i][j][a].get_x_position();
									targetY = SHASH.stone[i][j][a].get_y_position();
									targetNUM = a;
								}
							}
						}	
					}
				}
				if(matka != 10000){
					v.push_back(targetX);
					v.push_back(targetY);
					v.push_back(targetNUM);
					return v;
				}
			}
			break;
		case Resource::RType::IRON:
			for(int dis = 0;dis < HASHX; dis++){
				for(int i = x - dis; i <= (x + dis); i++){
					for(int j = y - dis; j <= (y + dis); j++){
						if((x-dis) >= 0 && (y-dis) >= 0 && (x+dis) <= HASHX -1 && (y+dis) <= HASHY -1){
							for(unsigned int a = 0; a < SHASH.iron[i][j].size(); a++){
								double tang  = sqrt(pow(SHASH.iron[i][j][a].get_x_position() - x, 2) + pow(SHASH.iron[i][j][a].get_y_position() - y, 2));
								if(matka > tang){
									matka = tang;
									targetX = SHASH.iron[i][j][a].get_x_position();
									targetY = SHASH.iron[i][j][a].get_y_position();
									targetNUM = a;
								}
							}
						}	
					}
				}
				if(matka != 10000){
					v.push_back(targetX);
					v.push_back(targetY);
					v.push_back(targetNUM);
					return v;
				}
			}
			break;
		}
		return std::vector<int> (-1);
	}
	
	void move(std::vector<int> t){
		int targetX = t[0];
		int targetY = t[1];
		//double matka = 10000;
		int x = this->x_pos;
		int y = this->y_pos;
		int dx;
		int dy;

		/*for(int i = x -1; i <= x +1; i++){
			for(int j = y -1; j <= y +1; j++){
				if(i >= 0 && j >= 0){//ei rajojen ulkopuolella
					if(m->at(i/DRAWSIZE,j/DRAWSIZE).type() != Tile::Type::WATER){
						double dis = sqrt(pow(targetX - x, 2) + pow(targetY - y, 2));
						if(matka > dis){
							matka = dis;
							nextX = i;
							nextY = j;		
						}
					}		
				}
			}
		}
        */
        //int dx = targetX - x;//(targetX - x)/abs(targetX - x);
        //int dy = targetY - y;//(targetY - y)/abs(targetY - y);
        if(targetX - x == 0){
            dx = 0;
        }
        else{
            dx = (int)((targetX - x)/abs(targetX - x));
        }
        if(targetY - y == 0){
            dy = 0;
        }
        else{
            dy = (int)((targetY - y)/abs(targetY - y));
        }

		std::cout<< "nykyinen: "<< x << "  " << y<<std::endl;
		this->x_pos += dx;//(int)(acos(dx)*STLSPEED);
		this->y_pos += dy;//(int)(asin(dx)*STLSPEED);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.SETTLERIMG.getSize().x/2, this->y_pos-ASSETHANDLER.SETTLERIMG.getSize().y );
	}
	
    bool has_weapon() const;
    Item get_inventory() const;

    void set_task(const Settler::TType t);
    void build( const Building b);
    void occupy(const Building b);
    void defend(const Building b);
    void gather();
    void idle();

    void move(int x, int y);
    void draw();

private:
    //Game game;
    bool armed;
    Item inventory;
    //Resource Nearest;
    std::vector<Resource> target;

};

#endif

