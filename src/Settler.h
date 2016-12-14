#ifndef SETTLER
#define SETTLER

#include "Item.h"
#include "Resource.h"
#include "Building.h"
#include "math.h"
//#include "logic/SpatialHash.h"


//#include "Entity.h"
//#include "../assets.h"

//#include "logic/Task.h"

//forward declaration
//class Building;
//class Resource;

class Settler : public Entity {
public:

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
    
    bool armed;
    Item inventory;
    //Resource Nearest;
    std::vector<Resource> target;

};

#endif

