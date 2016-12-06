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
		list rl = b.needed_resources(); Check required resources
		list resource_list = rl.filter(_.amount > 0);
		while (resource_list.size() > 0 && building.completed() != false)
			list sl = map.building_list(Stockpile);
			list stockpile_list = //List of stockpiles with required resources
			Building stock = pathfinder.find_nearest(get_x_position(), get_y_position(), stockpile_list);
			move(stock.get_x_position, stock.get_y_position);
			//Select required resource r at random from stockpile
			stock.get_resource(r);
			move(b.get_x_position, b.get_y_position);
			b.add_resource(r);
		*/
	}
	void Settler::occupy(const Building b) {
		/*
		move(b.get_x_position, b.get_y_position);
		b.add_inhabitant(this);
		map.remove_settler(this);
		*/
	}
	void Settler::defend(const Building b) {
		/*
		if (has_weapon() == false) {
			gather(Weapon);
		}
		move(b.get_x_position, b.get_y_position);
		b.add_defender(this);
		map.remove_settler(this);
		*/
	}
	void Settler::gather(const Item i) {
		/*
		if (i == Weapon) {
			list wl = map.building_list(Weaponsmith);
			list l = wl.filter(_.weapons > 0);
			Building wsmith = pathfinder.find_nearest(get_x_position(), get_y_position(), l);
			move(wsmith.get_x_position, wsmith.get_y_position);
			wsmith.take_weapon();
	  }
		Else {
			while(get_task() == Gather) {
				list rl = map.resource_list(i);
				resource r = pathfinder.find_nearest(get_x_position(), get_y_position(), rl);
				move(r.get_x_position, r.get_y_position);
				r.mine();
				list sl = map.building_list(Stockpile);
				Building stock = pathfinder.find_nearest(get_x_position(), get_y_position(), sl);
				move(stock.get_x_position, stock.get_y_position);
				b.store(i);
			}
		}
		*/
	}
	void Settler::idle() {
		//current_task = Idle
	}

	void Settler::move(int x, int y) {
		/*
		route r = pathfinder.get_route(get_x_position, get_y_position(), x, y);
		While (get_x_position() != x && get_y_position != y) {
			Iterator::<Int, Int> nextPos = r.next();
			x_pos = std::get<0>(nextPos)
			y_pos = std::get<1>(nextPos)
		}
		*/
	}
	void Settler::draw();
