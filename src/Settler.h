#pragma once
class Settler {

public:
	Settler() : {}
	int get_x_position const;
	int get_y_position const;
	void setTask(const Task t);
	std::string getInventory;
	
private:
	int x_pos;
	int y_pos;
	Task currentTask;
	std::string inventory;
	
};