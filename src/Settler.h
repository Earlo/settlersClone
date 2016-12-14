#ifndef SETTLER
#define SETTLER

#include "Item.h"
#include "Building.h"
#include "Task.h"
#include "Game.h"
#include "logic/SpatialHash.h"

//forward declaration
//class Building;

class Settler : public Entity {
public:
    Settler(Game g);

        this->updateImg();
        }

    void updateImg(){
        this->sprite.setTexture(ASSETHANDLER.SETTLERTEX, true);
        this->sprite.setPosition( this->x_pos-ASSETHANDLER.SETTLERIMG.getSize().x/2, this->y_pos-ASSETHANDLER.SETTLERIMG.getSize().y );
    }


    bool has_weapon() const;
    Item get_inventory() const;
    Task get_task() const;

    void set_task(const Task t);
    void build( const Building b);
    void occupy(const Building b);
    void defend(const Building b);
    void gather(const Item i);
    void idle();

    void move(int x, int y);
    void draw();

private:
    Game game;
    int x_pos;
    int y_pos;
    bool armed;
    Task current_task;
    Item inventory;

};

#endif

