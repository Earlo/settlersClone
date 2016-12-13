#pragma once

#include "Task.h"
#include "../Building.h"

class Gather : public Task {
public:
	Gather( Building ret ){

	}
	std::vector<Building> targets;
	Building returnPoint;
private:

};
