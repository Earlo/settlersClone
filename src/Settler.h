#pragma once

class Settler {

public:
	Settler() : {}
	
	int get_x_position const;
	int get_y_position const;
	bool has_weapon() const;
	Item get_inventory const;
	Task get_task() const;
	void set_task(const Task t);

	void occupy(const Building b);
	void defend(const Building b);
	void attack(const Building b);
	void attack(const Settler s);
	void gather(const Item i);
	void idle();

private:
	int x_pos;
	int y_pos;
	bool armed;
	Task current_task;
	Item inventory;
};
