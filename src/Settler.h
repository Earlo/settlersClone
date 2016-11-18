#pragma once
class Settler {

public:
	Settler() : {}
	int get_x_position const;
	int get_y_position const;
	Item get_inventory const;
	void set_task(const Task t);
	void collect(Resource r);
	void occupy();
	void idle();
	
protected:
	int x_pos;
	int y_pos;
	Task current_task;
	Item inventory;
	
};