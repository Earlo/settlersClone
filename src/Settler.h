#ifndef Settler
#define Settler

#include <stdio.h>
#include "Item.h"
#include "Building.h"
#include "Task.h"

class Settler {

public:
    Settler(Game g);

    ~Settler();

    int get_x_position() const;
    int get_y_position() const;
    bool has_weapon() const;
    Item get_inventory() const;
    Task get_task() const;

    void set_task(const Task t);
    void build(const Building b);
    void occupy(const Building b);
    void defend(const Building b);
    void gather(const Item i);
    void idle();

    void move(int x, int y);
    void draw();

private:
    
    int x_pos;
    int y_pos;
    bool armed;
    Task current_task;
    Item inventory;
};


#endif /* Settler_hpp */
