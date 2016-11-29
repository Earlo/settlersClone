#pragma once
#include "Settler.hpp	"

	Settler::Settler() {}

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
	void Settler::build(const Building b {
		//Check required resources
		//Get resource from nearest warehouse
		//Carry to building
		//Repeat until resources run out or building is done
	}
	void Settler::occupy(const Building b) {
		//Move settler to Building
		//Add settler to inhabitant list
		//Remove settler from map
	}
	void Settler::defend(const Building b) {
		//Get weapon if not armed
		//Go to building
		//Add settler to defenders
		//Remove settler from map
	}
	void Settler::gather(const Item i) {
		//If weapon, go to nearest weaponsmith with stock and get one
		//Else find nearest resource; mine and carry it to the nearest warehouse
		//Repeat
	}
	void Settler::idle() {
		//Clear task
	}
