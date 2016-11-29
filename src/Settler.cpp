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
	void Settler::build(const Building b) {
		/*
		Check required resources
		Get resource r from nearest warehouse
		Move to b
		b.add_resource(r);
		Repeat until resources run out or building is done
		*/
	}
	void Settler::occupy(const Building b) {
		/*
		Move settler to b
		b.add_inhabitant(this);
		map.remove_settler(this);
		*/
	}
	void Settler::defend(const Building b) {
		/*
		if (has_weapon() == false) {
			gather(Weapon)
		}
		Move settler to b
		b.add_defender(this);
		map.remove_settler(this);
		*/
	}
	void Settler::gather(const Item i) {
		/*
		if (i == Weapon) {
			go to nearest weaponsmith with weapons in stock
			weaponsmith.take_weapon();
	  }
		Else {
			go to nearest resource i
			resource.mine();
			go to nearest stockpile
			stockpile.store(i);
		}
		Repeat
		*/
	}
	void Settler::idle() {
		//Clear task
	}

	void Settler::move(int x, int y) {
		/*
		route r = pathfinder.get_route(get_x_position, get_y_position(), x, y);
		Iterator::<Int, Int> nextPos = r.next();
		x_pos = std::get<0>(nextPos)
		y_pos = std::get<1>(nextPos)
		*/
	}
	void Settler::draw();
