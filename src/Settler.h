#ifndef SETTLER
#define SETTLER


#include <math.h>

#include "Item.h"
#include "Resource.h"
#include "Building.h"

#include "mapGen/Map.h"

//#include "Game.h"
//#include "logic/SpatialHash.h"
//#include "logic/SpatialHash.h"

#include "../constants.h"
//#include "Entity.h"
//#include "../assets.h"

//#include "logic/Task.h"

//forward declaration
class SpatialHash;
//class Building;
//class Resource;

class Settler : public Entity {
public:
    //Settler(Game g);

    enum class TType { BUILD, GATHERW, GATHERS, GATHERI, IDLE };


    Settler(int x_position, int y_position, AssetHandler* ASSETHANDLER);

    void updateImg();
    std::vector<int> nearest(SpatialHash* SHASH, Resource::RType t);

    void move(std::vector<int> t, Map* m);
	
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

