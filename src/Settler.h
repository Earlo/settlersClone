#ifndef SETTLER
#define SETTLER

#include "Item.h"
#include "Resource.h"
//#include "logic/Task.h"

//forward declaration
//class Building;

class Settler : public Entity {
public:

    enum class TType { BUILD, GATHERW, GATHERS, GATHERI, IDLE };

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
            if ()
            this->gather()
            break;
        case Settler::TType::GATHERS:
            break;
        case Settler::TType::GATHERI:
            break;
        }

    }

    bool has_weapon() const;
    Item get_inventory() const;

    void set_task(const Settler::TType t);
    void build( const Building b);
    void occupy(const Building b);
    void defend(const Building b);
    void gather(const Resource r);
    void idle();

    void move(int x, int y);
    void draw();

    Settler::TType current_task;

private:
    
    bool armed;
    Item inventory;
    Resource Nearest;

};

#endif

