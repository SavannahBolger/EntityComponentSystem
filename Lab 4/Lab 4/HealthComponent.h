#pragma once
#include <iostream>
#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent() : health(100) {};
	int getHealth() { return health; }
	void setHealth(int health) { this->health = health; }
	void update() {};
private:
	int health;
};