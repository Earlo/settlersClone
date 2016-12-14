/*
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


/*
#include <iostream>
#include "Settler.h"
	/*
    void Settler::update(){
        switch (this->current_task) {
        case Settler::TType::GATHERW:
        	/*
            if (this->target.size() == 0){
                break;
            }
            else{
                this->gather();
            }
            break;
        case Settler::TType::GATHERS:
            break;
        case Settler::TType::GATHERI:
            break;
        }
    }
    */
	/*bool Settler::has_weapon() const {
		return armed;
	}
	Item Settler::get_inventory() const {
		return inventory;
	}
	void Settler::get_task() const{
		return current_task;
	}

	void Settler::set_task(const Settler::TType t) {
		current_task = t;
	}
	void Settler::build(const Building b) {
		int req_wood = b.get_required_wood();
		int req_stone = b.get_required_stone();
		int req_iron = b.get_required_iron();

		//TODO: Switch between resources at random
		while (req_wood > 0 && get_construction_status() == true) {
			list sl = game.get_stockpile_list();
			list stockpile_list = sl.filter(_.wood > 0)
			Building stock = pathfinder.find_nearest(get_x_position(), get_y_position(), stockpile_list);
			move(stock.get_x_position, stock.get_y_position);
			stock.take_wood();
			move(b.get_x_position, b.get_y_position);
			b.add_resource(Wood);
			req_wood = b.get_required_wood();
		}
		while (req_stone > 0 && get_construction_status() == true) {
			list sl = game.get_stockpile_list();
			list stockpile_list = sl.filter(_.stone > 0)
			Building stock = pathfinder.find_nearest(get_x_position(), get_y_position(), stockpile_list);
			move(stock.get_x_position, stock.get_y_position);
			stock.take_stone();
			move(b.get_x_position, b.get_y_position);
			b.add_resource(Stone);
			req_stone = b.get_required_stone();
		}
		while (req_iron > 0 && get_construction_status() == true) {
			list sl = game.get_stockpile_list();
			list stockpile_list = sl.filter(_.iron > 0)
			Building stock = pathfinder.find_nearest(get_x_position(), get_y_position(), stockpile_list);
			move(stock.get_x_position, stock.get_y_position);
			stock.take_iron();
			move(b.get_x_position, b.get_y_position);
			b.add_resource(Iron);
			req_iron = b.get_required_iron();
		}
	}
	void Settler::occupy(const Building b) {
		move(b.get_x_position, b.get_y_position);
		b.add_inhabitant(this);
		game.remove_settler(this);
	}
	void Settler::defend(const Building b) {
		if (has_weapon() == false) {
			gather(Weapon);
		}
		move(b.get_x_position, b.get_y_position);
		b.add_defender(this);
		game.remove_settler(this);
	}
	*/
	//void Settler::gather() {
		/*
		if (i == Weapon) {
			list wl = game.get_weaponsmiths();
			list l = wl.filter(_.weapons > 0);
			Building wsmith = pathfinder.find_nearest(get_x_position(), get_y_position(), l);
			move(wsmith.get_x_position, wsmith.get_y_position);
			wsmith.take_weapon();
	  }
		else {
			*/
			//while(get_task() == Gather) {
	//	std::cout<<"vittu"<<std::endl;
		/*Resource i = this->target[0];
		if (i == Tree) {
			list rl = game.get_trees();
		}
		else if (i == Stone) {
			list rl = game.get_stones();
		}
		else if (i == Iron) {
			list rl = game.get_irons();
		}
		std::cout<<"vittu"<<std::endl;
		/*Resource i = this->target[0];
		if (i == Tree) {
			list rl = game.get_trees();
		}
		else if (i == Stone) {
			list rl = game.get_stones();
		}
		else if (i == Iron) {
			list rl = game.get_irons();
		}
		else {
			throw "Unknown resource!";
		}*/
		/*resource r = pathfinder.find_nearest(get_x_position(), get_y_position(), rl);
		move(r.get_x_position, r.get_y_position);
		r.mine();
		list sl = game.stockpile_list();
		Building stock = pathfinder.find_nearest(get_x_position(), get_y_position(), sl);
		move(stock.get_x_position, stock.get_y_position);
		b.store(i);
			//}
		//}
		*/
	//}
	/*
	void Settler::idle() {
		current_task = Idle;
	}

	void Settler::move(int x, int y) {
		route r = pathfinder.get_route(get_x_position, get_y_position(), x, y);
		While (get_x_position() != x && get_y_position != y) {
			Iterator::<Int, Int> nextPos = r.next();
			x_pos = std::get<0>(nextPos);
			y_pos = std::get<1>(nextPos);
		}

	}
	void Settler::draw();
<<<<<<< HEAD
<<<<<<< 5fa578dc23149b9669ab3bd4aa3dc6f478431db8
*/
