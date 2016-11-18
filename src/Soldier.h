#pragma once
class Soldier : public Settler {
	
public:	
	void defend();
	void attack(Building b);
	void attack(Settler s); 
	bool has_weapon() const;

private:
	bool armed; 
	
};