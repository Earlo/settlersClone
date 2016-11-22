#pragma once
class Resource
{
public:
	
	enum class RType { TREE, STONE, IRON };
	
	Resource(int x, int y, Resource::RType t, unsigned int amount) : x_pos(x), y_pos(y), type(t), resource_amount(amount) { }
	~Resource(){}
	unsigned int get_resource_amount() { return resource_amount; }
	Resource::RType get_resource_type() { return type; }
	void take_resource();

private:
	Resource::RType type;
	int x_pos;
	int y_pos;
	unsigned int resource_amount;
};