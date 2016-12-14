
#pragma once
#include "Settler.hpp"
#include <vector>
#include <algorithm>


	Settler::Settler(Game g) {
		game = g;
	}

	int Settler::get_x_position() const {
		return x_pos;
	}

	int Settler::get_y_position() const {
		return y_pos;
	}

	bool Settler::has_weapon() const {
		return armed;
	}

	Item Settler::get_inventory() const {
		return inventory;
	}

	void Settler::get_task() const{
		return current_task;
	}

	void Settler::set_task(const Task t) {
		current_task = t;
	}

