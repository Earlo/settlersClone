#pragma once

class Settler {

public:
	Settler() : {}
	int get_x_position const;
	int get_y_position const;
	Item get_inventory const;
	void defend();
	void attack(Building b);
	void attack(Settler s);
	bool has_weapon() const;
	void set_task(const Task t);
	void collect(Resource r);
	void occupy();
	void idle();

protected:
	int x_pos;
	int y_pos;
	bool armed;
	Task current_task;
	Item inventory;

};
