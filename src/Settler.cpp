#pragma once
#include "Settler.h"

class Settler {
	Settler::Settler() {}

	int Settler::get_x_position const {
		return x:pos;
	}
	int Settler::get_y_position const {
		return y_pos;
	}
	bool Settler::has_weapon() const {
		return armed;
	}
	Item Settler::get_inventory const {
		return inventory;
	}
	void Settler::get_task const{
		return current_task;
	}

	void Settler::set_task(const Task t) {
		current_task = t;
	}
	void Settler::occupy(const Building b);
	void Settler::defend(const Building b);
	void Settler::attack(const Building b);
	void Settler::attack(const Settler s);
	void Settler::gather(const Item i);
	void Settler::idle();
	
};
