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
	Item Settler::get_inventory const {
		return inventory;
	}
	void Settler::get_task const{
		return current_task;
	}
	void Settler::set_task(const Task t);
	void Settler::collect(Resource r);
	void Settler::occupy();
	void Settler::idle();
	
};