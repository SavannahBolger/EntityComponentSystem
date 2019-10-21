#pragma once
#include <iostream>
#include "Entity.h"

class HealthSystem
{
	std::vector<Entity> entities;
public:
	HealthSystem() {};
	~HealthSystem() {};
	void addEntity(Entity e) { entities.push_back(e); }
	void update()
	{
		std::cout << "HealthSystem Update" << std::endl;
	}
};
