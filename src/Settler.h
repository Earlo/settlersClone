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


    Settler(int x_position, int y_position )
        :Entity(x_position, y_position){

        this->task = Settler::TType::IDLE;
        this->updateImg();
	this->workclock = 0;
        }

    void updateImg(){
        this->sprite.setTexture(ASSETHANDLER.SETTLERTEX, true);
        this->sprite.setPosition( this->x_pos-ASSETHANDLER.SETTLERIMG.getSize().x/2, this->y_pos-ASSETHANDLER.SETTLERIMG.getSize().y );
    }

    /*void update(){
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
    }*/

	std::vector<int> nearest(SpatialHash* SHASH, Resource::RType t){
		int x = this->get_x_position()/ENTHASH;
		int y = this->get_y_position()/ENTHASH;
		int targetX;
		int targetY;
		int targetNUM;
		

		double matka = 10000;
		bool done = false;
		std::vector<int> v;
		for(int dis = 0;dis < HASHX; dis++){
			for(int i = x - dis; i <= (x + dis); i++){
				for(int j = y - dis; j <= (y + dis); j++){
					if( i >= 0 && j >= 0 && i <= HASHX -1 && j <= HASHY -1){
					switch (t) {
						case Resource::RType::TREE:
						for(unsigned int a = 0; a < SHASH->trees[i][j].size(); a++){
							if(SHASH->trees[i][j][a]->is_free()){
								double tang  = sqrt(pow(SHASH->trees[i][j][a]->get_x_position() - x, 2) + pow(SHASH->trees[i][j][a]->get_y_position() - y, 2));
								if(matka > tang){
									matka = tang;
									targetX = SHASH->trees[i][j][a]->get_x_position();
									targetY = SHASH->trees[i][j][a]->get_y_position();
									targetNUM = a;
									done = true;
								}
							}
						}
						if(done){
							v.push_back(targetX);
							v.push_back(targetY);
							v.push_back(targetNUM);
							SHASH->trees[targetX/ENTHASH][targetY/ENTHASH][targetNUM]->set_free(false);
							std::cout<< SHASH->trees[targetX/ENTHASH][targetY/ENTHASH][targetNUM]->is_free()<<std::endl;
							return v;
						}
						break;
						case Resource::RType::STONE:
							for(unsigned int a = 0; a < SHASH->stone[i][j].size(); a++){
								if(SHASH->stone[i][j][a]->is_free()){
									double tang  = sqrt(pow(SHASH->stone[i][j][a]->get_x_position() - x, 2) + pow(SHASH->stone[i][j][a]->get_y_position() - y, 2));
									if(matka > tang){
										matka = tang;
										targetX = SHASH->stone[i][j][a]->get_x_position();
										targetY = SHASH->stone[i][j][a]->get_y_position();
										targetNUM = a;
									}
								}
							}
							if(matka != 10000){
								v.push_back(targetX);
								v.push_back(targetY);
								v.push_back(targetNUM);
								SHASH->stone[targetX/ENTHASH][targetY/ENTHASH][targetNUM]->set_free(false);
								return v;
							}
							break;
						case Resource::RType::IRON:
							for(unsigned int a = 0; a < SHASH->iron[i][j].size(); a++){
								if(SHASH->iron[i][j][a]->is_free()){
									double tang  = sqrt(pow(SHASH->iron[i][j][a]->get_x_position() - x, 2) + pow(SHASH->iron[i][j][a]->get_y_position() - y, 2));
									if(matka > tang){
										matka = tang;
										targetX = SHASH->iron[i][j][a]->get_x_position();
										targetY = SHASH->iron[i][j][a]->get_y_position();
										targetNUM = a;
									}
								}
							}
							if(matka != 10000){
								v.push_back(targetX);
								v.push_back(targetY);
								v.push_back(targetNUM);
								SHASH->iron[targetX/ENTHASH][targetY/ENTHASH][targetNUM]->set_free(false);
								return v;
							}
							break;
						}	
					}
				}
			}

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

		this->x_pos += dx;//(int)(acos(dx)*STLSPEED);
		this->y_pos += dy;//(int)(asin(dx)*STLSPEED);
		this->sprite.setPosition( this->x_pos-ASSETHANDLER.SETTLERIMG.getSize().x/2, this->y_pos-ASSETHANDLER.SETTLERIMG.getSize().y );
	}
	
    bool has_weapon() const;
    Item get_inventory() const;

    void set_task(Settler::TType t){task = t;}
    void build( const Building b);
    void occupy(const Building b);
    void defend(const Building b);
    void gather();
    void idle();

    void move(int x, int y);
    void draw();
	Settler::TType get_task(){return task;}
	void set_nearest(std::vector<int> v){near = v;}
	std::vector<int> get_nearest(){return near;}
	int get_near_x(){return near[0];}
	int get_near_y(){return near[1];}
	int get_near_a(){return near[2];}
	int get_workclock(){return workclock;}
	void set_workclock(int time){workclock += time;}
	int workPhase;
private:
    //Game game;
    bool armed;
    int workclock;
    Item inventory;
    Settler::TType task;
    std::vector<int> near;
    //Resource Nearest;
    std::vector<Resource> target;

};

#endif

