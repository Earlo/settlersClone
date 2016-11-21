#pragma once
#include "Soldier.h"
class Soldier : public Settler {
	
public:	
	void defend(Building b);
	void attack(Building b);
	void attack(Settler s); 
	bool has_weapon() const {
		return armed;
	}

};