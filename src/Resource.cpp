#include "Resource.h"

Resource::Resource(int x, int y, Resource::RType t, unsigned int amount) {

	switch (t) {
	case Resource::RType::TREE:
		break;
	case Resource::RType::IRON:
		break;
	case Resource::RType::STONE:
		break;
	}
}

Resource::~Resource() {}

void take_resource() {
	switch (this->get_resource_type()) {
	case Resource::RType::TREE:
		break;
	case Resource::RType::IRON:
		break;
	case Resource::RType::STONE:
		break;
	}
}

