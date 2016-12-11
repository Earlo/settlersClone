#pragma once

#include "Task.h"
#include "../Building.h"

class Gather : public Task {
public:
	std::vector<Building> Targets;
private:

};
